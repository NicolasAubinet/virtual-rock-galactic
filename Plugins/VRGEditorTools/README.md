# VRGEditorTools

Editor-only plugin that lets Claude read and edit Blueprint graphs in the **open** UE 4.27 editor, through Python remote execution. It is an `Editor` module, so it is never part of the `FSDGame` build or the pak.

## Pieces

- `Source/VRGEditorTools/`: `UVRGEditorToolsLibrary`, exposed to Python as `unreal.VRGEditorToolsLibrary`. Describe a Blueprint or graph, export (Ctrl+C text), import (Ctrl+V), add functions, parameters, variables and locals, remove functions, variables and locals, link or unlink pins, set pin defaults, remove or move nodes, compile, focus, format a graph with Blueprint Assist (`FormatGraph` = "Format All Events"; only for new graphs, it moves every linked node). Also outside graphs: `AddStructMember` (new member of a User Defined Struct, with a default), `DuplicateWidget` (designer copy-paste of a widget and its children, inserted right after it, with renames; widget variables stay variables) and `SetWidgetProperty` (a designer property from text, `Slot.X` for the slot). `CreatePoseAnimation` builds a one-frame AnimSequence (a fixed hand pose) from bone transforms, e.g. captured in game by the `VRGFistCapture` Lua mod (call it from `ue.py exec`, then save the asset with `unreal.EditorAssetLibrary.save_loaded_asset`). Types and conventions are documented in the header.
- `Scripts/ue.py`: command-line client (`py -3 ue.py --help`). It finds the running FSD editor, sends the job through a file in `FSD/Saved/VRGEditorTools/` and reads the result back from a file (the stock 4.27 client only reads 4 KB of reply).
- `Scripts/bp2pseudo.py`: turns `ue.py describe` output into compact pseudo-code (exec flow with inlined pure inputs, `goto [node]` at joins, `--ids` to keep node names). Much easier to read and diff than the raw describe output.
- Project setup: `PythonScriptPlugin` and `EditorScriptingUtilities` enabled in `FSD.uproject`, `bRemoteExecution=True` in `Config/DefaultEngine.ini`.

## Rules

- **`ue.py save` is the intended way to write to disk** (it compiles first and refuses a Blueprint with errors). But the user's editor has `SaveOnCompile=SoC_Always` (seen 2026-11-09), so `compile` saves the Blueprint too: only compile what is meant to be saved. `save` only handles Blueprints: save a struct with `unreal.EditorAssetLibrary.save_asset(path, False)` from `exec` (`save_loaded_asset` refuses struct objects), and save it before or with the Blueprints that use a new member. The user reviews the saved change with the editor's git diff. Each edit command is one undo step (Ctrl+Z).
- **Never edit through a commandlet** (`UE4Editor-Cmd -run=pythonscript`): on exit it saves every modified package silently. The module is `EditorNoCommandlet` (since 2026-11-11, for the Blueprint Assist dependency), so it isn't loaded in commandlets at all.
- After a paste, `describe` the new nodes: node names in the pasted text are kept when they don't collide, and links to nodes outside the pasted text are dropped (re-create them with `link`).
- Paste doesn't rebuild pins: the text must list every pin of each node (export a node of the same kind as a template). Nodes written this way for new native calls (`GetFSDGameUserSettings`, `StopAllCameraShakes`…) resolved and compiled fine on 2026-11-03.
- Linking a pin of an `Equal (Enum)` node resets its other pin's default (to the first enum value). Run `set` on enum defaults after the links, then `describe` to check.
- In `exec` scripts, never `+` two `unreal.Array` results (e.g. the two `get_dirty_*_packages()` lists): with an empty one it trips an engine assertion and crashes the editor (2026-11-09). Convert with `list()` first.
- Recompile the plugin after editing its C++: the editor must be closed, then run `Build.bat FSDEditor Win64 Development -Project=...` (see the VRG `CLAUDE.md`).

## Examples

```bash
py -3 ue.py describe-bp VRUIManager
py -3 ue.py describe VRUIManager FindMapZoomDistance
py -3 ue.py -o nodes.txt export VRUIManager FindMapZoomDistance K2Node_CallFunction_0
py -3 ue.py add-function VRUIManager MyFunc --in "Window:object:WindowWidget" --out "Ok:bool"
py -3 ue.py paste VRUIManager MyFunc nodes.txt
py -3 ue.py link VRUIManager MyFunc K2Node_FunctionEntry_0.then K2Node_IfThenElse_0.execute
py -3 ue.py compile VRUIManager
py -3 ue.py focus VRUIManager MyFunc
```

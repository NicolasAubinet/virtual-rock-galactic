# VRGEditorTools

Editor-only plugin that lets Claude read and edit Blueprint graphs in the **open** UE 4.27 editor, through Python remote execution. It is an `Editor` module, so it is never part of the `FSDGame` build or the pak.

## Pieces

- `Source/VRGEditorTools/`: `UVRGEditorToolsLibrary`, exposed to Python as `unreal.VRGEditorToolsLibrary`. Describe a Blueprint or graph, export (Ctrl+C text), import (Ctrl+V), add functions, variables and locals, link or unlink pins, set pin defaults, remove or move nodes, compile, focus. Types and conventions are documented in the header.
- `Scripts/ue.py`: command-line client (`py -3 ue.py --help`). It finds the running FSD editor, sends the job through a file in `FSD/Saved/VRGEditorTools/` and reads the result back from a file (the stock 4.27 client only reads 4 KB of reply).
- Project setup: `PythonScriptPlugin` and `EditorScriptingUtilities` enabled in `FSD.uproject`, `bRemoteExecution=True` in `Config/DefaultEngine.ini`.

## Rules

- **Only `ue.py save` writes to disk** (it compiles first and refuses a Blueprint with errors). The user reviews the saved change with the editor's git diff. Each edit command is one undo step (Ctrl+Z).
- **Never edit through a commandlet** (`UE4Editor-Cmd -run=pythonscript`): on exit it saves every modified package silently. The library refuses edits and compiles when `IsRunningCommandlet()`; read-only calls are fine there.
- After a paste, `describe` the new nodes: node names in the pasted text are kept when they don't collide, and links to nodes outside the pasted text are dropped (re-create them with `link`).
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

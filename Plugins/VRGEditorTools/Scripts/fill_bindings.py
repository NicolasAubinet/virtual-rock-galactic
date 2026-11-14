# Copies the SteamVR bindings (FSD/Config/SteamVRBindings: the manifest and every controller file it lists)
# into VRBindingsInstaller.Files, which the mod writes into the player's game folder at startup.
# Rerun after any change in FSD/Config/SteamVRBindings, then save the Blueprint:
#   py -3 FSD/Plugins/VRGEditorTools/Scripts/ue.py exec FSD/Plugins/VRGEditorTools/Scripts/fill_bindings.py
#   py -3 FSD/Plugins/VRGEditorTools/Scripts/ue.py save VRBindingsInstaller
# Contents are stored byte for byte (line endings included): the installer compares them as plain strings.
import json
import os
import unreal

BP = "/Game/VRG/Input/VRBindingsInstaller"
folder = os.path.join(unreal.Paths.convert_relative_path_to_full(unreal.Paths.project_config_dir()), "SteamVRBindings")


def load(name):
    with open(os.path.join(folder, name), "rb") as f:
        data = f.read()
    text = data.decode("ascii")  # WriteToPlainText saves ASCII unchanged; anything else would be re-encoded
    return text


manifest = load("steamvr_manifest.json")
names = ["steamvr_manifest.json"]
for b in json.loads(manifest)["default_bindings"]:
    if b["binding_url"] not in names:
        names.append(b["binding_url"])

files = {n: load(n) for n in names}
cls = unreal.load_object(None, BP + ".VRBindingsInstaller_C")
cdo = unreal.get_default_object(cls)
cdo.set_editor_property("Files", files)
unreal.load_asset(BP).modify()
print("Files: %d entries, %d chars" % (len(files), sum(len(v) for v in files.values())))

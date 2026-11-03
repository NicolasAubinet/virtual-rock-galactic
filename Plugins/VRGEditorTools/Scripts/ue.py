"""Drive the running UE 4.27 editor (FSD project) through Python remote execution.

Needs the editor open with the VRGEditorTools plugin and "Enable Remote Execution" on
(both set in the project). Nothing is ever saved: the user reviews and saves in the editor.
Each command is one undo step (Ctrl+Z in the editor).

Usage (BP = "VRUIManager" or "/Game/VRG/UI/VRUIManager"; PIN = Node.Pin):
  ue.py ping
  ue.py describe-bp BP
  ue.py describe BP GRAPH [NODE ...]
  ue.py export BP GRAPH [NODE ...]            same text as Ctrl+C
  ue.py paste BP GRAPH FILE [--keep]          same as Ctrl+V; --keep keeps the positions in FILE
  ue.py add-function BP NAME [--in N:type ...] [--out N:type ...] [--pure] [--category C]
  ue.py add-var BP NAME TYPE [--default V] [--category C]
  ue.py add-local BP FUNCTION NAME TYPE [--default V]
  ue.py link BP GRAPH PIN PIN
  ue.py unlink BP GRAPH PIN [PIN]             one PIN = break all its links
  ue.py set BP GRAPH PIN VALUE                pin default value
  ue.py remove BP GRAPH NODE [NODE ...]
  ue.py move BP GRAPH NODE X Y
  ue.py compile BP
  ue.py focus BP [GRAPH [NODE]]               open the Blueprint editor there
  ue.py exec FILE.py [--undo-name TEXT]       run a script in the editor (one undo step);
                                              `L` = unreal.VRGEditorToolsLibrary, print() is returned
Put -o FILE before the command to write the result to a file instead of stdout.
Types: see VRGEditorToolsLibrary.h.
"""
import argparse
import json
import os
import sys
import time
import uuid
from pathlib import Path

ENGINE_PY = Path(r"C:\EpicGames\UE_4.27\Engine\Plugins\Experimental\PythonScriptPlugin\Content\Python")
PROJECT_DIR = Path(__file__).resolve().parents[3]
EXCHANGE_DIR = PROJECT_DIR / "Saved" / "VRGEditorTools"
PROJECT_NAME = "FSD"

sys.path.insert(0, str(ENGINE_PY))
import remote_execution  # noqa: E402  (engine-provided client)
import types  # noqa: E402

# The 4.27 client calls json.loads(..., encoding=...), which Python 3.9+ rejects.
remote_execution._json = types.SimpleNamespace(
    dumps=json.dumps, loads=lambda s, **kw: json.loads(s, **{k: v for k, v in kw.items() if k != "encoding"}))


# Runs inside the editor. Reads its job from a file and writes the result to a file,
# because the stock client only reads 4 KB of reply.
REMOTE_TEMPLATE = r'''
import unreal, json, sys, io, traceback
_job = json.load(open(r"{job}", encoding="utf-8"))
_buf = io.StringIO()
_old = sys.stdout
sys.stdout = _buf
try:
    L = unreal.VRGEditorToolsLibrary
    with unreal.ScopedEditorTransaction(_job["undo"]):
        if _job["kind"] == "call":
            print(getattr(L, _job["fn"])(*_job["args"]), end="")
        else:
            exec(compile(_job["code"], _job["name"], "exec"), {{"unreal": unreal, "L": L, "__name__": "__vrg__"}})
except Exception:
    traceback.print_exc(file=_buf)
finally:
    sys.stdout = _old
    open(r"{out}", "w", encoding="utf-8", newline="").write(_buf.getvalue())
'''


def connect(timeout=6.0):
    rex = remote_execution.RemoteExecution()
    rex.start()
    deadline = time.time() + timeout
    node = None
    while time.time() < deadline:
        nodes = [n for n in rex.remote_nodes if n.get("project_name") == PROJECT_NAME] or rex.remote_nodes
        if nodes:
            node = nodes[0]
            break
        time.sleep(0.2)
    if not node:
        rex.stop()
        sys.exit("ERROR: no editor found. Is the FSD editor open, with Python remote execution enabled?")
    rex.open_command_connection(node["node_id"])
    return rex, node


def run_job(job):
    EXCHANGE_DIR.mkdir(parents=True, exist_ok=True)
    tag = uuid.uuid4().hex[:8]
    job_path = EXCHANGE_DIR / f"job_{tag}.json"
    out_path = EXCHANGE_DIR / f"out_{tag}.txt"
    job_path.write_text(json.dumps(job), encoding="utf-8")
    rex, _ = connect()
    try:
        try:
            res = rex.run_command(REMOTE_TEMPLATE.format(job=job_path, out=out_path), unattended=True)
            if not res.get("success") and not out_path.exists():
                return "ERROR: remote command failed: " + str(res.get("result"))
        except RuntimeError:
            pass  # reply over 4 KB (log noise); the result file is what matters
        for _ in range(50):
            if out_path.exists():
                break
            time.sleep(0.1)
        if not out_path.exists():
            return "ERROR: no result from the editor"
        return out_path.read_text(encoding="utf-8")
    finally:
        rex.stop()
        for p in (job_path, out_path):
            try:
                p.unlink()
            except OSError:
                pass


def call(fn, *args, undo=None):
    return run_job({"kind": "call", "fn": fn, "args": list(args), "undo": undo or f"VRG: {fn}"})


def pin(spec):
    node, sep, p = spec.partition(".")
    if not sep:
        sys.exit(f"ERROR: '{spec}' must be Node.Pin")
    return node, p


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("-o", "--output")
    sub = ap.add_subparsers(dest="cmd", required=True)
    sub.add_parser("ping")
    s = sub.add_parser("describe-bp"); s.add_argument("bp")
    for name in ("describe", "export"):
        s = sub.add_parser(name); s.add_argument("bp"); s.add_argument("graph"); s.add_argument("nodes", nargs="*")
    s = sub.add_parser("paste"); s.add_argument("bp"); s.add_argument("graph"); s.add_argument("file"); s.add_argument("--keep", action="store_true")
    s = sub.add_parser("add-function"); s.add_argument("bp"); s.add_argument("name")
    s.add_argument("--in", dest="inputs", action="append", default=[]); s.add_argument("--out", dest="outputs", action="append", default=[])
    s.add_argument("--pure", action="store_true"); s.add_argument("--category", default="")
    s = sub.add_parser("add-var"); s.add_argument("bp"); s.add_argument("name"); s.add_argument("type"); s.add_argument("--default", default=""); s.add_argument("--category", default="")
    s = sub.add_parser("add-local"); s.add_argument("bp"); s.add_argument("function"); s.add_argument("name"); s.add_argument("type"); s.add_argument("--default", default="")
    s = sub.add_parser("link"); s.add_argument("bp"); s.add_argument("graph"); s.add_argument("a"); s.add_argument("b")
    s = sub.add_parser("unlink"); s.add_argument("bp"); s.add_argument("graph"); s.add_argument("a"); s.add_argument("b", nargs="?")
    s = sub.add_parser("set"); s.add_argument("bp"); s.add_argument("graph"); s.add_argument("pin"); s.add_argument("value")
    s = sub.add_parser("remove"); s.add_argument("bp"); s.add_argument("graph"); s.add_argument("nodes", nargs="+")
    s = sub.add_parser("move"); s.add_argument("bp"); s.add_argument("graph"); s.add_argument("node"); s.add_argument("x", type=int); s.add_argument("y", type=int)
    s = sub.add_parser("compile"); s.add_argument("bp")
    s = sub.add_parser("focus"); s.add_argument("bp"); s.add_argument("graph", nargs="?", default=""); s.add_argument("node", nargs="?", default="")
    s = sub.add_parser("exec"); s.add_argument("file"); s.add_argument("--undo-name", default="VRG: script")
    a = ap.parse_args()

    c = a.cmd
    if c == "ping":
        rex, node = connect()
        rex.stop()
        out = "Connected: " + json.dumps(node)
    elif c == "describe-bp":
        out = call("describe_blueprint", a.bp)
    elif c == "describe":
        out = call("describe_graph", a.bp, a.graph, a.nodes)
    elif c == "export":
        out = call("export_nodes", a.bp, a.graph, a.nodes)
    elif c == "paste":
        out = call("import_nodes", a.bp, a.graph, Path(a.file).read_text(encoding="utf-8-sig"), a.keep, undo="VRG: paste nodes")
    elif c == "add-function":
        out = call("add_function", a.bp, a.name, a.inputs, a.outputs, a.pure, a.category)
    elif c == "add-var":
        out = call("add_member_variable", a.bp, a.name, a.type, a.default, a.category)
    elif c == "add-local":
        out = call("add_local_variable", a.bp, a.function, a.name, a.type, a.default)
    elif c == "link":
        out = call("link", a.bp, a.graph, *pin(a.a), *pin(a.b))
    elif c == "unlink":
        nb, pb = pin(a.b) if a.b else ("", "")
        out = call("unlink", a.bp, a.graph, *pin(a.a), nb, pb)
    elif c == "set":
        out = call("set_pin_default", a.bp, a.graph, *pin(a.pin), a.value)
    elif c == "remove":
        out = call("remove_nodes", a.bp, a.graph, a.nodes)
    elif c == "move":
        out = call("move_node", a.bp, a.graph, a.node, a.x, a.y)
    elif c == "compile":
        out = call("compile", a.bp)
    elif c == "focus":
        out = call("focus", a.bp, a.graph, a.node)
    elif c == "exec":
        code = Path(a.file).read_text(encoding="utf-8-sig")
        out = run_job({"kind": "exec", "code": code, "name": str(a.file), "undo": a.undo_name})

    if a.output:
        Path(a.output).write_text(out, encoding="utf-8", newline="")
        print(f"Wrote {len(out)} chars to {a.output}" + (" (ERROR)" if out.startswith("ERROR") else ""))
    else:
        sys.stdout.reconfigure(encoding="utf-8")
        print(out)
    if out.startswith("ERROR") or "Traceback (most recent call last)" in out:
        sys.exit(1)


if __name__ == "__main__":
    main()

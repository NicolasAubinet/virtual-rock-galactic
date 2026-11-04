"""Turn `ue.py describe` output into compact pseudo-code (exec flow + data inputs as expressions).

Usage: py -3 bp2pseudo.py DESCRIBE.txt [--ids]
  --ids  prefix each statement with its node name (to find it again for edits)

Exec nodes are printed in flow order from the function entry (and from any other exec node with no
incoming exec, e.g. events). Branching nodes print one indented block per exec output. A node reached a
second time prints "goto <node>". Pure nodes are inlined as expressions where they are used.
"""
import re
import sys

HDR = re.compile(r'^(\S+) "(.*?)" @\((-?\d+),(-?\d+)\)(?: // (.*))?$')
PIN = re.compile(r'^  ([<>]) (.+?)(?: "(.*?)")? \((.+?)\)(?: = (.*?))?(?: (<-|->) (.*))?$')


def parse(path):
    nodes, order = {}, []
    cur = None
    for line in open(path, encoding="utf-8"):
        line = line.rstrip("\n")
        m = HDR.match(line)
        if m:
            cur = {"name": m.group(1), "title": m.group(2), "comment": m.group(5), "ins": [], "outs": []}
            nodes[cur["name"]] = cur
            order.append(cur["name"])
            continue
        if cur is None:
            continue
        m = PIN.match(line)
        if not m:
            continue
        d, pin, friendly, typ, default, arrow, links = m.groups()
        links = [l.strip() for l in links.split(f" {arrow} ")] if links else []
        entry = {"pin": pin, "type": typ, "default": default, "links": links}
        (cur["ins"] if d == ">" else cur["outs"]).append(entry)
    return nodes, order


def short_title(t):
    t = t.split(" | ")[0]
    return t


def main():
    path = sys.argv[1]
    ids = "--ids" in sys.argv
    nodes, order = parse(path)

    def is_exec(p):
        return p["type"] == "exec"

    def has_exec(n):
        return any(is_exec(p) for p in n["ins"] + n["outs"])

    def expr(link, depth=0):
        node, _, pin = link.partition(".")
        n = nodes.get(node)
        if n is None:
            return link
        if n["title"] == "Reroute Node" and not has_exec(n):
            src = n["ins"][0]["links"] if n["ins"] else []
            return expr(src[0], depth) if src else "?"
        if has_exec(n) or depth > 6:
            return f"{node}.{pin}" if len([p for p in n['outs'] if not is_exec(p)]) > 1 or has_exec(n) else node
        t = short_title(n["title"])
        if t.startswith("Get ") and n["title"].find(" | ") < 0 and not [p for p in n["ins"] if p["pin"] != "self" and not is_exec(p)]:
            selfp = [p for p in n["ins"] if p["pin"] == "self" and p["links"]]
            return (expr(selfp[0]["links"][0], depth + 1) + "." if selfp else "") + t[4:]
        args = []
        for p in n["ins"]:
            if is_exec(p):
                continue
            if p["links"]:
                v = ",".join(expr(l, depth + 1) for l in p["links"])
            elif p["default"] is not None:
                v = p["default"]
            else:
                continue
            args.append(v if p["pin"] in ("self", "A", "B", "Object", "InString", "Value", "Target") else f"{p['pin']}={v}")
        outs = [p for p in n["outs"] if not is_exec(p)]
        suffix = f".{pin}" if len(outs) > 1 else ""
        return f"{t}({', '.join(args)}){suffix}"

    def stmt(n):
        t = short_title(n["title"])
        args = []
        for p in n["ins"]:
            if is_exec(p):
                continue
            if p["links"]:
                v = ",".join(expr(l) for l in p["links"])
            elif p["default"] not in (None, ""):
                v = p["default"]
            else:
                continue
            args.append(f"{p['pin']}={v}")
        out = f"{t}({', '.join(args)})"
        if n["comment"]:
            out += f"   // {n['comment']}"
        return (f"[{n['name']}] " if ids else "") + out

    seen = set()

    def through_knots(name):
        while name and nodes[name]["title"] == "Reroute Node":
            o = [p for p in nodes[name]["outs"] if is_exec(p) and p["links"]]
            name = o[0]["links"][0].partition(".")[0] if o else None
        return name

    def walk(name, ind):
        while name:
            name = through_knots(name)
            if not name:
                return
            n = nodes[name]
            pad = "  " * ind
            if name in seen:
                print(f"{pad}goto [{name}] {short_title(n['title'])}")
                return
            seen.add(name)
            print(pad + stmt(n))
            eo = [p for p in n["outs"] if is_exec(p)]
            linked = [p for p in eo if p["links"]]
            if len(eo) == 1:
                name = eo[0]["links"][0].partition(".")[0] if eo[0]["links"] else None
                continue
            for p in eo:
                if not p["links"]:
                    continue
                print(f"{pad}  [{p['pin']}]")
                for l in p["links"]:
                    walk(l.partition(".")[0], ind + 2)
            return

    starts = [n for n in order if any(is_exec(p) for p in nodes[n]["outs"])
              and not any(is_exec(p) and p["links"] for p in nodes[n]["ins"])]
    for s in starts:
        if s in seen:
            continue
        print(f"=== from {s}")
        walk(s, 0)
    left = [n for n in order if has_exec(nodes[n]) and n not in seen]
    if left:
        print("=== unreached exec nodes:", ", ".join(left))


main()

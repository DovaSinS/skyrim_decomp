"""Build private sibling hints with p127's parser and exact qualified-name coverage join.

Run with --source <private clone> --inventory <private functions.jsonl>.
Public data/progress.json supplements the private census, deduplicated by (build id, RVA).
The output defaults to .local/sources/fo4-private-index. No source bodies are published.
Later non-name pairs may be appended using --anchors <private JSON list>, with each row
containing build_id, rva, qualified (the sibling name), reason and evidence (p130's handoff).
These are explicitly anchor pairs, never exact-name pairs or match evidence.
"""
import argparse
from collections import defaultdict
import hashlib
import json
from pathlib import Path
import re
import subprocess

import check_origin
from fo4_private import GAME_DIRS, INDEX, REVISION, SOURCE, allowed_path
from local_paths import local_dir
import sibling_cpp

ROOT = Path(__file__).resolve().parents[1]


def source_bodies(source):
    source = Path(source)
    head = subprocess.check_output(['git', '-C', str(source), 'rev-parse', 'HEAD'], text=True).strip()
    if head != REVISION:
        raise ValueError('fo4-private source revision differs from the approved pin')
    paths = subprocess.check_output(['git', '-C', str(source), 'ls-tree', '-r', '--name-only',
                                     REVISION, '--', *GAME_DIRS], text=True).splitlines()
    index = defaultdict(list)
    for rel in paths:
        if not allowed_path(rel) or Path(rel).suffix not in check_origin.SUFFIXES:
            continue
        # Read the pinned Git blob, never a modified working file or a symlink destination.
        raw = subprocess.check_output(['git', '-C', str(source), 'show', f'{REVISION}:{rel}']).decode('utf-8', 'replace')
        for fn in sibling_cpp.functions(check_origin.clean(raw)):
            qualified = fn['qualified']
            if re.match(r'^(?:Ni|hk|hkp|hknp|hkb|hcl|Scaleform|std\b)', qualified):
                continue
            index[qualified].append({'path': rel, 'line': fn['line'], 'head': fn['head'],
                                     'params': fn['params'], 'body': raw[fn['start']+1:fn['end']]})
    return dict(index)


def join(bodies, private, public, build_id, anchors=()):
    if any(f.get('build_id', build_id) != build_id for f in (*private, *public)):
        raise ValueError('fo4-private inventory belongs to a different Skyrim build')
    public = {f['rva']: f for f in public}
    inventory = {(build_id, f['rva']): f for f in private}
    for rva, fn in public.items():
        inventory.setdefault((build_id, rva), fn)
    rows = []
    for (build, rva), fn in sorted(inventory.items()):
        names = {n['name'] for n in fn.get('names', []) if n.get('how') != 'placeholder'}
        if rva in public:
            names.add(public[rva]['name'])
        for name in sorted(names & bodies.keys()):
            rows.append(dict(build_id=build, rva=rva, qualified=name,
                             match='exact-qualified-name', sources=bodies[name]))
    for anchor in anchors:
        rva = anchor['rva']
        rva = int(rva, 0) if isinstance(rva, str) else rva
        if ((anchor['build_id'], rva) not in inventory or anchor['qualified'] not in bodies
                or not anchor.get('reason') or not anchor.get('evidence')):
            raise ValueError('fo4-private anchor needs a known target/source pair, reason and evidence')
        rows.append(dict(anchor, rva=rva, match='anchor', sources=bodies[anchor['qualified']]))
    return rows


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--source', type=Path, default=local_dir(ROOT) / 'sources/fo4-private')
    p.add_argument('--inventory', type=Path, required=True)
    p.add_argument('--out', type=Path, default=local_dir(ROOT) / INDEX)
    p.add_argument('--anchors', type=Path, action='append', default=[])
    args = p.parse_args()
    # A body index must stay under ignored storage, including for explicit output paths.
    if not args.out.resolve().is_relative_to(local_dir(ROOT).resolve()):
        p.error('output must stay under the private local directory')
    bodies = source_bodies(args.source)
    private = [json.loads(line) for line in args.inventory.read_text().splitlines() if line]
    public = json.loads((ROOT / 'data/progress.json').read_text())['functions']
    build_id = json.loads((ROOT / 'builds/target.json').read_text())['build_id']
    anchors = [row for path in args.anchors for row in json.loads(path.read_text())]
    rows = join(bodies, private, public, build_id, anchors)
    args.out.mkdir(parents=True, exist_ok=True)
    (args.out / 'hints.jsonl').write_text(''.join(json.dumps(row) + '\n' for row in rows))
    meta = dict(source=SOURCE, revision=REVISION, parser='tools/sibling_cpp.py',
                inventory_sha256=hashlib.sha256(args.inventory.read_bytes()).hexdigest(),
                public_sha256=hashlib.sha256((ROOT / 'data/progress.json').read_bytes()).hexdigest(),
                qualified_names=len(bodies), body_occurrences=sum(map(len, bodies.values())),
                pairs=len(rows), functions=len({(r['build_id'], r['rva']) for r in rows}),
                anchor_files=[str(p) for p in args.anchors])
    (args.out / 'meta.json').write_text(json.dumps(meta, indent=2) + '\n')
    print(f'fo4-private: {meta["functions"]} inventory functions, {len(rows)} pairs; private index written')


if __name__ == '__main__':
    main()

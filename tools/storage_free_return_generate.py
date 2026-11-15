"""Extract a selected storage-free population from the pinned local image.

Complete decoding is an enrollment check, never match evidence. The unchanged
verifier independently compiles and compares every generated member.
"""
import argparse
import hashlib
import json
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[1]
sys.path[:0] = [str(ROOT/'tools'), str(ROOT/'tools/verifier')]
from pecoff import PeImage
import bind
import symbol_map
import storage_free_return_template_v1 as template


def extract(code):
    if len(code) == 3 and code[-1] == 195:
        if code[:2] == bytes((51, 192)):
            return 'zero-word', 0
        if code[:2] == bytes((50, 192)):
            return 'zero-byte', 0
        if code[0] == 176:
            return 'constant-byte', code[1]
    identities = {(72, 139, 193, 195): 'this-pointer',
                  (72, 139, 194, 195): 'argument-pointer',
                  (65, 139, 192, 195): 'second-argument-word'}
    if tuple(code) in identities:
        return identities[tuple(code)], 0
    raise ValueError('unsupported complete return shape')


def generate(selection, out, template=template, extract=extract, task_prefix='p139-return', method='Invoke'):
    root = ROOT
    if not out.resolve().is_relative_to(root/'.local'):
        raise ValueError('outputs must remain private')
    image_data = Path(json.loads((root/'.local/verifier/config.json').read_text())['image']).read_bytes()
    target = json.loads((root/'builds/target.json').read_text())
    if hashlib.sha256(image_data).hexdigest() != target['image_sha256']:
        raise ValueError('pinned image mismatch')
    if selection['build_id'] != template.BUILD:
        raise ValueError('selection build mismatch')
    members = selection['members']
    if len({m['rva'] for m in members}) != len(members):
        raise ValueError('duplicate selection')
    image = PeImage(image_data)
    extracted = [(m, *extract(image.read(m['rva'], m['size'], 'return member')[1])) for m in members]
    progress = json.loads((root/'data/progress.json').read_text())
    existing = {f['rva']: f for f in progress['functions']}
    for m, _, _ in extracted:
        prior = existing.get(m['rva'])
        if prior and (prior['status'] == 'matched' or prior['size'] != m['size']):
            raise ValueError('matched or inconsistent prior entry')
    tasks, rows = [], []
    for m, result, value in extracted:
        rva, size = m['rva'], m['size']
        emitted = template.emit(rva, size, result, value)
        source = f'reconstruction/leaves/{emitted["cls"]}.cpp'
        for rel, content in [(source, emitted['source']), (source[:-4]+'.h', emitted['header'])]:
            p = root/rel
            p.parent.mkdir(parents=True, exist_ok=True)
            if p.exists() and (p.is_symlink() or p.read_text() != content):
                raise ValueError('refusing different existing source')
            p.write_text(content)
        smap = dict(schema=1, build_id=template.BUILD,
                    symbols={emitted['symbol']: dict(rva=rva, size=size)}, folds=[],
                    _provenance=dict(entries=[dict(name=emitted['symbol'], rva=hex(rva),
                        community_name=None, note='Explicit pinned-image entry; signature and name are stand-ins.')]))
        digest = hashlib.sha256(symbol_map.serialize(smap)).hexdigest()
        map_path = f'reports/{template.BUILD}/unit-symbols/{digest}.json'
        symbol_map.create(root, map_path, smap)
        params = dict(rva=rva, size=size, result=result, value=value)
        td = out/'tasks'/f'{task_prefix}-{rva:x}'
        td.mkdir(parents=True, exist_ok=True)
        task = dict(task_schema=1, task_id=td.name, build_id=template.BUILD,
                    compiled=source, recipe=template.RECIPE, symbols=map_path,
                    functions=[dict(rva=rva, size=size, symbol=emitted['symbol'], family_metadata=dict(
                        origin=template.origin(), family_parameters=params, name_source='GUESS(low)'))])
        (td/'task.json').write_text(json.dumps(task, indent=2)+'\n')
        tasks.append(str(td.resolve())); rows.append(params)
        if rva not in existing:
            progress['functions'].append(dict(id=f'{template.BUILD}-0x{rva:x}', build_id=template.BUILD,
                rva=rva, size=size, status='mapped', name=f'{emitted["cls"]}::{method}', name_origin='GUESS',
                name_source='GUESS(low): storage-free ABI stand-in; original signature and owner unknown.',
                owner='awarebayes', evidence=template.EVIDENCE))
    (root/'data/progress.json').write_text(json.dumps(progress, indent=2)+'\n')
    bind.preflight(tasks, root)
    (out/'all.txt').write_text(''.join(t+'\n' for t in tasks))
    (out/'parameter-rows.json').write_text(json.dumps(rows, indent=2)+'\n')
    print(f'extracted {len(tasks)} members; complete binding preflight passed', flush=True)


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--selection', type=Path, required=True)
    p.add_argument('--out', type=Path, required=True)
    a = p.parse_args()
    generate(json.loads(a.selection.read_text()), a.out)

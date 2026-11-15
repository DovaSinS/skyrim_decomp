"""Generate explicitly catalogued field leaves; never invent a storage layout.

Selection supplies private output path, committed population and pinned catalogue.
Complete decoded member extents and represented header hashes are checked before
source writes. Generation does not confirm, approve or accept any function.
"""
import argparse
from concurrent.futures import ThreadPoolExecutor
import hashlib
import json
from pathlib import Path
import re
import sys

ROOT = Path(__file__).resolve().parents[1]
sys.path[:0] = [str(ROOT/'tools'), str(ROOT/'tools/verifier'), str(ROOT/'tools/ghidra')]
import bind
import disasm
import symbol_map
from deleting_layout_bindings_v1 import Image as BindingImage
import represented_field_template_v2 as template


def extract(rows, size):
    if not rows or rows[0][0] != 0 or sum(len(r[1].split()) for r in rows) != size:
        raise ValueError('incomplete member extent')
    cursor = 0
    for row in rows:
        if row[0] != cursor:
            raise ValueError('noncontiguous instruction extent')
        cursor += len(row[1].split())
    instructions = [r[2] for r in rows]
    if len(rows) == 2 and instructions[-1] == 'ret':
        match = re.fullmatch(r'(mov rax, qword ptr|lea rax,) \[rcx \+ (0x[0-9a-f]+)\]', instructions[0])
        if match:
            return ('pointer' if match[1].startswith('mov') else 'address', int(match[2], 16))
    if len(rows) == 3 and instructions[1:] == ['setne al', 'ret']:
        match = re.fullmatch(r'cmp qword ptr \[rcx \+ (0x[0-9a-f]+)\], 0x0', instructions[0])
        if match:
            return 'present', int(match[1], 16)
    raise ValueError('unsupported complete field leaf shape')


def write_new(path, text):
    path.parent.mkdir(parents=True, exist_ok=True)
    if path.exists() and (path.is_symlink() or path.read_text() != text):
        raise ValueError('refusing to overwrite another source')
    path.write_text(text)


def validate_owner(image, row):
    owner = image.table(row['owner_table'])
    if (owner['offset'] != 0 or owner['type_raw'] != row['owner-rtti']
            or image.number(row['owner_table'] + 8*row['owner_slot'], 'Q') - image.base != row['rva']):
        raise ValueError('independent primary RTTI owner/slot binding mismatch')


def prepare(selection):
    root = ROOT
    out = Path(selection['out']).resolve()
    if not out.is_relative_to(root/'.local'):
        raise ValueError('private output required')
    population = json.loads((root/selection['population']).read_text())
    catalog_path = root/selection['catalog']
    raw = catalog_path.read_bytes()
    if hashlib.sha256(raw).hexdigest() != selection['catalog_sha256']:
        raise ValueError('catalogue pin mismatch')
    catalog = json.loads(raw)
    members = catalog['members']
    allowed = {(r['rva'], r['size']) for r in population['members']}
    if len({r['rva'] for r in members}) != len(members) or any((r['rva'],r['size']) not in allowed for r in members):
        raise ValueError('catalogue duplicates or member outside population')
    target = json.loads((root/'builds/target.json').read_text())
    if catalog['build_id'] != template.BUILD or population['build_id'] != template.BUILD or target['build_id'] != template.BUILD:
        raise ValueError('build identity mismatch')
    config = json.loads((root/'.local/verifier/config.json').read_text())
    image = Path(config['image'])
    if hashlib.sha256(image.read_bytes()).hexdigest() != target['image_sha256'] or catalog['image_sha256'] != target['image_sha256']:
        raise ValueError('image pin mismatch')
    for name, digest in catalog['headers'].items():
        if hashlib.sha256((root/name).read_bytes()).hexdigest() != digest:
            raise ValueError('represented header changed')
    objdump = disasm.find_objdump(config.get('objdump'))
    if not objdump:
        raise ValueError('objdump unavailable')
    binding_image = BindingImage(image)
    progress = json.loads((root/'data/progress.json').read_text())
    existing = {r['rva']:r for r in progress['functions']}
    def check(row):
        if row['header'] not in catalog['headers']:
            raise ValueError('unbound represented header')
        validate_owner(binding_image, row)
        prior = existing.get(row['rva'])
        if prior and (prior['status'] == 'matched' or prior['size'] != row['size']):
            raise ValueError('accepted or conflicting inventory member')
        extracted = extract(disasm.target_rows(objdump, str(image), row['rva'], row['size']), row['size'])
        if extracted != (row['operation'], row['offset']):
            raise ValueError('independent complete shape disagrees with field binding')
        return row, template.emit(row)
    with ThreadPoolExecutor(max_workers=6) as pool:
        checked = list(pool.map(check, members))
    tasks, parameters = [], []
    for row, emitted in checked:
        source = f'reconstruction/fields/{emitted["cls"]}.cpp'
        write_new(root/source, emitted['source'])
        write_new((root/source).with_suffix('.h'), emitted['header'])
        symbol = emitted['symbol']
        smap = dict(schema=1,build_id=template.BUILD,symbols={symbol:dict(rva=row['rva'],size=row['size'])},folds=[],
                    _provenance=dict(entries=[dict(name=symbol,rva=hex(row['rva']),community_name=None,
                        note='Explicit member RVA and represented field binding; source-container name is a guess.')]))
        digest = hashlib.sha256(symbol_map.serialize(smap)).hexdigest()
        map_path = f'reports/{template.BUILD}/unit-symbols/{digest}.json'
        symbol_map.create(root,map_path,smap)
        params = {'entry-rva':row['rva'],'size':row['size'],'operation':row['operation'],'offset':row['offset'],
                  'layout':row['type'],'field':row['field'],'layout-header':row['header'],
                  'layout-sha256':catalog['headers'][row['header']],
                  'owner':row['owner'],'owner-rtti':row['owner-rtti'],'owner-table':row['owner_table'],'owner-slot':row['owner_slot']}
        taskdir = out/'tasks'/f'p143-{row["rva"]:x}'
        taskdir.mkdir(parents=True,exist_ok=True)
        task = dict(task_schema=1,task_id=taskdir.name,build_id=template.BUILD,compiled=source,recipe=template.RECIPE,
                    symbols=map_path,functions=[dict(rva=row['rva'],size=row['size'],symbol=symbol,
                    family_metadata=dict(origin=template.origin(),family_parameters=params,name_source='GUESS(low)'))])
        (taskdir/'task.json').write_text(json.dumps(task,indent=2)+'\n')
        tasks.append(str(taskdir));parameters.append(params)
        if row['rva'] not in existing:
            progress['functions'].append(dict(id=f'{template.BUILD}-0x{row["rva"]:x}',build_id=template.BUILD,
                rva=row['rva'],size=row['size'],status='mapped',name=f'{emitted["cls"]}::Read',name_origin='GUESS',
                name_source='GUESS(low): represented field source container; original signature and ownership unverified.',
                owner='awarebayes',evidence=template.EVIDENCE))
    (root/'data/progress.json').write_text(json.dumps(progress,indent=2)+'\n')
    bind.preflight(tasks,root)
    (out/'all.txt').write_text(''.join(t+'\n' for t in tasks))
    (out/'parameter-rows.json').write_text(json.dumps(parameters,indent=2)+'\n')
    print(f'prepared {len(tasks)} field leaves; complete extraction and binding preflight passed',flush=True)


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--selection',type=Path,required=True)
    prepare(json.loads(p.parse_args().selection.read_text()))

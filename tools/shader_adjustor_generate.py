"""Extract and reconcile member-local shader destructor adjustors.

Private selection metadata proposes identities only. LLVM decodes each complete
member, and image-relative MSVC RTTI independently binds owner, direct base,
secondary offset and both destructor slots. No target byte signatures are stored.
"""
import argparse
from concurrent.futures import ThreadPoolExecutor
import hashlib
import json
from pathlib import Path
import re
import struct
import sys

ROOT = Path(__file__).resolve().parents[1]
sys.path[:0] = [str(ROOT/'tools/verifier'), str(ROOT/'tools/ghidra')]
import bind
import disasm
from export_pack import ImageFacts
import symbol_map
import shader_adjustor_template_v1 as template


def hierarchy(image, table):
    col = struct.unpack('<Q', image.read(table-8, 8))[0] - image.pe.image_base
    signature, offset, cd, td, chd, self_rva = struct.unpack('<IIIIII', image.read(col, 24))
    if signature != 1 or col != self_rva or cd:
        raise ValueError('unsupported RTTI locator')
    count, array = struct.unpack('<II', image.read(chd+8, 8))
    if not 1 <= count <= 4096:
        raise ValueError('invalid hierarchy count')
    bases = []
    for index in range(count):
        bcd = struct.unpack('<I', image.read(array+4*index, 4))[0]
        btd, contained, mdisp, pdisp, vdisp, attrs = struct.unpack('<IIiiiI', image.read(bcd, 24))
        bases.append(dict(type=image._cstr(btd+16), contained=contained, offset=mdisp,
                          parent=pdisp, virtual=vdisp))
    return dict(type=image._cstr(td+16), offset=offset, bases=bases)


def direct(bases):
    result, index = [], 1
    while index < len(bases):
        result.append(bases[index])
        index += bases[index]['contained']+1
    return result


def decode(rows, rva, size, image_base):
    position, adjustment, target = 0, 0, None
    for offset, encoding, text, *rest in rows:
        if offset != position:
            raise ValueError('decoded extent gap')
        position += len(encoding.split())
        arithmetic = re.fullmatch(r'(add|sub) rcx, (-?0x[0-9a-f]+|-?[0-9]+)', text)
        transfer = re.fullmatch(r'jmp (0x[0-9a-f]+)(?: <[^>]*>)?', text)
        if arithmetic and target is None:
            value = int(arithmetic[2], 0)
            adjustment += value if arithmetic[1] == 'add' else -value
        elif transfer and target is None and position == size:
            target = int(transfer[1], 16)-image_base
        else:
            raise ValueError('outside complete this-only arithmetic/direct transfer')
    if position != size or adjustment != -16 or target is None or target < 0:
        raise ValueError('unsupported adjustment or extent')
    return target


def reconcile(image, member, callee):
    primary = hierarchy(image, member['primary_table'])
    secondary = hierarchy(image, member['secondary_table'])
    base = hierarchy(image, member['base_table'])
    slot = lambda table: struct.unpack('<Q', image.read(table, 8))[0]-image.pe.image_base
    if primary['type'] != member['rtti_type'] or secondary['type'] != primary['type'] or primary['offset']:
        raise ValueError('owner RTTI differs')
    expected_type = '.?AV'+member['base']+'@@'
    parents = direct(primary['bases'])
    if len(parents) != 1 or (parents[0]['type'], parents[0]['offset'], parents[0]['parent']) != (expected_type, 0, -1):
        raise ValueError('owner direct inheritance differs')
    if base['type'] != expected_type or base['offset']:
        raise ValueError('base RTTI differs')
    if [(b['type'], b['offset'], b['parent']) for b in primary['bases'][2:]] != [(b['type'], b['offset'], b['parent']) for b in base['bases'][1:]]:
        raise ValueError('inherited base graph differs')
    graph = {b['type']: (b['offset'], b['parent']) for b in base['bases'][1:]}
    for name, offset in [('NiRefObject',0), ('NiBoneMatrixSetterI',16), ('BSReloadShaderI',24)]:
        if graph.get('.?AV'+name+'@@') != (offset,-1):
            raise ValueError('represented shader interface graph differs')
    if secondary['offset'] != 16 or slot(member['secondary_table']) != member['rva'] or slot(member['primary_table']) != callee:
        raise ValueError('destructor or secondary offset binding differs')
    return dict(member['owner'] and {'entry-rva': member['rva'], 'size': member['size'],
                'owner': member['owner'], 'base': member['base'], 'this-offset': 16,
                'callee-rva': callee, 'primary-table-rva': member['primary_table'],
                'secondary-table-rva': member['secondary_table'], 'base-table-rva': member['base_table'], 'slot': 0})


def generate(selection, out):
    if not out.resolve().is_relative_to(ROOT/'.local') or selection['build_id'] != template.BUILD:
        raise ValueError('private output and pinned build required')
    config = json.loads((ROOT/'.local/verifier/config.json').read_text())
    image = ImageFacts(config['image'])
    if image.sha256 != json.loads((ROOT/'builds/target.json').read_text())['image_sha256']:
        raise ValueError('image hash differs')
    objdump = disasm.find_objdump(config.get('objdump'))
    members = selection['members']
    if len({m['rva'] for m in members}) != len(members) or len({m['owner'] for m in members}) != len(members):
        raise ValueError('duplicate member or owner unit')
    def one(member):
        rows = disasm.target_rows(objdump, config['image'], member['rva'], member['size'])
        return member, reconcile(image, member, decode(rows, member['rva'], member['size'], image.pe.image_base))
    with ThreadPoolExecutor(max_workers=6) as pool:
        decoded = list(pool.map(one, members))
    progress = json.loads((ROOT/'data/progress.json').read_text())
    existing = {f['rva']: f for f in progress['functions']}
    tasks, parameters = [], []
    for member, row in decoded:
        rva = member['rva']
        prior = existing.get(rva)
        if prior and (prior['status'] == 'matched' or prior['size'] != member['size']):
            raise ValueError('accepted or inconsistent inventory member')
        emitted = template.emit(member['owner'], member['base'], [row])
        source = f'reconstruction/shaders/{emitted["cls"]}.cpp'
        for rel, content in [(source, emitted['source']), (source[:-4]+'.h', emitted['header'])]:
            path = ROOT/rel
            path.parent.mkdir(parents=True, exist_ok=True)
            if path.exists() and (path.is_symlink() or path.read_text() != content):
                raise ValueError('refusing changed existing source')
            path.write_text(content)
        entries = {emitted['symbol']:dict(rva=rva,size=member['size']), emitted['callee']:dict(rva=row['callee-rva'],size=None)}
        smap = dict(schema=1,build_id=template.BUILD,symbols=entries,folds=[],_provenance=dict(entries=[dict(name=n,rva=hex(v['rva']),community_name=None,note='Member-local decoded tailcall reconciled with owning RTTI destructor slots.') for n,v in entries.items()]))
        digest = hashlib.sha256(symbol_map.serialize(smap)).hexdigest()
        map_path = f'reports/{template.BUILD}/unit-symbols/{digest}.json'
        symbol_map.create(ROOT,map_path,smap)
        td = out/'tasks'/f'p155-thunk-{rva:x}'
        td.mkdir(parents=True,exist_ok=True)
        task = dict(task_schema=1,task_id=td.name,build_id=template.BUILD,compiled=source,recipe=template.RECIPE,symbols=map_path,functions=[dict(rva=rva,size=member['size'],symbol=emitted['symbol'],family_metadata=dict(origin=template.origin(),family_parameters=row,name_source='GUESS(low)'))])
        (td/'task.json').write_text(json.dumps(task,indent=2)+'\n')
        tasks.append(str(td.resolve()));parameters.append(row)
        if not prior:
            progress['functions'].append(dict(id=f'{template.BUILD}-0x{rva:x}',build_id=template.BUILD,rva=rva,size=member['size'],status='mapped',name=f'{emitted["cls"]} secondary destructor adjustor',name_origin='GUESS',name_source='GUESS(low): direct RTTI owner over represented shader interfaces; only compiler-emitted adjustor compared.',owner='awarebayes',evidence=template.EVIDENCE))
    (ROOT/'data/progress.json').write_text(json.dumps(progress,indent=2)+'\n')
    bind.preflight(tasks,ROOT)
    (out/'all.txt').write_text(''.join(t+'\n' for t in tasks))
    (out/'parameter-rows.json').write_text(json.dumps(parameters,indent=2)+'\n')
    print(f'extracted and reconciled {len(tasks)} shader destructor adjustors',flush=True)


if __name__ == '__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--selection',type=Path,required=True)
    parser.add_argument('--out',type=Path,required=True)
    args=parser.parse_args()
    generate(json.loads(args.selection.read_text()),args.out)

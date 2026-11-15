"""Emit compiler wrappers using unchanged represented headers and per-target bindings.

The catalog pins the previously published layout and independently observed primary
RTTI owner. Every complete wrapper is decoded anew; a second operand reader checks
the calls, allocation size and branch. No destructor implementation is supplied.
"""
import argparse
from concurrent.futures import ThreadPoolExecutor
import hashlib
import json
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[1]
sys.path[:0] = [str(ROOT / 'tools'), str(ROOT / 'tools/verifier')]
import bind
import disasm
import symbol_map
from deleting_layout_bindings_v1 import Image
from deleting_wrapper_generate import extract

BUILD = 'sse-steam-1-7-104'
RECIPE = 'reconstruction/recipes/represented-magic-wrapper-o2.json'
CATALOG = 'tools/represented_wrapper_catalog_v4.json'
CATALOG_SHA256 = 'b0c74fb82088adc49e31e7eb9a286c1b27c9068e9f7b35cc0e051524eae109b4'
DEPENDENCIES = {
    'tools/deleting_wrapper_generate.py': 'b273146a31620027767c6c4ab2b94b3259693f11264e14304e410a50e5976883',
    'tools/deleting_layout_bindings_v1.py': 'dde9d76f7f575b87a00294f5bf106ea15ee410cff6852e99771f9cc62a818eee',
}


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def origin():
    return dict(family='represented-deleting-wrapper', version='4',
                template_digest=sha(__file__))


def audit(image, member, params):
    """Read operands and primary-owner metadata independently of disassembly."""
    rva = member['rva']
    table = image.table(member['owner_table'])
    if (table['type_raw'] != member['owner_rtti'] or table['offset'] != 0
            or member['owner_slot'] != 0
            or image.number(member['owner_table'], 'Q') != image.base + rva):
        raise ValueError('primary owner binding disagrees')
    actual = {'entry-rva': rva, 'size': 52,
              'destructor-rva': rva + 20 + image.number(rva + 16, 'i'),
              'deallocator-rva': rva + 38 + image.number(rva + 34, 'i'),
              'object-size': image.number(rva + 26)}
    if (actual != params or rva + 25 + image.number(rva + 24, 'b') != rva + 38
            or actual['object-size'] != member['object_size']
            or actual['destructor-rva'] != member['destructor']
            or actual['deallocator-rva'] != member['deallocator']):
        raise ValueError('independent operand binding disagrees')


def source(member):
    name = Path(member['header']).stem
    return f'''// Build: {BUILD}; RVA 0x{member['rva']:x}; 52 bytes
// Evidence: findings/ghidra-import.md
// Recipe: {RECIPE}
// Source exposure: mixed (represented community declarations and local binary analysis).
// Drafted by tools/represented_wrapper_v4.py (GPT-6.1 Sol).
// Labels: v2
// object: GUESS(low)
// Code origin: original wrapper emission harness; represented declarations are included.
// No members or bases are added to the published represented header.
// Its type is a represented layout stand-in, not the recovered original specialization.
// The external complete destructor is bound independently for each target wrapper.
// A static object requests ordinary compiler emission of the scalar deleting destructor.
// Initialization, complete destruction and other methods are not compared or implemented.
// Only the wrapper's bytes are claimed; a pass proves no name or full layout identity.
// Origin: {json.dumps(origin(), sort_keys=True)}
void operator delete(void*, unsigned __int64) noexcept;
#include "{name}.h"
static_assert(sizeof({member['type']}) == {member['object_size']}, "represented allocation size");
static {member['type']} object;
'''


def prepare(out, limit=None):
    out = Path(out).resolve()
    if '.local' not in out.parts:
        raise ValueError('private outputs required')
    if sha(ROOT / CATALOG) != CATALOG_SHA256:
        raise ValueError('catalog changed')
    for path, digest in DEPENDENCIES.items():
        if sha(ROOT / path) != digest:
            raise ValueError('extraction dependency changed: ' + path)
    catalog = json.loads((ROOT / CATALOG).read_text())
    for header, digest in catalog['headers'].items():
        if sha(ROOT / header) != digest:
            raise ValueError('represented header changed: ' + header)
    cfg = json.loads((ROOT / '.local/verifier/config.json').read_text())
    image = Image(cfg['image'])
    if image.sha256 != catalog['image_sha256'] or image.sha256 != json.loads((ROOT / 'builds/target.json').read_text())['image_sha256']:
        raise ValueError('target image changed')
    objdump = disasm.find_objdump(cfg.get('objdump'))
    entries = catalog['members'][:limit] if limit else catalog['members']
    def decode(member):
        params = extract(disasm.target_rows(objdump, cfg['image'], member['rva'], 52), member['rva'], image.base)
        audit(image, member, params)
        params['layout-index'] = list(catalog['headers']).index(member['header'])
        params['owner-table'] = member['owner_table']
        return member, params
    with ThreadPoolExecutor(max_workers=6) as pool:
        decoded = list(pool.map(decode, entries))
    progress = json.loads((ROOT / 'data/progress.json').read_text())
    existing = {f['rva']: f for f in progress['functions']}
    tasks = []
    emitted = set()
    out.mkdir(parents=True, exist_ok=True)
    for member, params in decoded:
        rva = member['rva']
        if existing.get(rva, {}).get('status') == 'matched':
            raise ValueError('member already accepted')
        compiled = str(Path(member['header']).with_suffix('.cpp'))
        if compiled not in emitted:
            path = ROOT / compiled
            content = source(member)
            if path.exists() and path.read_text() != content:
                raise ValueError('existing source differs: ' + compiled)
            path.write_text(content)
            emitted.add(compiled)
        cls = member['type'].split('::')[-1]
        suffix = cls + '@ResearchLayouts@@'
        symbol = '??_G' + suffix + 'UEAAPEAXI@Z'
        destructor = '??1' + suffix + 'UEAA@XZ'
        symbols = {symbol: dict(rva=rva, size=52),
                   destructor: dict(rva=member['destructor'], size=None),
                   '??3@YAXPEAX_K@Z': dict(rva=member['deallocator'], size=None)}
        smap = dict(schema=1, build_id=BUILD, symbols=symbols, folds=[],
                    _provenance=dict(entries=[dict(name=n, rva=hex(v['rva']), community_name=None,
                        note='Complete wrapper extraction and independent operand/primary RTTI audit; represented type is a stand-in.')
                        for n, v in symbols.items()]))
        digest = hashlib.sha256(symbol_map.serialize(smap)).hexdigest()
        map_path = f'reports/{BUILD}/unit-symbols/{digest}.json'
        symbol_map.create(ROOT, map_path, smap)
        taskdir = out / 'tasks' / f'p137-{rva:x}'
        taskdir.mkdir(parents=True, exist_ok=True)
        task = dict(task_schema=1, task_id=taskdir.name, build_id=BUILD, compiled=compiled,
                    recipe=RECIPE, symbols=map_path, functions=[dict(rva=rva, size=52, symbol=symbol,
                    family_metadata=dict(origin=origin(), family_parameters=params, name_source='GUESS(medium)'))])
        (taskdir / 'task.json').write_text(json.dumps(task, indent=2) + '\n')
        tasks.append(str(taskdir))
        if rva not in existing:
            progress['functions'].append(dict(id=f'{BUILD}-0x{rva:x}', build_id=BUILD, rva=rva,
                size=52, status='mapped', name=f'{cls}::~{cls}', name_origin='GUESS',
                name_source='GUESS(medium): represented layout alias; original specialization not recovered.',
                owner='awarebayes', evidence='findings/ghidra-import.md'))
    temporary = out / 'progress.tmp'
    temporary.write_text(json.dumps(progress, indent=2) + '\n')
    temporary.replace(ROOT / 'data/progress.json')
    bind.preflight(tasks, ROOT)
    (out / 'all.txt').write_text(''.join(t + '\n' for t in tasks))
    (out / 'first20.txt').write_text(''.join(t + '\n' for t in tasks[:20]))
    (out / 'rows.json').write_text(json.dumps([p for m, p in decoded], indent=2) + '\n')
    print(f'prepared {len(tasks)} independently bound wrappers using {len(emitted)} unchanged represented headers', flush=True)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--limit', type=int)
    args = parser.parse_args()
    prepare(args.out, args.limit)

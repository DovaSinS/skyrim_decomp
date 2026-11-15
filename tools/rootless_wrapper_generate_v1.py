"""Private rootless wrapper revision; no padding, test, verifier or gate changes."""
from pathlib import Path
import hashlib
import json
import sys

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import symbol_map
from deleting_layout_bindings_v1 import Image

BUILD = 'sse-steam-1-7-104'
RECIPE = 'reconstruction/recipes/represented-magic-wrapper-o2.json'


def origin():
    return dict(family='represented-rootless-deleting-wrapper', version='1',
        template_digest=hashlib.sha256(Path(__file__).read_bytes()).hexdigest())


def prepare():
    cat = json.loads((ROOT / 'tools/rootless_wrapper_catalog_v1.json').read_text())
    for rel, digest in cat['headers'].items():
        assert hashlib.sha256((ROOT / rel).read_bytes()).hexdigest() == digest
    image = Image(json.loads((ROOT / '.local/verifier/config.json').read_text())['image'])
    assert image.sha256 == cat['image_sha256']
    recipe = json.loads((ROOT / RECIPE).read_text())
    assert not any(flag.startswith(('/I', '-I')) for flag in recipe['flags'])
    progress = json.loads((ROOT / 'data/progress.json').read_text())
    existing = {f['rva']: f for f in progress['functions']}
    source = 'reconstruction/actors/CombatInventoryItemMagicLayout.cpp'
    first = cat['members'][0]
    (ROOT / source).write_text(f'''// Build: {BUILD}; RVA 0x{first['rva']:x}; 52 bytes
// Evidence: findings/ghidra-import.md
// Recipe: {RECIPE}
// Source exposure: mixed (represented community declarations and independent target bindings).
// Drafted by tools/rootless_wrapper_generate_v1.py (GPT-6.1 Sol).
// Labels: v2
// object: GUESS(low)
// Original represented fields, bases and external complete destructor are unchanged.
// Header includes are relative; this recipe needs no repository include root.
// Only the compiler-emitted deleting wrapper is compared, not original specialization or behavior.
// Origin: {json.dumps(origin(), sort_keys=True)}
void operator delete(void*, unsigned __int64) noexcept;
#include "CombatInventoryItemMagicLayout.h"
static ResearchLayouts::CombatInventoryItemMagicLayout object;
''')
    out = ROOT / '.local/generation'
    names = []
    for member in cat['members']:
        rva = member['rva']
        table = image.table(member['owner_table'])
        assert table['type_raw'] == member['owner_rtti'] and table['offset'] == 0
        assert member['owner_slot'] == 0 and image.number(member['owner_table'], 'Q') == image.base + rva
        params = {'entry-rva': rva, 'size': 52, 'object-size': image.number(rva+26),
            'destructor-rva': rva+20+image.number(rva+16, 'i'),
            'deallocator-rva': rva+38+image.number(rva+34, 'i'), 'owner-table': member['owner_table']}
        assert params['object-size'] == member['object_size']
        assert params['destructor-rva'] == member['destructor'] and params['deallocator-rva'] == member['deallocator']
        assert rva+25+image.number(rva+24, 'b') == rva+38
        assert existing.get(rva, {}).get('status') != 'matched'
        suffix = 'CombatInventoryItemMagicLayout@ResearchLayouts@@'
        symbol = '??_G'+suffix+'UEAAPEAXI@Z'
        entries = {symbol: dict(rva=rva,size=52), '??1'+suffix+'UEAA@XZ':dict(rva=member['destructor'],size=None),
            '??3@YAXPEAX_K@Z':dict(rva=member['deallocator'],size=None)}
        smap = dict(schema=1,build_id=BUILD,symbols=entries,folds=[],_provenance=dict(entries=[
            dict(name=n,rva=hex(v['rva']),community_name=None,note='Independent wrapper operands and primary RTTI binding; represented specialization is a stand-in.')
            for n,v in entries.items()]))
        digest=hashlib.sha256(symbol_map.serialize(smap)).hexdigest();mp=f'reports/{BUILD}/unit-symbols/{digest}.json'
        symbol_map.create(ROOT,mp,smap);name=f'p171-rootless-{rva:x}';td=out/name;td.mkdir(parents=True,exist_ok=True)
        task=dict(task_schema=1,task_id=name,build_id=BUILD,compiled=source,recipe=RECIPE,symbols=mp,functions=[
            dict(rva=rva,size=52,symbol=symbol,family_metadata=dict(origin=origin(),family_parameters=params,name_source='GUESS(medium)'))])
        (td/'task.json').write_text(json.dumps(task,indent=2)+'\n');names.append(name)
        if rva not in existing:
            progress['functions'].append(dict(id=f'{BUILD}-0x{rva:x}',build_id=BUILD,rva=rva,size=52,status='mapped',
                name='CombatInventoryItemMagicLayout::~CombatInventoryItemMagicLayout',name_origin='GUESS',
                name_source='GUESS(medium): represented declaration; original specialization unverified.',owner='awarebayes',evidence='findings/ghidra-import.md'))
    (ROOT/'data/progress.json').write_text(json.dumps(progress,indent=2)+'\n')
    (out/'task-names.json').write_text(json.dumps(names,indent=2)+'\n')
    print('Prepared',len(names),'rootless members with independent primary RTTI/call bindings; no acceptance.')


if __name__ == '__main__':
    prepare()

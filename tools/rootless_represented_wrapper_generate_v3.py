"""Deleting wrappers from complete represented declarations with relative includes.

Support declarations retain their contents and notices. Only include spellings and
the represented wrapper class identifier change; no layout storage is introduced.
"""
from pathlib import Path
import hashlib
import json
import os
import re
import sys

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import symbol_map
from deleting_layout_bindings_v1 import Image

CATALOG = 'tools/rootless_represented_wrapper_catalog_v1.json'
BUILD = 'sse-steam-1-7-104'
RECIPE = 'reconstruction/recipes/represented-magic-wrapper-o2.json'
SUPPORT = Path('reconstruction/f004support')
INCLUDE = re.compile(r'^(\s*#\s*include\s*)"([^"\n]+)"', re.MULTILINE)


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def origin():
    return dict(family='rootless-represented-renamed-deleting-wrapper', version='3',
                template_digest=sha(__file__))


def support_path(original):
    relative = Path(original).relative_to('reconstruction')
    return SUPPORT / relative.name


def relative_includes(text, original, destination, headers):
    def replace(match):
        candidates = [Path(original).parent / match[2], Path('reconstruction') / match[2]]
        resolved = [p.resolve().relative_to(ROOT.resolve()).as_posix()
                    for p in (ROOT / q for q in candidates) if p.is_file()]
        assert resolved, 'quoted include not available: ' + original + ': ' + match[2]
        target = resolved[0]
        assert target in headers, 'dependency outside pinned declaration closure: ' + target
        relative = os.path.relpath(support_path(target), Path(destination).parent).replace('\\', '/')
        return match[1] + '"' + relative + '"'
    return INCLUDE.sub(replace, text)


def prepare():
    catalog = json.loads((ROOT / CATALOG).read_text())
    headers = catalog['headers']
    for rel, digest in headers.items():
        assert sha(ROOT / rel) == digest, 'represented declaration changed: ' + rel
    recipe = json.loads((ROOT / RECIPE).read_text())
    assert not any(flag.startswith(('/I', '-I')) for flag in recipe['flags'])
    image = Image(json.loads((ROOT / '.local/verifier/config.json').read_text())['image'])
    assert image.sha256 == catalog['image_sha256']
    progress = json.loads((ROOT / 'data/progress.json').read_text())
    existing = {fn['rva']: fn for fn in progress['functions']}
    for original in headers:
        dest = support_path(original)
        text = (f'// Origin: copied represented declaration from {original}; only include spellings changed.\n'
                + relative_includes((ROOT / original).read_text(), original, dest, headers))
        path = ROOT / dest
        path.parent.mkdir(parents=True, exist_ok=True)
        assert not path.exists() or path.read_text() == text, 'different support declaration'
        path.write_text(text, newline='\n')
    out = ROOT / '.local/generation'
    tasks = []
    for member in catalog['members']:
        rva = member['rva']
        assert existing.get(rva, {}).get('status') != 'matched'
        table = image.table(member['owner_table'])
        assert table['type_raw'] == member['owner_rtti'] and table['offset'] == 0
        assert image.number(member['owner_table'], 'Q') == image.base + rva
        params = {'entry-rva': rva, 'size': 52, 'object-size': image.number(rva + 26),
                  'destructor-rva': rva + 20 + image.number(rva + 16, 'i'),
                  'deallocator-rva': rva + 38 + image.number(rva + 34, 'i'),
                  'owner-table': member['owner_table'], 'layout-index': member['layout_index']}
        assert params['object-size'] == member['object_size']
        assert params['destructor-rva'] == member['destructor']
        assert params['deallocator-rva'] == member['deallocator']
        assert rva + 25 + image.number(rva + 24, 'b') == rva + 38
        cls = f'F004Represented{rva:x}'
        original = Path(member['header']).stem
        header = f'reconstruction/wrappers/{cls}.h'
        source = f'reconstruction/wrappers/{cls}.cpp'
        text = (ROOT / member['header']).read_text()
        assert re.search(r'\bclass\s+' + re.escape(original) + r'\b', text)
        text = re.sub(r'\b' + re.escape(original) + r'\b', cls, text)
        text = relative_includes(text, member['header'], header, headers)
        prefix = f'''// Build: {BUILD}; RVA 0x{rva:x}; 52 bytes
// Evidence: findings/ghidra-import.md
// Recipe: {RECIPE}
// Source exposure: mixed (represented community declaration and independent target bindings).
// Drafted by tools/rootless_represented_wrapper_generate_v3.py (GPT-6.1 Sol).
// Labels: v2
// {cls}, object: GUESS(low) STANDIN
// Declaration source: {member['header']} (renamed complete represented declaration).
// Fields and bases are unchanged; relative includes use copied declarations with original notices.
// Complete destructor remains external; only the compiler-emitted deleting wrapper is compared.
// Original ownership, specialization and complete destructor implementation are not claimed.
// Origin: {json.dumps(origin(), sort_keys=True)}
'''
        for rel, content in [(header, prefix + text), (source, prefix +
                'void operator delete(void*, unsigned __int64) noexcept;\n' +
                f'#include "{cls}.h"\nstatic ResearchLayouts::{cls} object;\n')]:
            path = ROOT / rel
            path.parent.mkdir(parents=True, exist_ok=True)
            assert not path.exists() or path.read_text() == content, 'different existing source'
            path.write_text(content, newline='\n')
        suffix = cls + '@ResearchLayouts@@'
        symbol = '??_G' + suffix + 'UEAAPEAXI@Z'
        entries = {symbol: dict(rva=rva, size=52),
                   '??1' + suffix + 'UEAA@XZ': dict(rva=member['destructor'], size=None),
                   '??3@YAXPEAX_K@Z': dict(rva=member['deallocator'], size=None)}
        smap = dict(schema=1, build_id=BUILD, symbols=entries, folds=[], _provenance=dict(entries=[
            dict(name=name, rva=hex(v['rva']), community_name=None,
                 note='Independent call operands and primary RTTI binding; complete represented stand-in.')
            for name, v in entries.items()]))
        digest = hashlib.sha256(symbol_map.serialize(smap)).hexdigest()
        mp = f'reports/{BUILD}/unit-symbols/{digest}.json'
        symbol_map.create(ROOT, mp, smap)
        td = out / f'p171-rootless33-{rva:x}'
        td.mkdir(parents=True, exist_ok=True)
        task = dict(task_schema=1, task_id=td.name, build_id=BUILD, compiled=source, recipe=RECIPE,
                    symbols=mp, functions=[dict(rva=rva, size=52, symbol=symbol,
                    family_metadata=dict(origin=origin(), family_parameters=params, name_source='GUESS(low)'))])
        (td / 'task.json').write_text(json.dumps(task, indent=2) + '\n', newline='\n')
        tasks.append(td.name)
        if rva not in existing:
            progress['functions'].append(dict(id=f'{BUILD}-0x{rva:x}', build_id=BUILD, rva=rva, size=52,
                status='mapped', name=f'{cls}::~{cls}', name_origin='GUESS',
                name_source='GUESS(low): renamed represented declaration; original specialization unverified.',
                owner='awarebayes', evidence='findings/ghidra-import.md'))
    (ROOT / 'data/progress.json').write_text(json.dumps(progress, indent=2) + '\n', newline='\n')
    (out / 'task-names.json').write_text(json.dumps(tasks, indent=2) + '\n', newline='\n')
    print('Prepared', len(tasks), 'rootless complete represented wrapper candidates; no acceptance.', flush=True)


if __name__ == '__main__':
    prepare()

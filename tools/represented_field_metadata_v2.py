"""Version family metadata without changing a compiled source or comparator report.

SHA-256 layout pins are eight numeric words in family parameters. The complete
digest remains pinned in the original catalogue and TU include closure. This
representation obeys the existing parameter-enumeration hygiene checks.
"""
import copy
import hashlib
import json
from pathlib import Path
import represented_field_family_metadata_v2 as template


SOURCE_PINS = {1: {'catalog': 'tools/represented_field_catalog_v1.json', 'catalog_sha256': '4145c604131b3144626d5f03594f2032beefca21845424a4e0404166786bfa28', 'generator': 'tools/represented_field_generate.py', 'generator_sha256': '159715681b81ab4164a643e51ab358cfa1e344e866c08dab4d694db1035f9573'}, 2: {'catalog': 'tools/represented_field_catalog_v2.json', 'catalog_sha256': '7c2b6a85130dd44e2ed359f1b511c996abefc3ba0874392ffffa5edf098d8189', 'generator': 'tools/represented_field_generate_v2.py', 'generator_sha256': 'a5e90650c2b231306e8d21d24f2d3db8aeac4e56cd18c5bed9345679a7d58412'}}


def parameters(original, version):
    result = dict(original)
    digest = result.pop('layout-sha256')
    if len(digest) != 64 or any(c not in '0123456789abcdef' for c in digest):
        raise ValueError('invalid original layout digest')
    result['source-version'] = version
    for i in range(8):
        result[f'layout-sha256-word{i}'] = int(digest[8*i:8*i+8], 16)
    return result


def convert(task, root):
    task = copy.deepcopy(task)
    for fn in task['functions']:
        old = fn['family_metadata']
        version = int(old['origin']['version'])
        emitter = template.emitter(version)
        if old['origin'] != emitter.origin():
            raise ValueError('original metadata/template origin differs')
        pins = SOURCE_PINS[version]
        for key in ('catalog','generator'):
            if hashlib.sha256((Path(root)/pins[key]).read_bytes()).hexdigest() != pins[key+'_sha256']:
                raise ValueError('original catalogue/extractor pin changed')
        catalog = json.loads((Path(root)/pins['catalog']).read_text())
        matches = [r for r in catalog['members'] if r['rva']==fn['rva'] and r['size']==fn['size']]
        if len(matches)!=1:
            raise ValueError('original catalogue identity missing or ambiguous')
        row = matches[0]
        emitted = emitter.emit(row)
        source = f'reconstruction/fields/{emitted["cls"]}.cpp'
        if (task['compiled']!=source or fn['symbol']!=emitted['symbol']
                or (Path(root)/source).read_text()!=emitted['source']
                or (Path(root)/source).with_suffix('.h').read_text()!=emitted['header']):
            raise ValueError('source differs from pinned original emitter')
        p = old['family_parameters']
        expected={'entry-rva':row['rva'],'size':row['size'],'operation':row['operation'],
                  'offset':row['offset'],'layout':row['type'],'field':row['field'],
                  'layout-header':row['header'],'layout-sha256':catalog['headers'][row['header']]}
        if version==2:
            expected.update(owner=row['owner'],**{'owner-rtti':row['owner-rtti'],
                             'owner-table':row['owner_table'],'owner-slot':row['owner_slot']})
        if p!=expected:
            raise ValueError('task parameters differ from pinned original catalogue')
        actual = hashlib.sha256((Path(root)/p['layout-header']).read_bytes()).hexdigest()
        if actual != p['layout-sha256']:
            raise ValueError('layout digest differs from original parameter')
        fn['family_metadata'] = dict(origin=template.origin(version),
                                    family_parameters=parameters(p, version),
                                    name_source=old['name_source'])
    task['task_id'] = 'p143m-' + format(task['functions'][0]['rva'], 'x')
    return task

"""Pin the complete version-1 virtual-tail extraction and binding implementation.

Family version 2 changes the metadata contract only. The C++ Origin comments
retain their truthful version-1 emission provenance; source and comparator
evidence are unchanged. Reconfirmation exports the new origin in new records.
"""
import argparse
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
PINS = {
    'virtual_tail_generate.py': 'f20cd88f1f06d14e47826b95be34dfef71847b9d4fb6d87ad7b0c1dd8a2f2060',
    'storage_free_return_generate.py': '7207dc9fc1c491ce5635227bb2b5dba66ed2331cc1fa14ac00922732e30375fd',
    'virtual_tail_template_v1.py': '76841bc2394c686c2fb12143f9071955a7009219a971e806d99423041de0f57b',
}


def check_pins():
    for name, digest in PINS.items():
        if hashlib.sha256((ROOT / 'tools' / name).read_bytes()).hexdigest() != digest:
            raise ValueError('virtual-tail extraction dependency differs from family pin')


def export(task_dirs):
    # Check before importing the implementations whose identities this contract binds.
    check_pins()
    import virtual_tail_template_v1 as template
    import storage_free_return_generate as generator
    for directory in map(Path, task_dirs):
        directory = directory.resolve()
        if not directory.is_relative_to(ROOT / '.local'):
            raise ValueError('task metadata must stay private')
        path = directory / 'task.json'
        task = json.loads(path.read_text())
        if task['build_id'] != template.BUILD or len(task['functions']) != 1:
            raise ValueError('unexpected member identity')
        fn = task['functions'][0]
        metadata = fn['family_metadata']
        params = metadata['family_parameters']
        if params['rva'] != fn['rva'] or params['size'] != fn['size']:
            raise ValueError('parameter identity differs')
        emitted = template.emit(fn['rva'], fn['size'], params['result'], params['value'])
        source = ROOT / task['compiled']
        if (task['compiled'] != f'reconstruction/leaves/{emitted["cls"]}.cpp'
                or source.read_text() != emitted['source']
                or source.with_suffix('.h').read_text() != emitted['header']
                or fn['symbol'] != emitted['symbol'] or task['recipe'] != template.RECIPE):
            raise ValueError('member differs from pinned source emission')
        origin = dict(template.origin(), version='2',
                      template_digest=hashlib.sha256(Path(__file__).read_bytes()).hexdigest())
        if metadata['origin'] not in (template.origin(), origin):
            raise ValueError('unexpected prior origin')
        metadata['origin'] = origin
        path.write_text(json.dumps(task, indent=2) + '\n')
    generator.bind.preflight(task_dirs, ROOT)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--list', type=Path, required=True)
    args = parser.parse_args()
    export([line for line in args.list.read_text().splitlines() if line.strip()])

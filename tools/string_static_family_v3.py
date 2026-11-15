"""Version 3 family metadata export for unchanged version 2 string sources.

The C++ Origin comment records the original v2 source emission. Family version 3
versions only the metadata contract: the string-dependency hash stays in private
audit rows, outside the public family parameter vocabulary. Existing source,
recipe and symbol-map digests are preserved; comparator evidence is never edited.
The pinned v2 generator performs all extraction and source generation.
"""
import argparse
import hashlib
import json
from pathlib import Path

import string_static_generate_v2 as generator
import string_static_template_v2 as template

ROOT = Path(__file__).resolve().parents[1]
GENERATOR_SHA256 = 'a8ce00e874eae9b2fb951bcd09c711d014a3a1ccd82f24ac31951d3a2eebede4'
TEMPLATE_SHA256 = '2732643f2c7f1350c7a54dd846e66879d1f14e70ac52519e4868f9c485a9224f'
VERSION = '3'


def check_pins():
    for path, digest in ((Path(generator.__file__), GENERATOR_SHA256),
                         (Path(template.__file__), TEMPLATE_SHA256)):
        if hashlib.sha256(path.read_bytes()).hexdigest() != digest:
            raise ValueError('source generator or template differs from v3 family pin')


def parameters(private_row):
    """Keep the dependency hash in its private audit file, not in member ranges."""
    if not isinstance(private_row.get('string-sha256'), str) or len(private_row['string-sha256']) != 64:
        raise ValueError('private dependency audit hash missing')
    return {key: value for key, value in private_row.items() if key != 'string-sha256'}


def export(task_dirs):
    check_pins()
    for directory in map(Path, task_dirs):
        directory = directory.resolve()
        if not directory.is_relative_to(ROOT / '.local'):
            raise ValueError('task metadata must remain in this checkout .local')
        path = directory / 'task.json'
        task = json.loads(path.read_text())
        if task['build_id'] != template.BUILD or len(task['functions']) != 1:
            raise ValueError('unexpected task identity')
        fn = task['functions'][0]
        cls, header, cpp, source_origin = template.emit(fn['rva'], fn['size'])
        compiled = f'reconstruction/static/{cls}.cpp'
        if task['compiled'] != compiled or (ROOT / compiled).read_text() != cpp or (ROOT / compiled).with_suffix('.h').read_text() != header:
            raise ValueError('source differs from pinned v2 emission')
        rows = json.loads((directory.parent.parent / 'rows.json').read_text())
        row = next((r for r in rows if r['entry-rva'] == fn['rva']), None)
        if row is None:
            raise ValueError('private extracted member row missing')
        metadata = fn['family_metadata']
        family_origin = dict(source_origin, version=VERSION)
        expected = row if metadata['origin'] == source_origin else parameters(row)
        if metadata['origin'] not in (source_origin, family_origin) or metadata['family_parameters'] != expected:
            raise ValueError('metadata differs from retained extraction')
        metadata.update(origin=family_origin, family_parameters=parameters(row))
        temporary = path.with_suffix('.export.tmp')
        temporary.write_text(json.dumps(task, indent=2) + '\n')
        temporary.replace(path)
    generator.bind.preflight(task_dirs, ROOT)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--list', type=Path, required=True)
    args = parser.parse_args()
    export([line for line in args.list.read_text().splitlines() if line.strip()])

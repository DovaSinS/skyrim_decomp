"""Anonymous, game-only sibling hints. Source bodies and the identity mapping stay private."""
import json
from pathlib import Path, PurePosixPath

from local_paths import local_dir

SOURCE = 'fo4-private'
REVISION = '1b765c7031394e5019767dff83e73e8b194f16b0'
LABEL = 'SIBLING(fo4-private@1b765c70, author-permission)'
INDEX = 'sources/fo4-private-index'
# p127's screened game-code folders; never recurse through the whole src tree.
GAME_DIRS = tuple('src/' + name for name in (
    'BSAnimation', 'BSAudio', 'BSCompanion', 'BSCore', 'BSDevices', 'BSDiag',
    'BSHavok', 'BSHavokMigration', 'BSMain', 'BSMenu', 'BSMovie', 'BSMusic',
    'BSPathfinding', 'BSResource', 'BSScript', 'BSShader', 'BSSystem',
    'BSSystemMonitor', 'BSSystemUtilities', 'Game', 'Shared'))
CAUTION = ('Different game, VS2012 build; names can hide overload/signature differences. '
           'Layouts, vtable slots, offsets and form IDs may differ: no transfer without '
           'Skyrim proof. Never match evidence; two-host comparison, review and integration remain required.')


def allowed_path(name):
    path = PurePosixPath(name)
    return (not path.is_absolute() and '..' not in path.parts and '\\' not in name
            and len(path.parts) >= 3 and '/'.join(path.parts[:2]) in GAME_DIRS)


def read_hints(directory):
    directory = Path(directory)
    meta = json.loads((directory / 'meta.json').read_text())
    if meta.get('source') != SOURCE or meta.get('revision') != REVISION:
        raise ValueError('fo4-private index has an unapproved source or revision')
    rows = [json.loads(line) for line in (directory / 'hints.jsonl').read_text().splitlines() if line]
    for row in rows:
        if not row.get('sources') or any(not allowed_path(s['path']) for s in row['sources']):
            raise ValueError('fo4-private index contains an excluded source path')
    return rows


def hint_section(root, build_id, rva):
    directory = local_dir(root) / INDEX
    if not directory.is_dir():
        return ''
    rows = [row for row in read_hints(directory) if row['build_id'] == build_id and row['rva'] == rva]
    if not rows:
        return ''
    out = ['## Sibling hint (fo4-private; private)', '', CAUTION, '', f'Label: `{LABEL}`.']
    for row in rows:
        out += ['', f'Pair: `{row["qualified"]}` ({row["match"]}; overloads unresolved).']
        for source in row['sources']:
            out += [f'Sibling source: fo4-private@1b765c70 {source["path"]}:{source["line"]}',
                    '```cpp', source['head'].strip() + '\n{' + source['body'] + '}', '```']
    return '\n'.join(out)

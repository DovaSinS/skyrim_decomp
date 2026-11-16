"""Bind existing public shader owner units to their ImageSpaceEffect adjustors.

This stamp never writes reconstruction source. Existing owner files must exactly match
public shader template v1, originally emitted for the independently bound offset-16
member. This separate family covers only their offset-144, size-12 destructor members.
"""
import hashlib
from pathlib import Path
import re
import adjustor_thunk_template_v3 as adjustor
import shader_adjustor_template_v1 as prior

BUILD = 'sse-steam-1-7-104'
RECIPE = 'reconstruction/recipes/msvc-19.16.27054-o2.json'

def origin():
    return dict(family='imagespace-effect-destructor-adjustor', version='1',
                template_digest=hashlib.sha256(Path(__file__).read_bytes()).hexdigest())

def bind_source(root, owner):
    if not re.fullmatch(r'[A-Za-z_]\w*', owner):
        raise ValueError('unsupported owner identifier')
    cls = owner + 'ThunkLayout'
    source = f'reconstruction/shaders/{cls}.cpp'
    header = f'reconstruction/shaders/{cls}.h'
    text = (root / source).read_text(encoding='utf8')
    matches = re.findall(r'^// RVA 0x([0-9a-f]+); 9 bytes$', text, re.M)
    if len(matches) != 1:
        raise ValueError('existing shader unit must identify exactly one original member')
    old = prior.emit(owner, 'BSImagespaceShader', [dict(**{'entry-rva': int(matches[0], 16), 'this-offset': 16, 'size': 9, 'slot': 0})])
    if text != old['source'] or (root / header).read_text(encoding='utf8') != old['header']:
        raise ValueError('existing unit differs from pinned original shader template')
    emitted = adjustor.emit(1, 12, 144, cls, 0x1a8)
    return dict(layout=cls, compiled=source, header=header,
                source_sha256=hashlib.sha256((root/source).read_bytes()).hexdigest(),
                header_sha256=hashlib.sha256((root/header).read_bytes()).hexdigest(),
                symbol=emitted['symbol'], callee_symbol=emitted['callee'])

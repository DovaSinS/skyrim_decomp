"""Storage-free virtual-dispatch stand-ins with a single declared first slot."""
import hashlib
import json
from pathlib import Path

BUILD = 'sse-steam-1-7-104'
RECIPE = 'reconstruction/recipes/msvc-19.16.27054-o2.json'
EVIDENCE = 'findings/ghidra-import.md'


def origin():
    return dict(family='nullable-virtual-tail', version='1',
                template_digest=hashlib.sha256(Path(__file__).read_bytes()).hexdigest())


def emit(rva, size, result, value):
    if (type(rva) is not int or rva <= 0
            or (result, size, value) not in [('argument-dispatch', 23, 1), ('object-dispatch', 14, 0)]):
        raise ValueError('unsupported virtual dispatch parameters')
    cls = f'VirtualTail{rva:x}'
    prefix = f'''// Build: {BUILD}; RVA 0x{rva:x}; {size} bytes
// Evidence: {EVIDENCE}
// Recipe: {RECIPE}
// Source exposure: binary-analysis; no external implementation reused.
// Drafted by tools/virtual_tail_template_v1.py (GPT-6.1 Sol).
// Labels: v2
// {cls}, Dispatch, Invoke, object: GUESS(low) STANDIN
// Original ownership, signature and slot meaning unknown; erased dispatch interface.
// Only Dispatch is compared; no original class layout or runtime behavior claim.
// Origin: {json.dumps(origin(), sort_keys=True)}
'''
    if result == 'argument-dispatch':
        # The receiver is unused; the second argument carries the nullable interface.
        h = f'''#pragma once
class {cls} {{
public:
    virtual void Invoke(unsigned int);
    void Dispatch({cls}* object);
}};
'''
        body = f'void {cls}::Dispatch({cls}* object) {{ if (object) object->Invoke(1); }}\n'
        symbol = f'?Dispatch@{cls}@@QEAAXPEAV1@@Z'
    else:
        h = f'''#pragma once
class {cls} {{
public:
    virtual void Invoke(unsigned int);
    static void Dispatch({cls}* object);
}};
'''
        body = f'void {cls}::Dispatch({cls}* object) {{ if (object) object->Invoke(0); }}\n'
        symbol = f'?Dispatch@{cls}@@SAXPEAV1@@Z'
    return dict(cls=cls, header=prefix+h, source=prefix+f'#include "{cls}.h"\n'+body, symbol=symbol)

"""Storage-free return stand-ins with explicitly extracted result ABI.

No class layout, original signature, ownership or runtime semantics are claimed.
"""
import hashlib
import json
from pathlib import Path

BUILD = 'sse-steam-1-7-104'
RECIPE = 'reconstruction/recipes/msvc-19.16.27054-o2.json'
EVIDENCE = 'findings/ghidra-import.md'


def origin():
    return dict(family='storage-free-return', version='1',
                template_digest=hashlib.sha256(Path(__file__).read_bytes()).hexdigest())


def emit(rva, size, result, value=0):
    forms = {
        'zero-word': ('unsigned int', '', 'return 0u;', 'QEAAIXZ', 3),
        'zero-byte': ('unsigned char', '', 'return 0;', 'QEAAEXZ', 3),
        'constant-byte': ('unsigned char', '', f'return {value};', 'QEAAEXZ', 3),
        'this-pointer': ('void*', '', 'return this;', 'QEAAPEAXXZ', 4),
        'argument-pointer': ('void*', 'void* value', 'return value;', 'QEAAPEAXPEAX@Z', 4),
        'second-argument-word': ('unsigned int', 'unsigned int, unsigned int value',
                                 'return value;', 'QEAAIII@Z', 4),
    }
    if (type(rva) is not int or rva <= 0 or result not in forms
            or type(value) is not int or not 0 <= value <= 255):
        raise ValueError('unsupported return parameters')
    ret, args, body, suffix, expected_size = forms[result]
    if size != expected_size or (result != 'constant-byte' and value != 0):
        raise ValueError('unsupported return extent or value')
    cls = f'ReturnLeaf{rva:x}'
    prefix = f'''// Build: {BUILD}; RVA 0x{rva:x}; {size} bytes
// Evidence: {EVIDENCE}
// Recipe: {RECIPE}
// Source exposure: binary-analysis; no external implementation reused.
// Drafted by tools/storage_free_return_template_v1.py (GPT-6.1 Sol).
// Labels: v2
// {cls}, Invoke, value: GUESS(low) STANDIN
// Original signature and owner unknown; no storage or class-layout claim.
// Only Invoke is compared; a pass proves no name or runtime behavior.
// Origin: {json.dumps(origin(), sort_keys=True)}
'''
    h = prefix + f'#pragma once\nclass {cls} {{\npublic:\n    {ret} Invoke({args});\n}};\n'
    cpp = prefix + f'#include "{cls}.h"\n{ret} {cls}::Invoke({args}) {{ {body} }}\n'
    return dict(cls=cls, header=h, source=cpp, symbol=f'?Invoke@{cls}@@{suffix}')

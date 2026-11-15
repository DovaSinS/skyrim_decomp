"""Pinned standard-library shared ownership teardown source form.

Only the compiler-generated static teardown is compared. No game-class layout
or implementation is supplied: storage and lifetime use the pinned C++ library.
"""
import hashlib
import json
from pathlib import Path

BUILD = 'sse-steam-1-7-104'
RECIPE = 'reconstruction/recipes/msvc-19.16.27054-o2.json'
EVIDENCE = 'findings/ghidra-import.md'


def origin():
    return dict(family='standard-shared-owner-teardown', version='1',
                template_digest=hashlib.sha256(Path(__file__).read_bytes()).hexdigest())


def emit(rva, size):
    if type(rva) is not int or rva <= 0 or size != 78:
        raise ValueError('unsupported shared teardown parameters')
    cls = f'SharedTeardown{rva:x}'
    prefix = f'''// Build: {BUILD}; RVA 0x{rva:x}; {size} bytes
// Evidence: {EVIDENCE}
// Recipe: {RECIPE}
// Source exposure: binary-analysis; original minimal lifetime declaration.
// Drafted by tools/shared_teardown_template_v1.py (GPT-6.1 Sol).
// Labels: v2
// {cls}, object, value: GUESS(low) STANDIN
// Original owner and pointee type unknown; shared_ptr<void> erases the pointee.
// Only the compiler-generated static teardown is compared, not initialization.
// Storage and release use the pinned toolchain standard library through <memory>.
// No external implementation is copied into this unit; no behavior/name claim.
// Origin: {json.dumps(origin(), sort_keys=True)}
'''
    header = prefix + f'''#pragma once
#include <memory>
struct {cls} {{ std::shared_ptr<void> value; }};
'''
    source = prefix + f'#include "{cls}.h"\nstatic {cls} object;\n'
    return dict(cls=cls, header=header, source=source,
                symbol='??__Fobject@@YAXXZ', object_symbol=f'?object@@3U{cls}@@A')

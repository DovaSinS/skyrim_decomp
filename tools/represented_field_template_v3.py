"""Field leaves expressed through existing represented declarations.

The derived source container adds no storage and claims no recovered class name.
Each field binding must be supplied explicitly and its offset asserted by C++.
"""
import hashlib
import json
from pathlib import Path
import re

BUILD = 'sse-steam-1-7-104'
RECIPE = 'reconstruction/recipes/msvc-19.16.27054-o2.json'
EVIDENCE = 'findings/ghidra-import.md'


def origin():
    return dict(family='represented-field-leaf', version='3-labels2',
                template_digest=hashlib.sha256(Path(__file__).read_bytes()).hexdigest())


def emit(row):
    rva, size, operation = row['rva'], row['size'], row['operation']
    if type(rva) is not int or rva < 0 or type(size) is not int or size <= 0:
        raise ValueError('invalid member identity')
    if operation not in ('pointer', 'address', 'present'):
        raise ValueError('unsupported field operation')
    for name in (row['type'], row['field']):
        if not re.fullmatch(r'[A-Za-z_]\w*(?:::[A-Za-z_]\w*)*', name):
            raise ValueError('invalid represented type or field')
    if not re.fullmatch(r'reconstruction/[a-z]+/[A-Z]\w*\.h', row['header']):
        raise ValueError('invalid represented header')
    if type(row['offset']) is not int or row['offset'] < 0:
        raise ValueError('invalid field offset')
    cls = f'FieldLeaf{rva:x}'
    result = 'bool' if operation == 'present' else 'const void*'
    expression = {'pointer': row['field'], 'address': '&' + row['field'],
                  'present': row['field'] + ' != nullptr'}[operation]
    prefix = f'''// Build: {BUILD}; RVA 0x{rva:x}; {size} bytes
// Evidence: {EVIDENCE}
// Recipe: {RECIPE}
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// {cls}, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {json.dumps(origin(), sort_keys=True)}
'''
    header = prefix + f'''#pragma once
#include "{Path(row['header']).name}"
class {cls} : public {row['type']} {{
public:
    {result} Read();
}};
static_assert(offsetof({row['type']}, {row['field']}) == {row['offset']}, "represented field offset");
static_assert(sizeof({cls}) == sizeof({row['type']}), "source container adds no storage");
'''
    source = prefix + f'''#include "{cls}.h"
{result} {cls}::Read() {{ return {expression}; }}
'''
    symbol = f'?Read@{cls}@@' + ('QEAA_NXZ' if operation == 'present' else 'QEAAPEBXXZ')
    return dict(cls=cls, header=header, source=source, symbol=symbol)

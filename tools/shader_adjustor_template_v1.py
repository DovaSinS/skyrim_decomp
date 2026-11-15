"""Emit direct RTTI owner constructors over represented shader inheritance.

Only compiler-generated secondary deleting-destructor adjustors are compared.
The owner destructor remains an external declaration; no added derived helper,
static object, intrinsic or emission-forcing attribute is used.
"""
import hashlib
import json
from pathlib import Path
import re
from adjustor_thunk_template_v3 import msvc_number

BUILD = 'sse-steam-1-7-104'
RECIPE = 'reconstruction/recipes/msvc-19.16.27054-o2.json'
EVIDENCE = 'findings/ghidra-import.md'
BASES = {'BSShader': 'ShaderBaseLayout', 'BSImagespaceShader': 'ImagespaceShaderLayout'}


def origin():
    return dict(family='shader-destructor-adjustor', version='1',
                template_digest=hashlib.sha256(Path(__file__).read_bytes()).hexdigest())


def emit(owner, base, members):
    if not re.fullmatch(r'[A-Za-z_]\w*', owner) or base not in BASES or not members:
        raise ValueError('unsupported shader owner')
    if any(m['this-offset'] != 16 or m['size'] != 9 or m['slot'] != 0 for m in members):
        raise ValueError('outside represented matrix-setter destructor scope')
    cls = owner + 'ThunkLayout'
    parent = BASES[base]
    prefix = f'''// Build: {BUILD}
// Evidence: {EVIDENCE}
// Recipe: {RECIPE}
// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// Drafted by tools/shader_adjustor_template_v1.py (GPT-6.1 Sol).
// Labels: v2
// {owner}: EXE_RTTI
// {cls}: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Base layouts adapt licensed community declarations in their own headers.
// Owner fields and methods outside the compared adjustor are omitted; owner size is not claimed.
// The owner destructor and base constructor remain external; only the listed adjustor is compared.
// No original-source, behavior, allocation-size or name-correctness claim.
// Origin: {json.dumps(origin(), sort_keys=True)}
'''
    prefix += ''.join(f'// RVA 0x{m["entry-rva"]:x}; {m["size"]} bytes\n' for m in members)
    header = prefix + f'''#pragma once
#include "{parent}.h"
namespace ResearchLayouts {{
class {cls} : public {parent} {{
public:
    {cls}();
    ~{cls}() override;
}};
}}
'''
    source = prefix + f'''#include "{cls}.h"
namespace ResearchLayouts {{
{cls}::{cls}() = default;
}}
'''
    return dict(cls=cls, header=header, source=source,
                symbol=f'??_E{cls}@ResearchLayouts@@W{msvc_number(16)}EAAPEAXI@Z',
                callee=f'??_E{cls}@ResearchLayouts@@UEAAPEAXI@Z')

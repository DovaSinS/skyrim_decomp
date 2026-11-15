"""Static string construction with a checked non-null input contract."""
import hashlib
import json
from pathlib import Path

VERSION = '2'
BUILD = 'sse-steam-1-7-104'
RECIPE = 'reconstruction/recipes/msvc-19.16.27054-o2.json'
EVIDENCE = 'findings/ghidra-import.md'


def template_digest():
    return hashlib.sha256(Path(__file__).read_bytes()).hexdigest()


def emit(rva, size):
    if type(rva) is not int or rva < 0 or type(size) is not int or size != 49:
        raise ValueError('unsupported static string identity')
    cls = f'StringStatic{rva:x}'
    origin = dict(family='static-string-acquisition', version=VERSION,
                  template_digest=template_digest())
    common = f'''// Build: {BUILD}
// Evidence: {EVIDENCE}
// Recipe: {RECIPE}
// Source exposure: mixed; binary analysis, CommonLibSSE-NG declarations and permitted FNV string code inspected.
// Code origin: original reconstruction; no external implementation code copied.
// Drafted by GPT-6.1 Sol (template and generator).
// Only the generated initializer and EH cleanup are compared; other implementations are bindings.
// Owning system and original types unknown; this is not a behaviour or naming claim.
// Labels: v2
'''
    header = common + f'''// {cls}, StringSlot, value, input, NullStringInput, text, object: GUESS(low) STANDIN
#pragma once
extern const char text[];
struct StringSlot {{
    const char* value;
    StringSlot(const char*);
    ~StringSlot();
}};
struct NullStringInput {{}};
struct {cls} {{
    StringSlot value;
    // Require a non-null string argument. Member ownership covers failure of the input contract.
    explicit {cls}(const char* input) : value(input) {{ if (!input) throw NullStringInput{{}}; }}
    ~{cls}() {{}}
}};
'''
    cpp = common + f'''// RVA 0x{rva:x}; {size} bytes
// Origin: {json.dumps(origin, sort_keys=True)}
#include "{cls}.h"
static {cls} object(text);
'''
    return cls, header, cpp, origin

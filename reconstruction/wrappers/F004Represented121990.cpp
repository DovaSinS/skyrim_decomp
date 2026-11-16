// Build: sse-steam-1-7-104; RVA 0x121990; 52 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (represented community declaration and independent target bindings).
// Drafted by tools/rootless_represented_wrapper_generate_v3.py (GPT-6.1 Sol).
// Labels: v2
// F004Represented121990, object: GUESS(low) STANDIN
// Declaration source: reconstruction/scaleform/GRefCountImplLayout.h (renamed complete represented declaration).
// Fields and bases are unchanged; relative includes use copied declarations with original notices.
// Complete destructor remains external; only the compiler-emitted deleting wrapper is compared.
// Original ownership, specialization and complete destructor implementation are not claimed.
// Origin: {"family": "rootless-represented-renamed-deleting-wrapper", "template_digest": "5e3face50d9dfb3acbe9c9ac9b04a6fa595f98390cbf76de90000c80d7a3bcf0", "version": "3"}
void operator delete(void*, unsigned __int64) noexcept;
#include "F004Represented121990.h"
static ResearchLayouts::F004Represented121990 object;

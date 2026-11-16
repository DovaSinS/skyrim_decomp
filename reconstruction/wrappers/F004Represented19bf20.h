// Build: sse-steam-1-7-104; RVA 0x19bf20; 52 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (represented community declaration and independent target bindings).
// Drafted by tools/rootless_represented_wrapper_generate_v3.py (GPT-6.1 Sol).
// Labels: v2
// F004Represented19bf20, object: GUESS(low) STANDIN
// Declaration source: reconstruction/bsengine/IOTaskLayout.h (renamed complete represented declaration).
// Fields and bases are unchanged; relative includes use copied declarations with original notices.
// Complete destructor remains external; only the compiler-emitted deleting wrapper is compared.
// Original ownership, specialization and complete destructor implementation are not claimed.
// Origin: {"family": "rootless-represented-renamed-deleting-wrapper", "template_digest": "5e3face50d9dfb3acbe9c9ac9b04a6fa595f98390cbf76de90000c80d7a3bcf0", "version": "3"}
// Build: sse-steam-1-7-104
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Drafted by GPT-6.1 Sol; p106 represented-layout recovery.
// Labels: v2
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/I/IOTask.h; GPL-3.0.
// IOTask: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// Member spelling and base declarations adapt that source; unspecified field meanings remain unknown.
// Omitted methods are not reconstructed. Pointee types are declarations only.
// Explicit padding fields are omitted; compiler alignment must satisfy every size and field assertion.
// Size assertions establish represented layout only, never a comparator match.
// F004Represented19bf20: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "../f004support/BSTaskLayout.h"

namespace ResearchLayouts {
class F004Represented19bf20 : public BSTaskLayout {
public:
    virtual ~F004Represented19bf20();
};
static_assert(sizeof(F004Represented19bf20) == 24, "community represented size");
}

// Build: sse-steam-1-7-104; RVA 0xfc80c0; 52 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (represented community declaration and independent target bindings).
// Drafted by tools/rootless_represented_wrapper_generate_v3.py (GPT-6.1 Sol).
// Labels: v2
// F004Representedfc80c0, object: GUESS(low) STANDIN
// Declaration source: reconstruction/bsengine/QueuedFileLayout.h (renamed complete represented declaration).
// Fields and bases are unchanged; relative includes use copied declarations with original notices.
// Complete destructor remains external; only the compiler-emitted deleting wrapper is compared.
// Original ownership, specialization and complete destructor implementation are not claimed.
// Origin: {"family": "rootless-represented-renamed-deleting-wrapper", "template_digest": "5e3face50d9dfb3acbe9c9ac9b04a6fa595f98390cbf76de90000c80d7a3bcf0", "version": "3"}
// Build: sse-steam-1-7-104
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Drafted by GPT-6.1 Sol; p106 represented-layout recovery.
// Labels: v2
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/Q/QueuedFile.h; GPL-3.0.
// QueuedFile: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// Member spelling and base declarations adapt that source; unspecified field meanings remain unknown.
// Omitted methods are not reconstructed. Pointee types are declarations only.
// Explicit padding fields are omitted; compiler alignment must satisfy every size and field assertion.
// Size assertions establish represented layout only, never a comparator match.
// F004Representedfc80c0: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "../f004support/IOTaskLayout.h"
#include "../f004support/BSFixedStringLayout.h"

namespace ResearchLayouts {
class F004Representedfc80c0;
class F004Representedfc80c0 : public IOTaskLayout {
public:
    virtual ~F004Representedfc80c0();
    std::uint64_t unk18;
    NiPointerLayout<F004Representedfc80c0> parent;
    std::uint64_t children;
    std::uint64_t unk30;
};
static_assert(sizeof(F004Representedfc80c0) == 56, "community represented size");
static_assert(offsetof(F004Representedfc80c0, unk18) == 24, "unk18 offset");
static_assert(offsetof(F004Representedfc80c0, parent) == 32, "parent offset");
static_assert(offsetof(F004Representedfc80c0, children) == 40, "children offset");
static_assert(offsetof(F004Representedfc80c0, unk30) == 48, "unk30 offset");
}

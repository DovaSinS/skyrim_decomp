// BSInlineHostf5afd0, build sse-steam-1-7-104; RVA 0xf5afd0, 48 bytes.
// Labels: v2
// Source exposure: mixed (binary-analysis, community-headers).
// Drafted by GPT-6.1 Sol high; owner awarebayes; p145 second box.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json.
// Evidence: findings/p145-shared-inline.md; original owner and ABI are unknown.
// Body origin: original reconstruction; shared reference types carry their attribution.
// Compared: this host only; the minimal owning-pointer representation is a stand-in.
// BSInlineHostf5afd0, reference: GUESS(low) STANDIN
#include "BSInlineHostf5afd0.h"
BSInlineHostf5afd0::~BSInlineHostf5afd0() {
    if (reference) reference->DecRefCount();
}

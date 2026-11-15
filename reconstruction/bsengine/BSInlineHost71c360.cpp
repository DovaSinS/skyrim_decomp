// BSInlineHost71c360, build sse-steam-1-7-104; RVA 0x71c360, 48 bytes.
// Labels: v2
// Source exposure: mixed (binary-analysis, community-headers).
// Drafted by GPT-6.1 Sol high; owner awarebayes; p145 second box.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json.
// Evidence: findings/p145-shared-inline.md; original owner and ABI are unknown.
// Body origin: original reconstruction; shared reference types carry their attribution.
// Compared: this host only; the minimal owning-pointer representation is a stand-in.
// BSInlineHost71c360, reference: GUESS(low) STANDIN
#include "BSInlineHost71c360.h"
BSInlineHost71c360::~BSInlineHost71c360() {
    if (reference) reference->DecRefCount();
}

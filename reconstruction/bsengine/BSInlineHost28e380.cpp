// BSInlineHost28e380, build sse-steam-1-7-104; RVA 0x28e380, 48 bytes.
// Labels: v2
// Source exposure: mixed (binary-analysis, community-headers).
// Drafted by GPT-6.1 Sol high; owner awarebayes; p145 second box.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json.
// Evidence: findings/p145-shared-inline.md; original owner and ABI are unknown.
// Body origin: original reconstruction; shared reference types carry their attribution.
// Compared: this host only; the minimal owning-pointer representation is a stand-in.
// BSInlineHost28e380, reference: GUESS(low) STANDIN
#include "BSInlineHost28e380.h"
BSInlineHost28e380::~BSInlineHost28e380() {
    if (reference) reference->DecRefCount();
}

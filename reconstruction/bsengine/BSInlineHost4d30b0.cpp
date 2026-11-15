// BSInlineHost4d30b0, build sse-steam-1-7-104; RVA 0x4d30b0, 48 bytes.
// Labels: v2
// Source exposure: mixed (binary-analysis, community-headers).
// Drafted by GPT-6.1 Sol high; owner awarebayes; p145 second box.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json.
// Evidence: findings/p145-shared-inline.md; original owner and ABI are unknown.
// Body origin: original reconstruction; shared reference types carry their attribution.
// Compared: this host only; the minimal owning-pointer representation is a stand-in.
// BSInlineHost4d30b0, reference: GUESS(low) STANDIN
#include "BSInlineHost4d30b0.h"
BSInlineHost4d30b0::~BSInlineHost4d30b0() {
    if (reference) reference->DecRefCount();
}

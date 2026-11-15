// BSInlineHost202380, build sse-steam-1-7-104; RVA 0x202380, 48 bytes.
// Labels: v2
// Source exposure: mixed (binary-analysis, community-headers).
// Drafted by GPT-6.1 Sol high; owner awarebayes; p145.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json.
// Evidence: findings/p145-shared-inline.md; source name and ABI are stand-ins.
// Original reconstruction; community-derived shared types are included with their notice.
// Compared: this host only; external callees are declarations, not reconstructed bodies.
// BSInlineHost202380, Invoke, reference, p145_lookup_a, p145_lookup_b, p145_consume_a, p145_consume_b, p145_get_handle: GUESS(low) STANDIN
#include "BSInlineHost202380.h"
BSInlineHost202380::~BSInlineHost202380() {
    if (reference) reference->DecRefCount();
}

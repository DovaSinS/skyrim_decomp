// Build: sse-steam-1-7-104; RVA 0x5e5a30; 52 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (public typed storage and independent target RTTI/call operands).
// Drafted by GPT-6.1 Sol; complete represented storage deleting wrapper.
// Labels: v2
// Code origin: original wrapper emission unit; public data declarations carry their notices below.
// F004Recovered5e5a30, object: GUESS(low) STANDIN
// BanishEffect: EXE_RTTI
// Full represented storage follows pinned community fields/bases. Virtual method sets and original source identity are unclaimed.
// Destructor remains external. Only the emitted deleting wrapper is compared; allocation size is a consistency check, never layout evidence.
// Independent primary owner vftable slot 19 binds this wrapper, including nonzero destructor slots where present.
void operator delete(void*, unsigned __int64) noexcept;
#include "F004Recovered5e5a30.h"
static ResearchLayouts::F004Recovered5e5a30 object;

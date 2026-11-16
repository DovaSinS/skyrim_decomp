// TESObjectBOOK, build sse-steam-1-7-104.
// Labels: v2
// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0x2805a0, 36 bytes: TESObjectBOOK::Function2805a0.
#include "TESObjectBOOK.h"
void TESObjectBOOK::Function2805a0(bool flag) { BookRequest request{this, flag}; GetManager()->HandleRequest(request); }

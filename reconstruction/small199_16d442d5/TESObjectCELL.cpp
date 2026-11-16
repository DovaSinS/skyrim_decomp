// TESObjectCELL, build sse-steam-1-7-104.
// Labels: v2
// TESObjectCELL, Function2be980, Update, Manager, Get, manager: GUESS(low)
// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis (local binary analysis only).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0x2be980, 39 bytes: TESObjectCELL::Function2be980.

#include "TESObjectCELL.h"
void TESObjectCELL::Function2be980() { const int result = manager->Get(); Update(result, false); }

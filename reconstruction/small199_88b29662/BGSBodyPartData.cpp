// BGSBodyPartData, build sse-steam-1-7-104.
// Labels: v2
// BGSBodyPartData, Function38b7f0, Function38b820, Process: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis (local binary analysis only).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0x38b7f0, 29 bytes: BGSBodyPartData::Function38b7f0.
// RVA 0x38b820, 29 bytes: BGSBodyPartData::Function38b820.

#include "BGSBodyPartData.h"

void* BGSBodyPartData::Function38b7f0(void* a, void* b, void* c, void* d) { return Process(a, b, c, d, false); }
void* BGSBodyPartData::Function38b820(void* a, void* b, void* c, void* d) { return Process(a, b, c, d, true); }

// NiAVObject, build sse-steam-1-7-104.
// Labels: v2
// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis (local binary analysis).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0x1516ee0, 34 bytes: NiAVObject::sub.
// NiAVObject: EXE_RTTI

#include "NiAVObject.h"
void NiAVObject::sub(void* first, void* second, void* third) { Arguments args{first, second, third}; Process(args); }

// BSTempEffectSimpleDecal, build sse-steam-1-7-104.
// Labels: v2
// Origin: original reconstruction; NiObject declarations from reconstruction/netimmerse/NiObject.h.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0x4b31d0, 45 bytes: BSTempEffectSimpleDecal::sub.
// BSTempEffectSimpleDecal, Function4b31d0, ApplyShape: GUESS(low)
// BSTempEffectSimpleDecal: STANDIN GUESS(low)
#pragma once
#include "netimmerse/NiObject.h"
class BSTempEffectSimpleDecal {
public:
 void ApplyShape(BSTriShape*);
 void Function4b31d0(NiObject*);
};

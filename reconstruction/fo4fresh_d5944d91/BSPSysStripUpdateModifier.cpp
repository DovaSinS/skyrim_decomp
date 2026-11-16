// BSPSysStripUpdateModifier, build sse-steam-1-7-104.
// Labels: v2
// RVA 0x1002c80, 12 bytes: BSPSysStripUpdateModifier::Initialize
// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/BSMain/BSPSysStripUpdateModifier.cpp:12 (BSPSysStripUpdateModifier::Initialize)
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// BSPSysStripUpdateModifier, Initialize: GUESS(low)
#include "BSPSysStripUpdateModifier.h"

void BSPSysStripUpdateModifier::Initialize(NiPSysData* data, unsigned short particle, NiPoint3*) { static_cast<BSStripPSysData*>(data)->InitializePoint(particle); }

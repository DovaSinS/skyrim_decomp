// FrenzyEffect function for build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: anonymous sibling and target listing.
// GetTargetValue: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/TargetValueModifierEffect.cpp:198
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x5e5c10, 9 bytes: FrenzyEffect::GetTargetValue
#include "FrenzyEffect.h"
float FrenzyEffect::GetTargetValue() const { return 3.0f; }

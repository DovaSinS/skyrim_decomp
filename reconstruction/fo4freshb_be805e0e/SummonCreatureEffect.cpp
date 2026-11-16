// SummonCreatureEffect functions for build sse-steam-1-7-104.
// Labels: v2
// Task: p177fb-be805e0e
// Source exposure: mixed (pinned target listing and sibling hints).
// Evidence: findings/ghidra-import.md
// RVA 0x5e5360, 27 bytes: SummonCreatureEffect::SetLocation
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// Origin: adapted sibling source and target listing.
// SummonCreatureEffect::SetLocation: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/SummonCreatureEffect.cpp:197
// SummonCreatureEffect, SummonCreatureEffect::SetLocation: GUESS(low)
// SummonCreatureEffect fields: STANDIN GUESS(low)
#include "SummonCreatureEffect.h"
void SummonCreatureEffect::SetLocation(const Point3& value) { location.x = value.x; location.y = value.y; location.z = value.z; }

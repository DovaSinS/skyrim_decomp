// ReferenceEffect functions for build sse-steam-1-7-104.
// Labels: v2
// Task: p177fb-e084f4c9
// Source exposure: mixed (pinned target listing and sibling hints).
// Evidence: findings/ghidra-import.md
// RVA 0x5db660, 10 bytes: ReferenceEffect::ClearTarget
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// Origin: adapted sibling source and target listing.
// ReferenceEffect::ClearTarget: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ReferenceEffect.cpp:155
// ReferenceEffect, ReferenceEffect::ClearTarget: GUESS(low)
// ReferenceEffect fields: STANDIN GUESS(low)
#include "ReferenceEffect.h"
void ReferenceEffect::ClearTarget() { target = nullHandle; }

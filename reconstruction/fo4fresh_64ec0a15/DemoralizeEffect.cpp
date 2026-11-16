// DemoralizeEffect, build sse-steam-1-7-104.
// Labels: v2
// RVA 0x5e5c00, 4 bytes: DemoralizeEffect::GetTargetValue
// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/TargetValueModifierEffect.cpp:122 (DemoralizeEffect::GetTargetValue)
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// DemoralizeEffect, GetTargetValue: GUESS(low)
#include "DemoralizeEffect.h"

float DemoralizeEffect::GetTargetValue() const
{
    return 0.0f;
}


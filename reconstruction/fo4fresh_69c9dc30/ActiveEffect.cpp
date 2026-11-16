// ActiveEffect, build sse-steam-1-7-104.
// Labels: v2
// RVA 0x5bdc10, 9 bytes: ActiveEffect::GetCustomSkillUseMagnitudeMultiplier
// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ActiveEffect.cpp:281 (ActiveEffect::GetCustomSkillUseMagnitudeMultiplier)
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// ActiveEffect, GetCustomSkillUseMagnitudeMultiplier: GUESS(low)
#include "ActiveEffect.h"

float ActiveEffect::GetCustomSkillUseMagnitudeMultiplier(float) const
{
    return 1.0f;
}


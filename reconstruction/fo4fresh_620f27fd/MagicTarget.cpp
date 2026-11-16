// MagicTarget, build sse-steam-1-7-104.
// Labels: v2
// RVA 0x5d2fe0, 9 bytes: MagicTarget::CheckResistance
// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/MagicTarget.cpp:487 (MagicTarget::CheckResistance)
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// MagicTarget, CheckResistance: GUESS(low)
#include "MagicTarget.h"

float MagicTarget::CheckResistance(const MagicItem*, EffectItem*, TESBoundObject*) const
{
    return 1.0f;
}


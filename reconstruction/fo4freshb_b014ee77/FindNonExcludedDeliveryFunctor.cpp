// FindNonExcludedDeliveryFunctor functions for build sse-steam-1-7-104.
// Labels: v2
// Task: p177fb-b014ee77
// Source exposure: mixed (pinned target listing and sibling hints).
// Evidence: findings/ghidra-import.md
// RVA 0x153220, 38 bytes: FindNonExcludedDeliveryFunctor::MatchCondition
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// Origin: adapted sibling source and target listing.
// FindNonExcludedDeliveryFunctor::MatchCondition: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/Magic/MagicItem.cpp:167
// FindNonExcludedDeliveryFunctor, FindNonExcludedDeliveryFunctor::MatchCondition: GUESS(low)
// FindNonExcludedDeliveryFunctor fields: STANDIN GUESS(low)
#include "FindNonExcludedDeliveryFunctor.h"
bool FindNonExcludedDeliveryFunctor::MatchCondition(EffectItem* item) { if (item) { EffectSetting* setting = item->setting; int delivery = setting ? setting->delivery : 5; if (delivery != excluded) return true; } return false; }

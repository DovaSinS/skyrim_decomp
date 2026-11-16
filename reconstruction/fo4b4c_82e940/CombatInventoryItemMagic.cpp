// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x82e940, 24 bytes: CombatInventoryItemMagic::GetOptimalRange
// CombatInventoryItemMagic::GetOptimalRange: SIBLING(fo4-private@1b765c70, author-permission); adapted to target arithmetic.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:387
// names: GUESS(low); method and setting names are unverified.
#include "CombatInventoryItemMagic.h"
float CombatInventoryItemMagic::GetOptimalRange() { return (maxRange - minRange) * optimalRangePercent + minRange; }

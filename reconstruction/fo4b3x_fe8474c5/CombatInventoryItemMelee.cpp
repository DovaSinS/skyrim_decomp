// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x82d1f0, 6 bytes: CombatInventoryItemMelee::GetMaxRange
// CombatInventoryItemMelee::GetMaxRange: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:184
// RVA 0x82d200, 14 bytes: CombatInventoryItemMelee::GetOptimalRange
// CombatInventoryItemMelee::GetOptimalRange: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:186
// RVA 0x82d220, 14 bytes: CombatInventoryItemMelee::GetEquipRange
// CombatInventoryItemMelee::GetEquipRange: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:188
#include "CombatInventoryItemMelee.h"
float CombatInventoryItemMelee::GetMaxRange() { return maxRange; }
float CombatInventoryItemMelee::GetOptimalRange() { return optimalRangeScale * maxRange; }
float CombatInventoryItemMelee::GetEquipRange() { return equipRange + maxRange; }

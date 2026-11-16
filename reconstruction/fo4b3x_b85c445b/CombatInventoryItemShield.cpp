// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x82dc60, 6 bytes: CombatInventoryItemShield::GetMaxRange
// CombatInventoryItemShield::GetMaxRange: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:323
// RVA 0x82dc70, 14 bytes: CombatInventoryItemShield::GetOptimalRange
// CombatInventoryItemShield::GetOptimalRange: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:325
// RVA 0x82dc90, 14 bytes: CombatInventoryItemShield::GetEquipRange
// CombatInventoryItemShield::GetEquipRange: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:327
#include "CombatInventoryItemShield.h"
float CombatInventoryItemShield::GetMaxRange() { return maxRange; }
float CombatInventoryItemShield::GetOptimalRange() { return optimalRangeScale * maxRange; }
float CombatInventoryItemShield::GetEquipRange() { return equipRange + maxRange; }

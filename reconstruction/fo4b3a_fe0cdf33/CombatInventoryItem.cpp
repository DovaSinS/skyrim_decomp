// Build: sse-steam-1-7-104
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// RVA 0x82ce50, 7 bytes: CombatInventoryItem::GetEquipType
// RVA 0x82ce50, 7 bytes: CombatInventoryItem::GetEquipType
// CombatInventoryItem::GetEquipType: SIBLING(fo4-private@1b765c70, author-permission); adaptation of src/Game/AI/Combat/CombatInventoryItem.cpp:147; target behavior differs where applicable.
// Semantic names and types: GUESS(low)
// Labels: v2
// Source exposure: mixed.
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra. Evidence: findings/ghidra-import.md
#include "CombatInventoryItem.h"
CombatInventoryItem::TYPE CombatInventoryItem::GetEquipType(unsigned int) { return GetType(); }

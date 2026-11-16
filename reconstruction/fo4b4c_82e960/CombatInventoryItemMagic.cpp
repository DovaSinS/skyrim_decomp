// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x82e960, 22 bytes: CombatInventoryItemMagic::GetEquipRange
// CombatInventoryItemMagic::GetEquipRange: SIBLING(fo4-private@1b765c70, author-permission); adapted to target arithmetic.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:390
// names: GUESS(low); method and setting names are unverified.
#include "CombatInventoryItemMagic.h"
float CombatInventoryItemMagic::GetEquipRange() { return maxRange > 0.0f ? maxRange : 3.402823466e+38F; }

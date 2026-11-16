// Build: sse-steam-1-7-104; RVA 0x82cea0; 22 bytes
// Labels: v2
// Source exposure: mixed
// Origin: independently decoded target and anonymous sibling hint.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// CombatInventoryItem::CheckShouldEquip: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:103
// names: GUESS(low); names and original signatures are tentative.
#include "CombatInventoryItem.h"
bool CombatInventoryItem::CheckShouldEquip(CombatController* controller) const { return !controller->IsFleeing(); }

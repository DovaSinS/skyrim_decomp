// CombatInventoryItemTorch reconstructed functions.
// Build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Names, signatures and layout are unverified.
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x82e2e0, 6 bytes: CombatInventoryItemTorch::GetMaxRange
// GetMaxRange: Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:370
// CombatInventoryItemTorch, CombatInventoryItemTorch::GetMaxRange: SIBLING(fo4-private@1b765c70, author-permission)
#include "CombatInventoryItemTorch.h"

float CombatInventoryItemTorch::GetMaxRange() const { return maxRange; }

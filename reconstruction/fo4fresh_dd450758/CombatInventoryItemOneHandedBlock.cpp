// CombatInventoryItemOneHandedBlock reconstructed functions.
// Build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Names, signatures and layout are unverified.
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x82e130, 6 bytes: CombatInventoryItemOneHandedBlock::CalculateScore
// CalculateScore: Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:409
// CombatInventoryItemOneHandedBlock, CombatInventoryItemOneHandedBlock::CalculateScore: SIBLING(fo4-private@1b765c70, author-permission)
#include "CombatInventoryItemOneHandedBlock.h"

float CombatInventoryItemOneHandedBlock::CalculateScore(CombatController*) const { return score; }

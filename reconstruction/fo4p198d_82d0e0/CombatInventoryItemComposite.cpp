// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: independently decoded target and anonymous sibling; declarations adapted from community headers.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x82d0e0, 66 bytes: CombatInventoryItemComposite::LoadGame
// CombatInventoryItemComposite::LoadGame: SIBLING(fo4-private@1b765c70, author-permission); adapted to the target calls.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:161
// names: GUESS(low); signatures and helper identities need independent review.
#include "CombatInventoryItemComposite.h"
void CombatInventoryItemComposite::LoadGame(BGSLoadFormBuffer* buffer) { CombatInventoryItem::LoadGame(buffer); unsigned int formID = 0; buffer->LoadFormID(formID); secondaryItem = TESForm::GetFormByNumericID(formID); }

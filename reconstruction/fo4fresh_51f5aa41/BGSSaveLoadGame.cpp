// BGSSaveLoadGame reconstructed functions.
// Build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// IsFormIDInUse: Sibling source: fo4-private@1b765c70 src/Game/SaveGame/BGSSaveLoadGame.cpp:157
// GetChange: Sibling source: fo4-private@1b765c70 src/Game/SaveGame/BGSSaveLoadGame.cpp:115
// RVA 0x618130, 12 bytes: BGSSaveLoadGame::IsFormIDInUse
// RVA 0x616dc0, 15 bytes: BGSSaveLoadGame::GetChange
// BGSSaveLoadGame, BGSSaveLoadGame::IsFormIDInUse, BGSSaveLoadGame::GetChange: SIBLING(fo4-private@1b765c70, author-permission)
// TESForm, ChangeMap, MusicCondition, Player, musicPlayer, unknown00, unknown10, formID, changes, conditions: STANDIN GUESS(low)
// Names, signatures, and layout are unverified.
#include "BGSSaveLoadGame.h"

bool BGSSaveLoadGame::IsFormIDInUse(unsigned int id) const { return changes->HasChanges(id); }
bool BGSSaveLoadGame::GetChange(TESForm* form, unsigned int flags) const { return changes->CheckChangeFlags(form->formID, flags); }

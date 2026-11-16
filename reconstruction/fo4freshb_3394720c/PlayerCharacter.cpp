// PlayerCharacter functions for build sse-steam-1-7-104.
// Labels: v2
// Task: p177fb-3394720c
// Source exposure: mixed (pinned target listing and sibling hints).
// Evidence: findings/ghidra-import.md
// RVA 0x74c520, 11 bytes: PlayerCharacter::HasBeenAttacked
// RVA 0x74c540, 17 bytes: PlayerCharacter::SetBeenAttacked
// RVA 0x7423b0, 37 bytes: PlayerCharacter::GetCannibal
// RVA 0x7423e0, 37 bytes: PlayerCharacter::GetVampireFeed
// RVA 0x75d410, 17 bytes: PlayerCharacter::StartPowerAttackCoolDown
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// Origin: adapted sibling source and target listing.
// PlayerCharacter::HasBeenAttacked: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/AI/PlayerCharacter.cpp:773
// PlayerCharacter::SetBeenAttacked: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/AI/PlayerCharacter.cpp:779
// PlayerCharacter::GetCannibal: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/AI/PlayerCharacter.cpp:1238
// PlayerCharacter::GetVampireFeed: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/AI/PlayerCharacter.cpp:1222
// PlayerCharacter, PlayerCharacter::HasBeenAttacked, PlayerCharacter::SetBeenAttacked: GUESS(low)
// PlayerCharacter fields: STANDIN GUESS(low)
// PlayerCharacter::StartPowerAttackCoolDown: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/AI/PlayerCharacter.cpp:2025
#include "PlayerCharacter.h"
bool PlayerCharacter::HasBeenAttacked() { return (flags >> 7) != 0; }
void PlayerCharacter::SetBeenAttacked(bool value) { flags = (flags & 0x7f) | (value << 7); }

bool PlayerCharacter::GetCannibal() { if (moreFlags & 0x0e) { Package* package = process->package; if (package && package->type == 38) return true; } return false; }
bool PlayerCharacter::GetVampireFeed() { if (moreFlags & 0x0e) { Package* package = process->package; if (package && package->type == 37) return true; } return false; }

void PlayerCharacter::StartPowerAttackCoolDown() { timer = defaultCooldown; }

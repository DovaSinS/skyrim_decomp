// PlayerCharacter functions for build sse-steam-1-7-104.
// Labels: v2
// Task: p177fb-3394720c
// Source exposure: mixed (pinned target listing and sibling hints).
// Evidence: findings/ghidra-import.md
// RVA 0x75d430, 14 bytes: PlayerCharacter::IsPowerAttackCoolingDown
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-sol after a fresh Terra mismatch.
// Origin: adapted permitted anonymous sibling body with a target-specific predicate.
// Sibling source: fo4-private@1b765c70 src/Game/AI/PlayerCharacter.cpp:2032
// PlayerCharacter, PlayerCharacter::HasBeenAttacked, PlayerCharacter::IsPowerAttackCoolingDown, PlayerCharacter::SetBeenAttacked: GUESS(low)
// PlayerCharacter fields: STANDIN GUESS(low)
// PlayerCharacter::GetCannibal, PlayerCharacter::GetVampireFeed: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/AI/PlayerCharacter.cpp:1222,1238
#include "PlayerCharacter.h"
bool PlayerCharacter::IsPowerAttackCoolingDown() const { return !(timer <= 0.0f); }

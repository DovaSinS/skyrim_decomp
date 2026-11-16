// PlayerCameraTransitionState functions for build sse-steam-1-7-104.
// Labels: v2
// Task: p177fb-65cdceb4
// Source exposure: mixed (pinned target listing and sibling hints).
// Evidence: findings/ghidra-import.md
// RVA 0x8fd200, 10 bytes: PlayerCameraTransitionState::Begin
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// Origin: adapted sibling source and target listing.
// PlayerCameraTransitionState::Begin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/PlayerCameraTransitionState.cpp:25
// PlayerCameraTransitionState, PlayerCameraTransitionState::Begin: GUESS(low)
// PlayerCameraTransitionState fields: STANDIN GUESS(low)
#include "PlayerCameraTransitionState.h"
void PlayerCameraTransitionState::Begin() { startTime = lastTime; }

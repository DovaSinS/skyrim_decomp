// PlayerCamera functions for build sse-steam-1-7-104.
// Labels: v2
// Task: p177fb-dfca7f0a
// Source exposure: mixed (pinned target listing and sibling hints).
// Evidence: findings/ghidra-import.md
// RVA 0x8f8eb0, 18 bytes: PlayerCamera::SetSittingRotation
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// Origin: adapted sibling source and target listing.
// PlayerCamera::SetSittingRotation: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/PlayerCamera.cpp:80
// PlayerCamera, PlayerCamera::SetSittingRotation: GUESS(low)
// PlayerCamera fields: STANDIN GUESS(low)
#include "PlayerCamera.h"
void PlayerCamera::SetSittingRotation(float value) { if (state) state->rotation = value; }

// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x8f6fd0, 49 bytes: HorseCameraState::Revert
// HorseCameraState::Revert: SIBLING(fo4-private@1b765c70, author-permission); adapted to target call sequence.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/HorseCameraState.cpp:113
// names: GUESS(low); call identities and method names remain unverified.
#include "HorseCameraState.h"
void HorseCameraState::Revert(BGSLoadFormBuffer* buffer) { ThirdPersonState::Revert(buffer); atMaxHorseAngle = false; horseRefHandle = nullHandle; horseCurrentDirection = 0.0f; }

// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x8f76a0, 28 bytes: HorseCameraState::GetFreeRotationMode
// HorseCameraState::GetFreeRotationMode: SIBLING(fo4-private@1b765c70, author-permission); adapted to target call sequence.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/HorseCameraState.cpp:43
// names: GUESS(low); field meaning and singleton identity remain unverified.
#include "HorseCameraState.h"
bool HorseCameraState::GetFreeRotationMode() const { return freeRotationEnabled || playerControls->data.fovSlideMode; }

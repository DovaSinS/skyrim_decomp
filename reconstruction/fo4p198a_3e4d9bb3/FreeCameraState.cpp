// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x8f6060, 51 bytes: FreeCameraState::GetRotation
// FreeCameraState::GetRotation: SIBLING(fo4-private@1b765c70, author-permission); adapted to target call sequence.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/FreeCameraState.cpp:81
// names: GUESS(low); call identities and method names remain unverified.
#include "FreeCameraState.h"
void FreeCameraState::GetRotation(NiQuaternion& result) const { NiMatrix3 matrix; matrix.FromEulerAnglesZXY(rotation.y, rotation.x, 0.0f); result.FromRotation(matrix); }

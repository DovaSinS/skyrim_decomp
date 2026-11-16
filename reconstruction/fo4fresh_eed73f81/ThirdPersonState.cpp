// ThirdPersonState reconstructed functions.
// Build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// GetRotation: Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/ThirdPersonState.cpp:106
// GetTranslation: Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/ThirdPersonState.cpp:112
// RVA 0x8fd870, 8 bytes: ThirdPersonState::GetRotation
// RVA 0x8fd880, 18 bytes: ThirdPersonState::GetTranslation
// ThirdPersonState, ThirdPersonState::GetRotation, ThirdPersonState::GetTranslation: SIBLING(fo4-private@1b765c70, author-permission)
// Names, signatures, and layout are unverified.
#include "ThirdPersonState.h"

void ThirdPersonState::GetRotation(NiQuaternion& value) const { value = rotation; }
void ThirdPersonState::GetTranslation(NiPoint3& value) const { value.x = translation.x; value.y = translation.y; value.z = translation.z; }

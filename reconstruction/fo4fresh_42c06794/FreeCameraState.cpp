// FreeCameraState reconstructed functions.
// Build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// GetTranslation: Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/FreeCameraState.cpp:25
// RVA 0x8f60a0, 18 bytes: FreeCameraState::GetTranslation
// FreeCameraState, FreeCameraState::GetTranslation: SIBLING(fo4-private@1b765c70, author-permission)
// Names, signatures, and layout are unverified.
#include "FreeCameraState.h"

void FreeCameraState::GetTranslation(NiPoint3& value) const { value.x = translation.x; value.y = translation.y; value.z = translation.z; }

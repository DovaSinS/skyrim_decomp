// VATSCameraState, build sse-steam-1-7-104.
// Labels: v2
// RVA 0x8ffaa0, 14 bytes: VATSCameraState::Begin
// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/VATSCameraState.cpp:36 (VATSCameraState::Begin)
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// VATSCameraState, Begin: GUESS(low)
#include "VATSCameraState.h"
void VATSCameraState::Begin() { player->Show1stPerson(false); }

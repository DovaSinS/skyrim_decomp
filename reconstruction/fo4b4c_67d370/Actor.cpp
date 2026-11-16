// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x67d370, 33 bytes: Actor::UpdateCharacterControllerSimulationSettings
// Actor::UpdateCharacterControllerSimulationSettings: SIBLING(fo4-private@1b765c70, author-permission); adapted to target flag and global accesses.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:1415
// names: GUESS(low); global identity is inferred.
#include "Actor.h"
void Actor::UpdateCharacterControllerSimulationSettings(bhkCharacterController& controller) { if (sceneIsComplex) controller.flags |= 0x100000; else controller.flags &= ~0x100000; }

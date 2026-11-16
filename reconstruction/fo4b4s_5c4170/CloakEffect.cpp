// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-sol.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x5c4170, 56 bytes: CloakEffect::Update
// CloakEffect::Update: SIBLING(fo4-private@1b765c70, author-permission); adapted to target tick width and helper call.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/CloakEffect.cpp:42
// names: GUESS(low); import and helper identities are inferred.
#include "CloakEffect.h"
void CloakEffect::Update(float elapsed) { if ((unsigned)GetTickCount64() >= nextTargetCheck) FindTargets(elapsed); }

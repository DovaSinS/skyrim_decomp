// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x5c58a0, 28 bytes: DetectLifeEffect::CheckCustomSkillUseConditions
// DetectLifeEffect::CheckCustomSkillUseConditions: SIBLING(fo4-private@1b765c70, author-permission); adapted to target call and comparison.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/DetectLifeEffect.cpp:12
// names: GUESS(low); global identity is inferred.
#include "DetectLifeEffect.h"
bool DetectLifeEffect::CheckCustomSkillUseConditions() const { return target->GetTargetAsActor() != player; }

// Build: sse-steam-1-7-104
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// RVA 0x5e5c20, 9 bytes: RallyEffect::GetTargetValue
// RVA 0x5e5c20, 9 bytes: RallyEffect::GetTargetValue
// RallyEffect::GetTargetValue: SIBLING(fo4-private@1b765c70, author-permission); adaptation of src/Game/Magic/TargetValueModifierEffect.cpp:32.
// Semantic names and types: GUESS(low)
// Labels: v2
// Source exposure: mixed.
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra. Evidence: findings/ghidra-import.md
#include "RallyEffect.h"
float RallyEffect::GetTargetValue() const { return 4.0f; }

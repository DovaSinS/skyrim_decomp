// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x14b700, 53 bytes: EffectSetting::GetEffectShader
// EffectSetting::GetEffectShader: SIBLING(fo4-private@1b765c70, author-permission); adapted to target call sequence.
// Sibling source: fo4-private@1b765c70 src/Shared/Magic/EffectSetting.cpp:299
// names: GUESS(low); call identities and method names remain unverified.
#include "EffectSetting.h"
TESEffectShader* EffectSetting::GetEffectShader(bool dual) { auto visual = data.hitVisuals; auto result = visual ? visual->data.effectShader : data.effectShader; if (dual && data.dualCastData && data.dualCastData->data.effectShader) result = data.dualCastData->data.effectShader; return result; }

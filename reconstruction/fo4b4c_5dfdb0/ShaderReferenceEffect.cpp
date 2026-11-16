// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x5dfdb0, 17 bytes: ShaderReferenceEffect::Push
// ShaderReferenceEffect::Push: SIBLING(fo4-private@1b765c70, author-permission); adapted to target field accesses.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ShaderReferenceEffect.cpp:393
// names: GUESS(low); method name and signature are unverified.
#include "ShaderReferenceEffect.h"
void ShaderReferenceEffect::Push() { if (effectShaderData) ++pushCount; }

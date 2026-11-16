// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed (local target analysis and permitted sibling).
// Origin: independently reconstructed from target and sibling hints.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// names: GUESS(low); signatures and type names are hypotheses.
// RVA 0x2b68d0, 24 bytes.
// TESLandTexture::InitializeData: SIBLING(fo4-private@1b765c70, author-permission); adapted initialization.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESLandTexture.cpp:27
// TESLandTexture and members: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted declarations.
#include "TESLandTexture.h"
void TESLandTexture::InitializeData() {
    friction = 30;
    restitution = 30;
    specularExponent = 30;
    textureSet = nullptr;
    materialType = nullptr;
    shaderTextureIndex = 0;
}

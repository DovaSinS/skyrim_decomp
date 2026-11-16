// Historical individual reconstruction, build sse-steam-1-7-104, RVA 0x1f2dc0, 82 bytes.
// Labels: v2
// Source exposure: mixed (authorized target analysis and anonymous permitted sibling source).
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-sol (historical p130 source; p177 recovery), human owner awarebayes.
// Origin: adapted from the cited game-code body under anonymous author permission.
// Licence: fo4-private reused with author permission conditional on anonymity.
// Partial declarations are stand-ins; no complete layout, original-source or behavior claim.
// A comparator pass covers only this function; sibling declarations are hypotheses, never target evidence.
// BSFixedString: STANDIN GUESS(low)
// data: GUESS(low)
// TESTexture, GetAsNormalFile: SIBLING(fo4-private@1b765c70, author-permission)
// Adapted bodies: TESTexture::GetAsNormalFile and TESTexture::GetAsSkinFile.
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESTexture.cpp:116
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESTexture.cpp:125
// GetAsSkinFile: SIBLING(fo4-private@1b765c70, author-permission)
#include "TESTexture.h"
void TESTexture::GetAsNormalFile(const char *apTextureName, char *apNormalTextureName)
{
    strcpy_s(apNormalTextureName, 0x104u, apTextureName);
    char *v3 = strrchr(apNormalTextureName, '.');
    if (v3)
        strcpy_s(v3, apNormalTextureName - v3 + 260, "_n.dds");

}

void TESTexture::GetAsSkinFile(const char *apTextureName, char *apSkinTextureName)
{
    strcpy_s(apSkinTextureName, 0x104u, apTextureName);
    char *v3 = strrchr(apSkinTextureName, '.');
    if (v3)
        strcpy_s(v3, apSkinTextureName - v3 + 260, "_sk.dds");

}

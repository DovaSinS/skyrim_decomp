// ImageSpaceModifierInstanceTemp function for build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: anonymous sibling and target listing.
// PrintInfo: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/ImageSpaceModifierInstance.cpp:116
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x2a4700, 20 bytes: ImageSpaceModifierInstanceTemp::PrintInfo
#include "ImageSpaceModifierInstanceTemp.h"
void ImageSpaceModifierInstanceTemp::PrintInfo(char* buffer) { BSsprintf(buffer, 0x800, "  Temp"); }

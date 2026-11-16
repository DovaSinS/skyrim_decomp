// LightEffect function for build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: anonymous sibling and target listing.
// Revert: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/LightEffect.cpp:230
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x5c9970, 27 bytes: LightEffect::Revert
#include "LightEffect.h"
void LightEffect::Revert(BGSLoadFormBuffer* buffer) { ActiveEffect::Revert(buffer); DetachLight(); }

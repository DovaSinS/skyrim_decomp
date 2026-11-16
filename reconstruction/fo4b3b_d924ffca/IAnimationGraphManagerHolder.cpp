// Build: sse-steam-1-7-104
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// RVA 0x6b61b0, 7 bytes: IAnimationGraphManagerHolder::GetGraphVariableCacheSize
// IAnimationGraphManagerHolder::GetGraphVariableCacheSize, build sse-steam-1-7-104, RVA 0x6b61b0, 7 bytes.
// Labels: v2
// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: original reconstruction using target listing and anonymous sibling hints.
// GetGraphVariableCacheSize: SIBLING(fo4-private@1b765c70, author-permission); src/Shared/Animation/IAnimationGraphManagerHolder.cpp:225; signature hint only; target reads a global.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Semantic names and types: GUESS(low); except where separately attributed.
#include "IAnimationGraphManagerHolder.h"
unsigned int IAnimationGraphManagerHolder::GetGraphVariableCacheSize() const { return graphVariableCacheSize; }

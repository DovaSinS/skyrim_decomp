// Build: sse-steam-1-7-104
// IAnimationGraphManagerHolder::GetGraphVariableCacheSize, build sse-steam-1-7-104, RVA 0x6b61b0, 7 bytes.
// Labels: v2
// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: original reconstruction using target listing and anonymous sibling hints.
// GetGraphVariableCacheSize: SIBLING(fo4-private@1b765c70, author-permission); src/Shared/Animation/IAnimationGraphManagerHolder.cpp:225; signature hint only; target reads a global.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Semantic names and types: GUESS(low); except where separately attributed.
#pragma once
extern unsigned int graphVariableCacheSize;
class IAnimationGraphManagerHolder { public: unsigned int GetGraphVariableCacheSize() const; };

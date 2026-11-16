// PathingRequestRotate partial declarations.
// Build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// GetType: Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestRotate.cpp:26
// RVA 0x4f9080, 47 bytes: PathingRequestRotate::GetType
// PathingRequestRotate, PathingRequestRotate::GetType: SIBLING(fo4-private@1b765c70, author-permission)
// PathingRequestRotate_typeCRC, PathingRequestRotate_typeName, GenerateTypeCRC: STANDIN GUESS(low)
// Names, signatures, and layout are unverified.
#pragma once
class PathingRequestRotate {
public:
    unsigned int GetType() const;
};

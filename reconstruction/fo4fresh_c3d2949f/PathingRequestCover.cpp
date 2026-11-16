// PathingRequestCover reconstructed functions.
// Build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// GetType: Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestCover.cpp:30
// RVA 0x4f4300, 47 bytes: PathingRequestCover::GetType
// PathingRequestCover, PathingRequestCover::GetType: SIBLING(fo4-private@1b765c70, author-permission)
// PathingRequestCover_typeCRC, PathingRequestCover_typeName, GenerateTypeCRC: STANDIN GUESS(low)
// Names, signatures, and layout are unverified.
#include "PathingRequestCover.h"

extern unsigned int PathingRequestCover_typeCRC;
extern const char PathingRequestCover_typeName[];
void GenerateTypeCRC(unsigned int&, const char*, unsigned int);

unsigned int PathingRequestCover::GetType() const { if (!PathingRequestCover_typeCRC) GenerateTypeCRC(PathingRequestCover_typeCRC, PathingRequestCover_typeName, 0); return PathingRequestCover_typeCRC; }

// PathingRequestFlee reconstructed functions.
// Build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// GetType: Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestFlee.cpp:56
// RVA 0x4f4f70, 47 bytes: PathingRequestFlee::GetType
// PathingRequestFlee, PathingRequestFlee::GetType: SIBLING(fo4-private@1b765c70, author-permission)
// PathingRequestFlee_typeCRC, PathingRequestFlee_typeName, GenerateTypeCRC: STANDIN GUESS(low)
// Names, signatures, and layout are unverified.
#include "PathingRequestFlee.h"

extern unsigned int PathingRequestFlee_typeCRC;
extern const char PathingRequestFlee_typeName[];
void GenerateTypeCRC(unsigned int&, const char*, unsigned int);

unsigned int PathingRequestFlee::GetType() const { if (!PathingRequestFlee_typeCRC) GenerateTypeCRC(PathingRequestFlee_typeCRC, PathingRequestFlee_typeName, 0); return PathingRequestFlee_typeCRC; }

// PathingRequestClosePoint reconstructed functions.
// Build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// GetType: Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestClosePoint.cpp:77
// RVA 0x4f23e0, 47 bytes: PathingRequestClosePoint::GetType
// PathingRequestClosePoint, PathingRequestClosePoint::GetType: SIBLING(fo4-private@1b765c70, author-permission)
// PathingRequestClosePoint_typeCRC, PathingRequestClosePoint_typeName, GenerateTypeCRC: STANDIN GUESS(low)
// Names, signatures, and layout are unverified.
#include "PathingRequestClosePoint.h"

extern unsigned int PathingRequestClosePoint_typeCRC;
extern const char PathingRequestClosePoint_typeName[];
void GenerateTypeCRC(unsigned int&, const char*, unsigned int);

unsigned int PathingRequestClosePoint::GetType() const { if (!PathingRequestClosePoint_typeCRC) GenerateTypeCRC(PathingRequestClosePoint_typeCRC, PathingRequestClosePoint_typeName, 0); return PathingRequestClosePoint_typeCRC; }

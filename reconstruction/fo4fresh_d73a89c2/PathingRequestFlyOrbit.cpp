// PathingRequestFlyOrbit reconstructed functions.
// Build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// GetType: Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestFlyOrbit.cpp:67
// RVA 0x4f74f0, 47 bytes: PathingRequestFlyOrbit::GetType
// PathingRequestFlyOrbit, PathingRequestFlyOrbit::GetType: SIBLING(fo4-private@1b765c70, author-permission)
// PathingRequestFlyOrbit_typeCRC, PathingRequestFlyOrbit_typeName, GenerateTypeCRC: STANDIN GUESS(low)
// Names, signatures, and layout are unverified.
#include "PathingRequestFlyOrbit.h"

extern unsigned int PathingRequestFlyOrbit_typeCRC;
extern const char PathingRequestFlyOrbit_typeName[];
void GenerateTypeCRC(unsigned int&, const char*, unsigned int);

unsigned int PathingRequestFlyOrbit::GetType() const { if (!PathingRequestFlyOrbit_typeCRC) GenerateTypeCRC(PathingRequestFlyOrbit_typeCRC, PathingRequestFlyOrbit_typeName, 0); return PathingRequestFlyOrbit_typeCRC; }

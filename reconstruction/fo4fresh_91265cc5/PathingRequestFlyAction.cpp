// PathingRequestFlyAction reconstructed functions.
// Build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// GetType: Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestFlyAction.cpp:58
// RVA 0x4f5ac0, 47 bytes: PathingRequestFlyAction::GetType
// PathingRequestFlyAction, PathingRequestFlyAction::GetType: SIBLING(fo4-private@1b765c70, author-permission)
// PathingRequestFlyAction_typeCRC, PathingRequestFlyAction_typeName, GenerateTypeCRC: STANDIN GUESS(low)
// Names, signatures, and layout are unverified.
#include "PathingRequestFlyAction.h"

extern unsigned int PathingRequestFlyAction_typeCRC;
extern const char PathingRequestFlyAction_typeName[];
void GenerateTypeCRC(unsigned int&, const char*, unsigned int);

unsigned int PathingRequestFlyAction::GetType() const { if (!PathingRequestFlyAction_typeCRC) GenerateTypeCRC(PathingRequestFlyAction_typeCRC, PathingRequestFlyAction_typeName, 0); return PathingRequestFlyAction_typeCRC; }

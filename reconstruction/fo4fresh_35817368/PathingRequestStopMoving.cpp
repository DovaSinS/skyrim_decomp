// PathingRequestStopMoving, build sse-steam-1-7-104.
// Labels: v2
// RVA 0x4f9670, 47 bytes: PathingRequestStopMoving::GetType
// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestStopMoving.cpp:17 (PathingRequestStopMoving::GetType)
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// PathingRequestStopMoving, GetType, typeId, result, BSCRC32, GenerateCRC: GUESS(low)
#include "PathingRequestStopMoving.h"
unsigned int PathingRequestStopMoving::GetType() const
{
    unsigned int result = typeId;
    if (!result) {
        BSCRC32::GenerateCRC(typeId, "PathingRequestStopMoving", 0);
        return typeId;
    }
    return result;
}

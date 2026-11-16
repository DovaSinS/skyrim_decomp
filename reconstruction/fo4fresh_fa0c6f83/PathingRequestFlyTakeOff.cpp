// PathingRequestFlyTakeOff, build sse-steam-1-7-104.
// Labels: v2
// RVA 0x4f7920, 47 bytes: PathingRequestFlyTakeOff::GetType
// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestFlyTakeOff.cpp:53 (PathingRequestFlyTakeOff::GetType)
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// PathingRequestFlyTakeOff, GetType, typeId, result, BSCRC32, GenerateCRC: GUESS(low)
#include "PathingRequestFlyTakeOff.h"
unsigned int PathingRequestFlyTakeOff::GetType() const
{
    unsigned int result = typeId;
    if (!result) {
        BSCRC32::GenerateCRC(typeId, "PathingRequestFlyTakeOff", 0);
        return typeId;
    }
    return result;
}

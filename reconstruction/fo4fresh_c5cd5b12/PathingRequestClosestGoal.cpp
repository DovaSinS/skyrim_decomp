// PathingRequestClosestGoal, build sse-steam-1-7-104.
// Labels: v2
// RVA 0x4f2990, 47 bytes: PathingRequestClosestGoal::GetType
// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestClosestGoal.cpp:34 (PathingRequestClosestGoal::GetType)
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// PathingRequestClosestGoal, GetType, typeId, result, BSCRC32, GenerateCRC: GUESS(low)
#include "PathingRequestClosestGoal.h"
unsigned int PathingRequestClosestGoal::GetType() const
{
    unsigned int result = typeId;
    if (!result) {
        BSCRC32::GenerateCRC(typeId, "PathingRequestClosestGoal", 0);
        return typeId;
    }
    return result;
}

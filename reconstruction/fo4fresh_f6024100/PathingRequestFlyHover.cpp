// PathingRequestFlyHover, build sse-steam-1-7-104.
// Labels: v2
// RVA 0x4f6380, 47 bytes: PathingRequestFlyHover::GetType
// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestFlyHover.cpp:45 (PathingRequestFlyHover::GetType)
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// PathingRequestFlyHover, GetType, typeId, result, BSCRC32, GenerateCRC: GUESS(low)
#include "PathingRequestFlyHover.h"
unsigned int PathingRequestFlyHover::GetType() const
{
    unsigned int result = typeId;
    if (!result) {
        BSCRC32::GenerateCRC(typeId, "PathingRequestFlyHover", 0);
        return typeId;
    }
    return result;
}

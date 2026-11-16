// PathingRequestSafeStraightLine function for build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: anonymous sibling and target listing.
// GetType: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestSafeStraightLine.cpp:41
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x4f93a0, 47 bytes: PathingRequestSafeStraightLine::GetType
#include "PathingRequestSafeStraightLine.h"
unsigned int PathingRequestSafeStraightLine::GetType() const {
    unsigned int result = PathingRequestSafeStraightLineCRC;
    if (!result) {
        BSCRC32::GenerateCRC(PathingRequestSafeStraightLineCRC, "PathingRequestSafeStraightLine", 0);
        return PathingRequestSafeStraightLineCRC;
    }
    return result;
}

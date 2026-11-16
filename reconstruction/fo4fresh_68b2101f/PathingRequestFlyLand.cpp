// PathingRequestFlyLand function for build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: anonymous sibling and target listing.
// GetType: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestFlyLand.cpp:59
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x4f6e90, 47 bytes: PathingRequestFlyLand::GetType
#include "PathingRequestFlyLand.h"
unsigned int PathingRequestFlyLand::GetType() const {
    unsigned int result = PathingRequestFlyLandCRC;
    if (!result) {
        BSCRC32::GenerateCRC(PathingRequestFlyLandCRC, "PathingRequestFlyLand", 0);
        return PathingRequestFlyLandCRC;
    }
    return result;
}

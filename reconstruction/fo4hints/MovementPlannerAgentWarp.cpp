// Historical individual reconstruction, build sse-steam-1-7-104, RVA 0x7a9340, 140 bytes.
// Labels: v2
// Source exposure: mixed (authorized target analysis and anonymous permitted sibling source).
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-sol (historical p130 source; p177 recovery), human owner awarebayes.
// Origin: adapted from the cited game-code body under anonymous author permission.
// Licence: fo4-private reused with author permission conditional on anonymity.
// Partial declarations are stand-ins; no complete layout, original-source or behavior claim.
// A comparator pass covers only this function; sibling declarations are hypotheses, never target evidence.
// BSFixedString: STANDIN GUESS(low)
// data: GUESS(low)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementPlannerAgentWarp.cpp:67
// MovementPlannerAgentWarp, QClassAgentType: SIBLING(fo4-private@1b765c70, author-permission)
#include "MovementPlannerAgentWarp.h"
const BSFixedString &MovementPlannerAgentWarp::QClassAgentType()
{
    static BSFixedString typeString("FailSafe Warp");
    return typeString;

}

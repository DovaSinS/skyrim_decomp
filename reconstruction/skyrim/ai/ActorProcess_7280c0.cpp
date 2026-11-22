// Source exposure: community-headers (names, layout), binary-analysis (offsets from the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x7280c0 ActorProcess::HasPerk
// Adapted bodies: none
#include "ActorProcess_7280c0.h"

std::uint8_t ActorProcess::HasPerk(Actor* a_actor, BGSPerk* a_perk)
{
    if (middleHigh) {
        FindPerkVisitor visitor(a_perk);
        a_actor->ForEachPerk(visitor);
        if (visitor.found) {
            return visitor.found->rank;
        }
    }
    return 0;
}

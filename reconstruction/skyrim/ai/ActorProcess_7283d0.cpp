// Source exposure: community-headers (names, layout), binary-analysis (offsets from the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x7283d0 ActorProcess::HasPerkEntries
// Adapted bodies: none
#include "ActorProcess_7283d0.h"

bool ActorProcess::HasPerkEntries(std::uint8_t a_entryPoint) const
{
    if (middleHigh && middleHigh->perkData && a_entryPoint < 0x5C) {
        if (middleHigh->perkData->entries[a_entryPoint].size > 0) {
            return true;
        }
    }
    return false;
}

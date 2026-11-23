// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x69f920 Actor::Function69f920
// Adapted bodies: none
#include "Actor_69f920.h"

std::uint8_t Actor::Function69f920(BGSPerk* a_perk)
{
    if (currentProcess) {
        return currentProcess->HasPerk(this, a_perk);
    }
    return 0;
}

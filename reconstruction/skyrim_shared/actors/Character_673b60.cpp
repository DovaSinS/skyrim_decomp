// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x673b60 Character::FightsInWater
// Adapted bodies: none
#include "Character_673b60.h"

bool Character::FightsInWater() const
{
    std::uint32_t flags = race->flags;
    if (!IsFlagBitSet(flags, 6)) {
        return false;
    }
    return !IsFlagBitSet(flags, 11);
}

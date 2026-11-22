// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x673ac0 Character::SwimsOnly
// Adapted bodies: none
#include "Character_673ac0.h"

bool Character::SwimsOnly() const
{
    std::uint32_t flags = race->flags;
    return !IsFlagBitSet(flags, 8) && IsFlagBitSet(flags, 6) && !IsFlagBitSet(flags, 7);
}

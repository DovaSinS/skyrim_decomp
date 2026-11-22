// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x674000 Character::GetEssential
// Adapted bodies: none
#include "Character_674000.h"

bool Character::GetEssential(bool a_includeProtected) const
{
    std::uint32_t flags = boolFlags;
    bool essential = IsFlagBitSet(flags, 18);
    if (essential || !a_includeProtected) {
        return essential;
    }
    return IsFlagBitSet(flags, 19);
}

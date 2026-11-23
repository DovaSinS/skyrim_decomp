// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6d9500 Actor::GetSoul
// Adapted bodies: none
#include "Actor_6d9500.h"

std::uint32_t Actor::GetSoul()
{
    return TESSoulGem::GetSoulLevelValue(GetSoulLevel());
}

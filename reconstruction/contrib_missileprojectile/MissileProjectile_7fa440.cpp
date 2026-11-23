// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x7fa440 MissileProjectile::Function7fa440
// Adapted bodies: none
#include "MissileProjectile_7fa440.h"

bool MissileProjectile::Function7fa440()
{
    return owner && !owner->GetSlotValue();
}

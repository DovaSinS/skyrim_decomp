// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x7fbfa0 Projectile::Function7fbfa0
// Adapted bodies: none
#include "Projectile_7fbfa0.h"

float Projectile::Function7fbfa0()
{
    float scale = source->scale;
    return GetFactorA() * scale * GetFactorB() * multiplier;
}

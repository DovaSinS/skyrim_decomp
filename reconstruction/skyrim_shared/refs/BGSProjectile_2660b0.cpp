// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x2660b0 BGSProjectile::GetCollisionLayer
// Adapted bodies: none
#include "BGSProjectile_2660b0.h"

// an explicit collision layer wins; otherwise the layer follows the projectile type
std::uint32_t BGSProjectile::GetCollisionLayer() const
{
    if (data.collisionLayer)
        return data.collisionLayer->collisionIdx;
    std::uint32_t layer = 7;
    switch (data.flagsAndType & 0x7F0000) {
    case 0x100000:
        layer = 38;
        break;
    case 0x400000:
        layer = 6;
        break;
    }
    return layer;
}

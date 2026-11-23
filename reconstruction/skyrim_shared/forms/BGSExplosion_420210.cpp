// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x420210 BGSExplosion::ScaleByDistance
// Adapted bodies: none
#include "BGSExplosion_420210.h"

float BGSExplosion::ScaleByDistance(const BGSExplosion* a_explosion, float a_distance)
{
    const float strength = a_explosion ? a_explosion->strength : 0.0f;
    return (gDistanceScale * a_distance + gDistanceBias) * strength;
}

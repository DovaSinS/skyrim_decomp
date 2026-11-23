// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x2f40e0 TESObjectREFR::DistanceSquaredTo
// Adapted bodies: none
#include "TESObjectREFR_2f40e0.h"

float TESObjectREFR::DistanceSquaredTo(const NiPoint3Stand* a_point) const
{
    float dx = a_point->x - position.x;
    float dy = a_point->y - position.y;
    float dz = a_point->z - position.z;
    return dy * dy + dx * dx + dz * dz;
}

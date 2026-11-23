// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x2f40a0 TESObjectREFR::Function2f40a0
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none
#include "TESObjectREFR_2f40a0.h"

#include <cmath>

float TESObjectREFR::Function2f40a0(const NiPoint3& a_pos)
{
    float dx = a_pos.x - data.location.x;
    float dy = a_pos.y - data.location.y;
    float dz = a_pos.z - data.location.z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

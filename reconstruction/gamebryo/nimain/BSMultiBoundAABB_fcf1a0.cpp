// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xfcf1a0 BSMultiBoundAABB::GetWithinPoint
// Adapted bodies: none
// Recipe: reconstruction/recipes/o2-fpfast.json
#include "BSMultiBoundAABB_fcf1a0.h"

#include <cmath>

bool BSMultiBoundAABB::GetWithinPoint(const NiPoint3& a_pos)
{
    const NiPoint3 diff{ a_pos.x - center.x, a_pos.y - center.y, a_pos.z - center.z };
    if (std::fabs(diff.x) - size.x > 0.01f) {
        return false;
    }
    if (std::fabs(diff.y) - size.y > 0.01f) {
        return false;
    }
    if (std::fabs(diff.z) - size.z > 0.01f) {
        return false;
    }
    return true;
}

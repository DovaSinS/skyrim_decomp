// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x248230 LocalMapCamera::SetExtents
// Adapted bodies: none
#include "LocalMapCamera_248230.h"

void LocalMapCamera::SetExtents(const NiPoint3& a_max, const NiPoint3& a_min)
{
    maxExtent = a_max;
    minExtent = a_min;
    maxExtent.z = kLocalMapExtentZBias + maxExtent.z;
}

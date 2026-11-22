// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xfe8120 BSOcclusionBox::BSOcclusionBox
// Adapted bodies: none
#include "BSOcclusionBox_fe8120.h"

BSOcclusionBox::BSOcclusionBox(const NiPoint3& a_center, const NiPoint3& a_extents)
{
    center.x = a_center.x;
    center.y = a_center.y;
    center.z = a_center.z;
    extents.x = a_extents.x;
    extents.y = a_extents.y;
    extents.z = a_extents.z;
}

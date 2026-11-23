// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x3018e0 TESObjectREFR::CheckPosition
// Adapted bodies: none
#include "TESObjectREFR_3018e0.h"

bool TESObjectREFR::CheckPosition(PointVisitor* a_visitor) const
{
    NiPoint3Stand point;
    point.x = position.x;
    point.y = position.y;
    point.z = position.z;
    return a_visitor->TestPoint(&point);
}

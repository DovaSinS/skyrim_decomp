// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6b5820 Actor::Function6b5820
// Adapted bodies: none
#include "Actor_6b5820.h"

void Actor::Function6b5820(Vec3Like& a_out)
{
    const Vec3Like& value = unk38 ? unk38->Function7233b0() : g_defaultVec6b5820;
    a_out.x = value.x;
    a_out.y = value.y;
    a_out.z = value.z;
}

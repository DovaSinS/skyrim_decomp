// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xf3d830 NiUnionBV::ForEachBoundingVolume
// Adapted bodies: none
#include "NiUnionBV_f3d830.h"

void NiUnionBV::ForEachBoundingVolume(NiUnionBV* a_other, void* a_extra)
{
    for (std::uint32_t i = 0; i < volumeCount; ++i) {
        volumes[i]->Slot05(a_other->volumes[i], a_extra);
    }
}

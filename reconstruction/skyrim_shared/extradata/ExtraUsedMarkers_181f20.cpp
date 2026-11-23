// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x181f20 ExtraUsedMarkers::Function181f20
// Adapted bodies: none
#include "ExtraUsedMarkers_181f20.h"

bool ExtraUsedMarkers::Function181f20(std::uint32_t a_value)
{
    bool found = false;
    for (std::uint32_t i = 0; i < unk20; ++i) {
        if (a_value == unk10[i].unk04) {
            found = true;
            break;
        }
    }
    return found;
}

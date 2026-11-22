// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xf8d0e0 BSTreadTransfInterpolator::GetChannelPosed
// Adapted bodies: none
#include "BSTreadTransfInterpolator_f8d0e0.h"

bool BSTreadTransfInterpolator::GetChannelPosed(std::uint16_t) const
{
    if (spLerpData) {
        Unk3A();
    }
    return false;
}

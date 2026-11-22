// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xf8c9d0 BSTreadTransfInterpolator::RegisterStreamables
// Adapted bodies: none
#include "BSTreadTransfInterpolator_f8c9d0.h"

bool BSTreadTransfInterpolator::RegisterStreamables(NiStream& a_stream)
{
    bool registered = NiInterpolator::RegisterStreamables(a_stream);
    if (registered) {
        for (std::uint32_t i = 0; i < uiNumLinks; ++i) {
            a_stream.RegisterFixedString(Links[i].fixedString);
        }
        if (spLerpData) {
            spLerpData->RegisterStreamables(a_stream);
        }
    }
    return registered;
}

// Source exposure: mixed (local binary analysis and public names).
// Code origin: written for this reconstruction from the listing; slot and field offsets measured, names invented.
// Adapted bodies: none.
// NiSingleInterpController: EXE_RTTI
// GetInterpolatorCount: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding, stand-in bases: GUESS(low); storage and slot names invented for measured offsets
// 0xf62fc0 NiSingleInterpController::GetInterpolatorCount
// 0xf63010 NiSingleInterpController::Functionf63010
// 0xf630b0 NiSingleInterpController::Functionf630b0
// 0xf63140 NiSingleInterpController::Functionf63140
// SPDX-License-Identifier: CC0-1.0
// Drafted by v-macrev, assisted by claude-sonnet-5-5.
#include "NiSingleInterpController.h"

std::uint32_t NiSingleInterpController::GetInterpolatorCount() const
{
    return 0x1;
}

NiInterpolatorStub* NiSingleInterpController::Functionf63010()
{
    return interpolator;
}

void NiSingleInterpController::Functionf630b0()
{
    if (interpolator) {
        interpolator->Op();
    }
}

void NiSingleInterpController::Functionf63140()
{
    ApplyTarget(target);
}

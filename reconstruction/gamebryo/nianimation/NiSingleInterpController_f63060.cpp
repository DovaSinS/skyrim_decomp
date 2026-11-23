// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xf63060 NiSingleInterpController::ResetTimeExtrema
// Adapted bodies: none
#include "NiSingleInterpController_f63060.h"

// IsFlagSet: GUESS(low); a flag-word bit test by bit index, taking the word by value.
inline bool IsFlagSet(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

void NiSingleInterpController::ResetTimeExtrema()
{
    if (!IsFlagSet(flags, 5)) {
        NiInterpController::ResetTimeExtrema();
        if (interpolator) {
            interpolator->Slot50(&lowTime, &highTime);
        }
    }
}

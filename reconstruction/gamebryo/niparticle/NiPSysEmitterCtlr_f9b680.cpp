// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xf9b680 NiPSysEmitterCtlr::GuaranteeTimeRange
// Adapted bodies: none
#include "NiPSysEmitterCtlr_f9b680.h"

void NiPSysEmitterCtlr::GuaranteeTimeRange(float a_startTime, float a_endTime)
{
    NiSingleInterpController::GuaranteeTimeRange(a_startTime, a_endTime);
    if (visibilityInterpolator) {
        visibilityInterpolator->GuaranteeTimeRange(a_startTime, a_endTime);
    }
}

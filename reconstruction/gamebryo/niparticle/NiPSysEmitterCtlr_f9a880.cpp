// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xf9a880 NiPSysEmitterCtlr::RegisterStreamables
// Adapted bodies: none
#include "NiPSysEmitterCtlr_f9a880.h"

bool NiPSysEmitterCtlr::RegisterStreamables(NiStream& a_stream)
{
    if (!NiPSysModifierCtlr::RegisterStreamables(a_stream)) {
        return false;
    }
    if (visibilityInterpolator) {
        visibilityInterpolator->RegisterStreamables(a_stream);
    }
    return true;
}

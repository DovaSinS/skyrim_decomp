// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xf9b6d0 NiPSysEmitterCtlr::ResetTimeExtrema
// Adapted bodies: TestBit (header), momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422, CC0-1.0
#include "NiPSysEmitterCtlr_f9b6d0.h"

void NiPSysEmitterCtlr::ResetTimeExtrema()
{
    if (!TestBit(flags, 5)) {
        m_spControllerInterpolator->GetActiveTimeRange(loKeyTime, hiKeyTime);
        float beginKeyTime;
        float endKeyTime;
        visibilityInterpolator->GetActiveTimeRange(beginKeyTime, endKeyTime);
        if (!(beginKeyTime >= loKeyTime)) {
            loKeyTime = beginKeyTime;
        }
        if (endKeyTime > hiKeyTime) {
            hiKeyTime = endKeyTime;
        }
    }
}

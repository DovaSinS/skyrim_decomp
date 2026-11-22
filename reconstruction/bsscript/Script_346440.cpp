// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x346440 Script::ClearOptimizations
// Adapted bodies: none
#include "Script_346440.h"

void Script::ClearOptimizations()
{
    g_optimizedCode = nullptr;
    g_optimizedData = nullptr;
    g_optimizedIndex = -1;
    g_optimizedOwner = nullptr;
}

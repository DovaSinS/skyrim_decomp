// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x1a0130 TES::ResetGridPositions
// Adapted bodies: none
#include "TES_1a0130.h"

void TES::ResetGridPositions()
{
    currentGridX = 0x7FFFFFFF;
    currentGridY = 0x7FFFFFFF;
    currentQueuedX = 0x7FFFFFFF;
    currentQueuedY = 0x7FFFFFFF;
    saveGridX = 0x7FFFFFFF;
    saveGridY = 0x7FFFFFFF;
}

// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x1a0180 TES::GetCurrentCell
// Adapted bodies: none
#include "TES_1a0180.h"

// 0x1a0180 TES::GetCurrentCell
TESObjectCELL* TES::GetCurrentCell()
{
    if (interiorCell) {
        return interiorCell;
    }
    if (currentGridX != 0x7FFFFFFF && currentGridY != 0x7FFFFFFF) {
        return GetCellAtGrid(currentGridX, currentGridY);
    }
    return nullptr;
}

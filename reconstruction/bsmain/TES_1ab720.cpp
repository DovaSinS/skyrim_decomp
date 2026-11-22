// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x1ab720 TES::IsExteriorCellInBuffer
// Adapted bodies: none
#include "TES_1ab720.h"

// 0x1ab720 TES::IsExteriorCellInBuffer
bool TES::IsExteriorCellInBuffer(TESObjectCELL* a_cell)
{
    for (std::uint32_t i = 0; i < iTempExteriorBufferSize; ++i) {
        if (exteriorBuffer[i] == a_cell) {
            return true;
        }
    }
    return false;
}

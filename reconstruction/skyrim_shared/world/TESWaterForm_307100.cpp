// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x307100 TESWaterForm::GetNoisePathBySlot
// Adapted bodies: none
#include "TESWaterForm_307100.h"

const char* TESWaterForm::GetNoisePathBySlot(std::uint32_t index)
{
    switch (index) {
    case 0:
        return noiseTextureName0;
    case 1:
        return noiseTextureName1;
    case 2:
        return noiseTextureName2;
    case 3:
        return noiseTextureName3;
    default:
        return nullptr;
    }
}

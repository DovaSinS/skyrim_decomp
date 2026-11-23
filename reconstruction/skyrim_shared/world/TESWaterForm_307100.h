// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// TESWaterForm, TESWaterForm::GetNoisePathBySlot, noiseTextureName, unk00: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class TESWaterForm
{
public:
    const char* GetNoisePathBySlot(std::uint32_t index);  // compared: 0x307100

    std::uint8_t unk00[0x80];
    const char* noiseTextureName0;
    std::uint8_t unk88[8];
    const char* noiseTextureName1;
    std::uint8_t unk98[8];
    const char* noiseTextureName2;
    std::uint8_t unkA8[8];
    const char* noiseTextureName3;
};

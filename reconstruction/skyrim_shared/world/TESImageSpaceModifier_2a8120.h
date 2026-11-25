// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// TESImageSpaceModifier::InitializeData: CRASHLOGGER_PDB(59818@2026.10.24); name only
// TESImageSpaceModifier, ImageSpaceModifierData and their members: STANDIN GUESS(low); offsets from the listing
#pragma once

#include <cstdint>
#include <cstddef>

// ZeroBlock: GUESS(low); stands for the CRT memset the target calls. It is declared as an ordinary
// external function so the compiler does not drop the explicit zero stores that follow it.
void* ZeroBlock(void* a_dest, int a_value, std::size_t a_size);

struct ImageSpaceModifierData
{
    std::uint8_t unk00[4];
    float unk04;               // 04 (0x24 in the owner)
    std::uint8_t unk08[0xC4];
    float unkCC;               // CC (0xEC in the owner)
    float unkD0;               // D0 (0xF0 in the owner)
    std::uint8_t unkD4[0xE0 - 0xD4];
    std::uint8_t unkE0;        // E0 (0x100 in the owner)
    std::uint8_t unkE1;        // E1
    std::uint8_t unkE2[0xF4 - 0xE2];
};
static_assert(sizeof(ImageSpaceModifierData) == 0xF4, "data size");

class TESImageSpaceModifier
{
public:
    void InitializeData();  // compared: 0x2a8120

    std::uint8_t unk00[0x20];
    ImageSpaceModifierData data;  // 20
};
static_assert(offsetof(TESImageSpaceModifier, data) == 0x20, "data offset");

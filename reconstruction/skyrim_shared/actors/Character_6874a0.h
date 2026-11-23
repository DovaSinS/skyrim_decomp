// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Character: STANDIN GUESS(low); a view of the members used, from offsets
// Character::Function6874a0: CRASHLOGGER_PDB(59818@2026.10.24)
// Character::unk1f8: GUESS(low); a pointer member read as a struct with one float
#pragma once

#include <cstdint>
#include <cstddef>

struct Character_6874a0_Target
{
    std::uint8_t pad00[0x14c];
    float unk14c;
};

class Character
{
public:
    float Function6874a0();  // compared: 0x6874a0

    std::uint8_t pad00[0x1f8];
    Character_6874a0_Target* unk1f8;
};

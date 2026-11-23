// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Character, Character::Function6a03b0: GUESS(low)
// Character::unk1F8, Character_Obj1F8, TestBit: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Character_Obj1F8
{
    std::uint8_t pad00[0x108];
    std::uint32_t flags;
};

class Character
{
public:
    bool Function6a03b0();  // compared: 0x6a03b0

    std::uint8_t pad00[0x1F8];
    Character_Obj1F8* unk1F8;
};

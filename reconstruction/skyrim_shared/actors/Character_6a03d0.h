// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Character, Character::Function6a03d0: GUESS(low)
// Character_Arg, Character_Arg::unk40, Character_Form40, TestBit: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Character_Form40
{
    std::uint8_t pad00[0x10];
    std::uint32_t flags;
    std::uint8_t pad14[0x1A - 0x14];
    std::uint8_t formType;
};

struct Character_Arg
{
    std::uint8_t pad00[0x40];
    Character_Form40* unk40;
};

class Character
{
public:
    bool Function6a03d0(Character_Arg* a_arg);  // compared: 0x6a03d0
};

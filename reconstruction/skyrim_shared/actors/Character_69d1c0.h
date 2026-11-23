// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Character, Character::Function69d1c0: GUESS(low)
// Character::unkB8, Character_SubB8: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Character_SubB8
{
    virtual void unk00();
    virtual float unk01(std::uint32_t a_arg);
};

class Character
{
public:
    std::int32_t Function69d1c0();  // compared: 0x69d1c0

    std::uint8_t pad00[0xB8];
    Character_SubB8 unkB8;
};

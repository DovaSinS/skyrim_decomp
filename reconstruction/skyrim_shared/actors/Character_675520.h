// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Character, Character::Function675520, Holder, Holder::unk137: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Holder
{
    uint8_t pad00[0x137];
    uint8_t unk137;
};

class Character
{
public:
    int Function675520();
    uint8_t pad00[0xF8];
    Holder* unkF8;
};

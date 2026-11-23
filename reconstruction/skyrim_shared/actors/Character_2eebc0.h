// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Character, Character::Function2eebc0, Inner::Get: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Inner
{
    float Get();
};

class Character
{
public:
    float Function2eebc0();
    uint8_t pad00[0x40];
    Inner* unk40;
};

// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Character, Character::Function6a0380: GUESS(low)
// Character::unk204: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Character
{
public:
    void Function6a0380(bool a_set);  // compared: 0x6a0380

    std::uint8_t pad00[0x204];
    std::uint32_t unk204;
};

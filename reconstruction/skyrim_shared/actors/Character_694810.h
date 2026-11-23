// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Character, Character::Function694810: GUESS(low)
// Character::unkF8, ActorProcess, ActorProcess::Function6f7190: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct ActorProcess
{
    bool Function6f7190();
};

class Character
{
public:
    bool Function694810();  // compared: 0x694810

    std::uint8_t pad00[0xF8];
    ActorProcess* unkF8;
};

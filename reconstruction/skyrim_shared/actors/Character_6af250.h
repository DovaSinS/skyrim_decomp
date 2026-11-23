// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Character, Character::Function6af250, ProcessData, ProcessData::unk137: GUESS(low)
#pragma once

#include <cstdint>

class ProcessData
{
public:
    char pad000[0x137];
    std::uint8_t unk137;  // 0x137
};

class Character
{
public:
    int Function6af250();  // compared: 0x6af250

    char pad000[0xF8];
    ProcessData* process;  // 0xF8
};

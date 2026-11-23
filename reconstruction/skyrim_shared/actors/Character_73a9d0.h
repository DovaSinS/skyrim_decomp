// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Character, Character::Function73a9d0, ProcessData, ProcessData::flags108: GUESS(low)
#pragma once

#include <cstdint>

class ProcessData
{
public:
    char pad000[0x108];
    std::uint32_t flags108;  // 0x108
};

class Character
{
public:
    bool Function73a9d0();  // compared: 0x73a9d0

    char pad000[0x1F8];
    ProcessData* data;  // 0x1F8
};

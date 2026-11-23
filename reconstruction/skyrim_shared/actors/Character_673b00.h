// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: momusdigital/f3_decomp@f5bac1b src/f3staging/f3blk_004e0000_o2.cpp:49422 (TestBit shape; helper written from the project cookbook pattern)
// Character, Character::Function673b00, TestBit, Data: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Data
{
    uint8_t pad00[0x108];
    uint32_t unk108;
};

// TestBit: a flag-word bit test by bit index, taking the word by value.
inline bool TestBit(uint32_t a_flags, uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

class Character
{
public:
    bool Function673b00();
    uint8_t pad00[0x1f8];
    Data* unk1F8;
};

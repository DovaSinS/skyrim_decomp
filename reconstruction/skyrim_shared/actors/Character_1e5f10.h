// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Character: STANDIN GUESS(low); a view of the form header only
// Character::Function1e5f10: GUESS(low)
// flags10: GUESS(low); the flag word at offset 0x10
// TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
// Character::unk50: GUESS(low); virtual slot 10, called with true after the flag changes
#pragma once

#include <cstdint>
#include <cstddef>

inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

class Character
{
public:
    virtual void unk00();
    virtual void unk08();
    virtual void unk10();
    virtual void unk18();
    virtual void unk20();
    virtual void unk28();
    virtual void unk30();
    virtual void unk38();
    virtual void unk40();
    virtual void unk48();
    virtual void unk50(std::uint32_t a_arg);

    void Function1e5f10(bool a_set);  // compared: 0x1e5f10

    std::uint64_t pad08;
    std::uint32_t flags10;
};

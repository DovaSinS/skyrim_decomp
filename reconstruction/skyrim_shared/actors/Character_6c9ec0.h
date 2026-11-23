// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Character: STANDIN GUESS(low); a view of the members used, from offsets
// Character::Function6c9ec0: CRASHLOGGER_PDB(59818@2026.10.24)
// SaveLoadView gBGSSaveLoadGame unk340: GUESS(low); the pointer is the one NG reads for the save-load manager, data at 0x3223e18; the manager view holds one flag word
// unk160 LinkedObject LinkedObject::Function560bf0: GUESS(low); a pointer member at 0x160 and the method called on it
// TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
#pragma once

#include <cstdint>
#include <cstddef>

inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

class SaveLoadView
{
public:
    std::uint8_t unk00[0x340];
    std::uint32_t unk340;
};

extern SaveLoadView* gBGSSaveLoadGame;

class LinkedObject
{
public:
    void Function560bf0(void* a_arg1, void* a_arg2);
};

class Character
{
public:
    void Function6c9ec0(void* a_arg1, void* a_arg2);  // compared: 0x6c9ec0

    std::uint8_t pad00[0x160];
    LinkedObject* unk160;
};

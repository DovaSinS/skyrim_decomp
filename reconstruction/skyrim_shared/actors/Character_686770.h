// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Character: STANDIN GUESS(low); a view of the members used, from offsets
// Character::Function686770: CRASHLOGGER_PDB(59818@2026.10.24)
// ExtraDataList: STANDIN CRASHLOGGER_PDB(59818@2026.10.24); only the type name, an embedded member at 0x70
// ExtraDataList::Function1702b0: GUESS(low); a lookup returning a record with a byte at 0x10
// ExtraByteRecord TargetRace: GUESS(low); stand-in records read through pointers
// unk108 unk1f8: GUESS(low); a flag word at 0x108 of the race-like record and a pointer member at 0x1f8
// TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
#pragma once

#include <cstdint>
#include <cstddef>

inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

struct ExtraByteRecord
{
    std::uint8_t pad00[0x10];
    bool unk10;
};

struct TargetRace
{
    std::uint8_t pad00[0x108];
    std::uint32_t unk108;
};

class ExtraDataList
{
public:
    ExtraByteRecord* Function1702b0();
};

class Character
{
public:
    bool Function686770();  // compared: 0x686770

    std::uint8_t pad00[0x70];
    ExtraDataList extraList;
    std::uint8_t pad78[0x1f8 - 0x78];
    TargetRace* unk1f8;
};

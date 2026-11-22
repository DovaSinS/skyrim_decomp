// Source exposure: mixed (community headers; compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// Character: GUESS(low); the class is the placeholder owner
// GetEssential: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb); the PDB class is Actor, this unit keeps the placeholder class
// boolFlags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); Actor::BOOL_FLAGS word, bit 18 kEssential, bit 19 kProtected
// a_includeProtected: GUESS(low); the unnamed bool parameter
#pragma once

#include <cstdint>
#include <cstddef>

// IsFlagBitSet: GUESS(low); a flag-word bit test by bit index, taking the word by value.
inline bool IsFlagBitSet(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

class Character
{
public:
    bool GetEssential(bool a_includeProtected) const;  // compared: 0x674000

    std::uint8_t unk00[0x204];
    std::uint32_t boolFlags;
};

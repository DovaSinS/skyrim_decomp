// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectREFR, TESBaseStand, baseObject, formType, IsUsableLight, TestBit: GUESS(low); stand-in view, layout only as far as the compared code reads it.
#pragma once

#include <cstdint>
#include <cstddef>

// formFlags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NG calls the TESForm field formFlags.

struct TESBaseStand
{
    std::uint8_t unk00[0x1A];
    std::uint8_t formType;  // 1A
};

class TESObjectREFR
{
public:
    std::uint8_t unk00[0x10];
    std::uint32_t formFlags;     // 10
    std::uint8_t unk14[0x2C];
    TESBaseStand* baseObject;    // 40
    bool IsUsableLight() const;
};

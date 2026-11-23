// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectREFR, CheckFlagByKind: GUESS(low); stand-in view, layout only as far as the compared code reads it.
// formFlags, formID, formType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NG's TESForm field names.
#pragma once

#include <cstdint>
#include <cstddef>

class TESObjectREFR
{
public:
    std::uint8_t unk00[0x10];
    std::uint32_t formFlags;  // 10
    std::uint32_t formID;     // 14
    std::uint8_t unk18[2];
    std::uint8_t formType;    // 1A
    bool CheckFlagByKind() const;
};

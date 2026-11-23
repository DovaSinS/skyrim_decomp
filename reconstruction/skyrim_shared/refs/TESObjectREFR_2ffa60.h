// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectREFR, TESBoundObject, TESObjectREFR::Function2ffa60, TESObjectREFR::objectReference: GUESS(low)
// TESForm::formFlags, TESForm::formType, FormType: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); offsets read from the listing
#pragma once

#include <cstdint>
#include <cstddef>

class TESBoundObject
{
public:
    unsigned char pad00[0x1A];
    std::uint8_t formType;  // 1A
    unsigned char pad1B[0xE4 - 0x1B];
    std::uint32_t furnitureFlags;  // E4
};

class TESObjectREFR
{
public:
    bool Function2ffa60();

    unsigned char pad00[0x40];
    TESBoundObject* objectReference;  // 40
};

// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectREFR, TESBoundObject, TESObjectREFR::Function2f3830, TESObjectREFR::objectReference, TESBoundObject::unk38, TESBoundObject::unkB9, TESObjectREFR::IsTemporaryFormID: GUESS(low)
// TESForm::formFlags, TESForm::formType: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the form-type values are read from the listing

#pragma once

#include <cstdint>
#include <cstddef>

class TESBoundObject
{
public:
    unsigned char pad00[0x1A];
    std::uint8_t formType;  // 1A
    unsigned char pad1B[0x38 - 0x1B];
    std::uint32_t unk38;  // 38
    unsigned char pad3C[0xB9 - 0x3C];
    std::int8_t unkB9;  // B9
};

class TESObjectREFR
{
public:
    bool IsTemporaryFormID();
    bool Function2f3830();

    unsigned char pad00[0x10];
    std::uint32_t formFlags;  // 10
    unsigned char pad14[0x2C];
    TESBoundObject* objectReference;  // 40
};

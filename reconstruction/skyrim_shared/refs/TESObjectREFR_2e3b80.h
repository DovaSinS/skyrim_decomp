// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectREFR, TESBoundObject, TESObjectREFR::Function2e3b80, TESObjectREFR::objectReference, ExtraDataList::GetLightData, Leaf14ecc70::Invoke: GUESS(low)
// TESForm::formFlags, TESForm::formType: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); offsets and prototypes read from the listing
#pragma once

#include <cstdint>
#include <cstddef>

class TESBoundObject
{
public:
    unsigned char pad00[0x1A];
    std::uint8_t formType;  // 1A
};

class ExtraDataList
{
public:
    void* GetLightData();
};

struct Leaf14ecc70
{
    static void Invoke();
};

class TESObjectREFR
{
public:
    void Function2e3b80(bool a_set);

    unsigned char pad00[0x10];
    std::uint32_t formFlags;  // 10
    unsigned char pad14[0x2C];
    TESBoundObject* objectReference;  // 40
    unsigned char pad48[0x28];
    ExtraDataList extraList;  // 70
};

// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectREFR, TESBoundObject, TESObjectREFR::Function2f0b40, TESObjectREFR::objectReference: GUESS(low)
// TESForm::formFlags, TESForm::formType, FormType: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); offsets read from the listing
#pragma once

#include <cstdint>
#include <cstddef>

// ExtraDataList::GetLeveledNPC: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission); prototype read from the listing
class ExtraDataList
{
public:
    void* GetLeveledNPC();
};

class TESObjectREFR
{
public:
    void* Function2f0b40();

    unsigned char pad00[0x40];
    void* objectReference;  // 40
    unsigned char pad48[0x28];
    ExtraDataList extraList;  // 70
};

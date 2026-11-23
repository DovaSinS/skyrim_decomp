// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectREFR, TESObjectREFR::Function302bc0: GUESS(low)
// TESObjectREFR::extraList, ExtraDataList: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); offset 0x70
// ExtraDataList::Function169100: CRASHLOGGER_PDB(59818@2026.10.24); float result is read from the listing
#pragma once

#include <cstdint>
#include <cstddef>

class ExtraDataList
{
public:
    float Function169100();
};

class TESObjectREFR
{
public:
    bool Function302bc0();

    unsigned char pad00[0x70];
    ExtraDataList extraList;
};

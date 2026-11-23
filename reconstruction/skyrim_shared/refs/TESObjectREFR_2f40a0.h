// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectREFR, TESObjectREFR::Function2f40a0: GUESS(low)
// TESObjectREFR::data, NiPoint3, OBJ_REFR, OBJ_REFR::angle, OBJ_REFR::location: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); offsets read from the listing
#pragma once

#include <cstdint>
#include <cstddef>

struct NiPoint3
{
    float x;  // 00
    float y;  // 04
    float z;  // 08
};

struct OBJ_REFR
{
    unsigned char pad00[0x8];
    NiPoint3 angle;  // 08
    NiPoint3 location;  // 14
};

class TESObjectREFR
{
public:
    float Function2f40a0(const NiPoint3& a_pos);

    unsigned char pad00[0x40];
    OBJ_REFR data;  // 40
};

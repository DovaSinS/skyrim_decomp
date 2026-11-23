// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Character: STANDIN GUESS(low); a view of the members used, from offsets
// Character::Function303b60: CRASHLOGGER_PDB(59818@2026.10.24)
// ExtraDataList: STANDIN CRASHLOGGER_PDB(59818@2026.10.24); only the type name, an embedded member at 0x70
// ExtraDataList::Function164c50: CRASHLOGGER_PDB(59818@2026.10.24); return type guessed from the call site
// NiPoint3: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// StartingExtra: GUESS(low); the record whose point lives at offset 8
#pragma once

#include <cstdint>
#include <cstddef>

struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct StartingExtra
{
    std::uint8_t pad00[8];
    NiPoint3 point;
};

class ExtraDataList
{
public:
    StartingExtra* Function164c50();
};

class Character
{
public:
    NiPoint3* Function303b60();  // compared: 0x303b60

    std::uint8_t pad00[0x54];
    NiPoint3 unk54;
    std::uint8_t pad60[0x10];
    ExtraDataList extraList;
};

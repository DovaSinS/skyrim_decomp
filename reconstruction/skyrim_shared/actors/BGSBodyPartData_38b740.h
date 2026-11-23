// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSBodyPartData, BGSBodyPartData::parts, BGSBodyPart, BGSBodyPart::data, PART_DATA, PART_DATA::actorValue: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; names and offsets only, the actor value is read as a signed byte
// BGSBodyPartData::sub_14032D170: CRASHLOGGER_PDB(59818@2026.10.24); placeholder name of the compared function
// BGSBodyPartData::GetPartByActorValue: GUESS(low)
// unk00, unk08, unk78, unk80: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct PART_DATA
{
    unsigned char unk00[7];
    std::int8_t actorValue;
};

class BGSBodyPart
{
public:
    unsigned char unk00[0x78];
    PART_DATA data;
};
static_assert(offsetof(BGSBodyPart, data) == 0x78, "part data offset");

class BGSBodyPartData
{
public:
    BGSBodyPart* GetPartByActorValue(std::int32_t a_actorValue);

    unsigned char unk00[0x50];
    BGSBodyPart* parts[6];
};
static_assert(offsetof(BGSBodyPartData, parts) == 0x50, "parts offset");

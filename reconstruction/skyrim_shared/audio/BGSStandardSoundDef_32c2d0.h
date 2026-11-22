// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSStandardSoundDef, BGSStandardSoundDef::conditions, BGSStandardSoundDef::outputModel: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSStandardSoundDef::Unk_02: CRASHLOGGER_PDB(59818@2026.10.24); the parameter is read from the listing
// BGSSoundOutput, BGSSoundOutput::data, BGSSoundOutput::attenuation: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// DynamicAttenuationCharacteristics, DynamicAttenuationCharacteristics::data, DataType, maxDistance: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESCondition, TESCondition::IsTrue: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectREFR: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); opaque here
// playerSingleton: GUESS(low); the player reference global, read as the base reference
// BGSStandardSoundDef::unk01, BGSStandardSoundDef::unk08: GUESS(low); slot placeholder and unused region
// BGSSoundOutput::unk00, ::unk29, DynamicAttenuationCharacteristics::unk00: GUESS(low); unused regions
#pragma once

#include <cstdint>
#include <cstddef>

class TESObjectREFR;

class TESCondition
{
public:
    bool IsTrue(TESObjectREFR* actionRef, TESObjectREFR* targetRef) const;
};

extern TESObjectREFR* playerSingleton;

struct DynamicAttenuationCharacteristics
{
    unsigned char unk00[0x8];
    float minDistance;  // 08
    float maxDistance;  // 0C
};

class BGSSoundOutput
{
public:
    unsigned char unk00[0x28];
    std::uint8_t flags;                                    // 28
    unsigned char unk29[7];
    DynamicAttenuationCharacteristics* attenuation;        // 30
};

class BGSStandardSoundDef
{
public:
    virtual ~BGSStandardSoundDef();      // 00
    virtual void unk01();                // 01
    virtual bool Unk_02(float distance); // 02

    unsigned char unk08[0x38];
    TESCondition* conditions;            // 40
    BGSSoundOutput* outputModel;         // 48
};

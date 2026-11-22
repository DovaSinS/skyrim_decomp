// Source exposure: community-headers (names, layout), binary-analysis (offsets and slots from the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// Recipe: reconstruction/recipes/o2-fpfast.json
// Actor: GUESS(low); the class is the placeholder owner
// RestoreActorValue: CRASHLOGGER_PDB(59818@2026.10.24)
// ActorValueOwner, ActorValueList, ActorValueInfo, actorValues, flags, RestoreActorValue, GetActorValueModifier, AsActorValueOwner: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; ActorValueOwner sits at 0xB8 in this build, the three classes are stand-ins with only the members the body reads
// g_actorValueList, unk00 to unk05: GUESS(low); the singleton pointer global, a bit helper and slot placeholders
// header-gap Actor: stand-in view with only GetActorValueModifier and the ActorValueOwner subobject address
// TestBit: GUESS(low); a one-line flag-bit helper taking the word by value, the shape also appears in the sibling below
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
#pragma once

#include <cstdint>
#include <cstddef>

class ActorValueOwner
{
public:
    virtual ~ActorValueOwner();
    virtual float unk01(std::int32_t a_av);
    virtual float unk02(std::int32_t a_av);
    virtual float unk03(std::int32_t a_av);
    virtual void unk04(std::int32_t a_av, float a_value);
    virtual void unk05(std::int32_t a_av, float a_value);
    virtual void RestoreActorValue(std::int32_t a_modifier, std::int32_t a_av, float a_value);  // 06
};

struct ActorValueInfo
{
    std::uint8_t pad00[0x60];
    std::uint32_t flags;
};

struct ActorValueList
{
    std::uint64_t pad00;
    ActorValueInfo* actorValues[1];
};

extern ActorValueList* g_actorValueList;

inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

class Actor
{
public:
    float GetActorValueModifier(std::int32_t a_modifier, std::int32_t a_value) const;  // compared elsewhere: 0x6c5440
    void RestoreActorValue(std::int32_t a_av, float a_delta);                          // compared: 0x6c47f0

    ActorValueOwner* AsActorValueOwner()
    {
        return reinterpret_cast<ActorValueOwner*>(reinterpret_cast<std::uint8_t*>(this) + 0xB8);
    }
};

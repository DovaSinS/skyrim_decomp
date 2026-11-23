// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Character: STANDIN GUESS(low); a view of the members used, from offsets
// Character::Function6739d0: CRASHLOGGER_PDB(59818@2026.10.24)
// ActorValueOwner ActorValueOwner::GetActorValue: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); virtual slot 1, embedded at 0xb8
// ActorValue ActorValue::kWaterBreathing: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); value 57
#pragma once

#include <cstdint>
#include <cstddef>

#include <cmath>

enum class ActorValue : std::int32_t
{
    kWaterBreathing = 57
};

class ActorValueOwner
{
public:
    virtual void unk00();
    virtual float GetActorValue(ActorValue a_akValue);
};

class Character
{
public:
    bool Function6739d0();  // compared: 0x6739d0

    std::uint8_t pad00[0xb8];
    ActorValueOwner actorValueOwner;
};

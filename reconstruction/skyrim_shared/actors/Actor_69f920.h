// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Actor, currentProcess, BGSPerk: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function69f920: GUESS(low)
// ActorProcess: GUESS(low); the placeholder owner, NG calls the class AIProcess
// ActorProcess::HasPerk: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission); callee defined in its own unit
// pad08: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct BGSPerk;
class Actor;

class ActorProcess
{
public:
    std::uint8_t HasPerk(Actor* a_actor, BGSPerk* a_perk);
};

class Actor
{
public:
    virtual ~Actor();

    std::uint8_t Function69f920(BGSPerk* a_perk);

    std::uint8_t pad08[0xF0];
    ActorProcess* currentProcess;  // 0xf8
};
static_assert(offsetof(Actor, currentProcess) == 0xf8, "Actor::currentProcess offset");

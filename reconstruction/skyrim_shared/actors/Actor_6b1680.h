// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Actor, currentProcess: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function6b1680, pad08, ActorProcess, Function700eb0, gActorProcessFlag: GUESS(low); ActorProcess is the placeholder owner, NG calls the class AIProcess
#pragma once

#include <cstdint>
#include <cstddef>

class ActorProcess
{
public:
    bool Function700eb0();  // callee at 0x700eb0, defined in its own unit
};

extern bool gActorProcessFlag;  // data at 0x20b6bb0

class Actor
{
public:
    virtual ~Actor();

    bool Function6b1680();

    std::uint8_t pad08[0xF0];
    ActorProcess* currentProcess;  // 0xf8
};
static_assert(offsetof(Actor, currentProcess) == 0xf8, "Actor::currentProcess offset");

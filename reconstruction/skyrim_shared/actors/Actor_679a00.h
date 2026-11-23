// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Actor, Actor::Function679a00: GUESS(low)
// ActorValueOwner, ActorValueOwner::GetActorValue, ActorValueOwner::GetPermanentActorValue: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

class ActorValueOwner
{
public:
    virtual ~ActorValueOwner();
    virtual float GetActorValue(int a_akValue);  // slot 1
    virtual float GetPermanentActorValue(int a_akValue);  // slot 2
};

class Actor
{
public:
    float Function679a00(int a_akValue);  // compared: 0x679a00

    char pad000[0xB8];
    ActorValueOwner avOwner;  // 0xB8
};

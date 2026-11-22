// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Actor, Actor::IsMoving: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// movementController, MovementControllerNPC: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); stand-in views, the controller offset is this build's
// MovementKey, MotionGate, kMotionGateKey, unk03, unk01: GUESS(low); the controller hands out a gate by key and the gate's second slot yields a speed
#pragma once

#include <cstdint>
#include <cstddef>

struct MovementKey
{
    std::uint32_t unk00;
};

extern const MovementKey kMotionGateKey;

class MotionGate
{
public:
    virtual void unk00();
    virtual float unk01() const;
};

class MovementControllerNPC
{
public:
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual MotionGate* unk03(const MovementKey& a_key);
};

class Actor
{
public:
    bool IsMoving() const;  // compared: 0x6aefa0

    std::uint8_t unk00[0x150];
    MovementControllerNPC* movementController;
};

// Source exposure: mixed (community headers; compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// Character: GUESS(low); the class is the placeholder owner
// GetTurning: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb); the PDB class is Actor, this unit keeps the placeholder class
// movementController, MovementControllerNPC: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); stand-in views, the controller offset is this build's
// MovementKey, MotionGate, MotionData, kMotionGateKey, unk03, unk01, unk00, angularSpeed: GUESS(low); the controller hands out a gate by key and the gate yields a record with a float at 0x8
#pragma once

#include <cstdint>
#include <cstddef>

struct MovementKey
{
    std::uint32_t unk00;
};

extern const MovementKey kMotionGateKey;

class MotionData
{
public:
    std::uint8_t unk00[0x8];
    float angularSpeed;
};

class MotionGate
{
public:
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual MotionData* unk03();
};

class MovementControllerNPC
{
public:
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual MotionGate* unk03(const MovementKey& a_key);
};

class Character
{
public:
    bool GetTurning() const;  // compared: 0x6aeff0

    std::uint8_t unk00[0x150];
    MovementControllerNPC* movementController;
};

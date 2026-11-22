// Source exposure: mixed (community headers; compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// Character: GUESS(low); the class is the placeholder owner
// GetLookAtTarget: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb); the PDB class is Actor, this unit keeps the placeholder class
// NiPoint3, x, y, z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); stand-in point
// movementController, MovementControllerNPC: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); stand-in views, the controller offset is this build's
// MovementKey, MotionGate, LookAtRecord, kLookAtGateKey, unk03, unk01, unk00, state, point: GUESS(low); the controller hands out a gate by key and the gate yields a record with a state word and a point
#pragma once

#include <cstdint>
#include <cstddef>

struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct MovementKey
{
    std::uint32_t unk00;
};

extern const MovementKey kLookAtGateKey;

class LookAtRecord
{
public:
    std::uint32_t state;
    NiPoint3 point;
};

class MotionGate
{
public:
    virtual void unk00();
    virtual LookAtRecord* unk01();
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
    bool GetLookAtTarget(NiPoint3& a_target) const;  // compared: 0x6a6c20

    std::uint8_t unk00[0x150];
    MovementControllerNPC* movementController;
};

// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Actor, Actor::Functiona00c10, Actor::Function6a51b0, ControlsHolder, ControlsHolder::unk15: GUESS(low)
// Actor::Functiona00c10: CRASHLOGGER_PDB(59818@2026.10.24); the name there is papyrus__Actor::GetPlayerControls_14094B1A0
#pragma once

#include <cstdint>

class ControlsHolder
{
public:
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual void unk07();
    virtual void unk08();
    virtual void unk09();
    virtual void unk10();
    virtual void unk11();
    virtual void unk12();
    virtual void unk13();
    virtual void unk14();
    virtual bool unk15();  // slot 15
};

class Actor
{
public:
    static bool Functiona00c10(void* a_vm, std::uint32_t a_stackId, Actor* a_actor);  // compared: 0xa00c10
    ControlsHolder** Function6a51b0();  // callee at 0x6a51b0
};

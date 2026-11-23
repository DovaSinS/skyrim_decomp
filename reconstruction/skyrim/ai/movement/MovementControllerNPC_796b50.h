// Source exposure: mixed (CrashLogger and FO4 layout names; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// MovementControllerNPC: CRASHLOGGER_PDB(59818@2026.10.24)
// Unk_11: CRASHLOGGER_PDB(59818@2026.10.24); the inventory name for this address, the PDB records Func17
// MovementSubObject, Slot04, Slot06, subObject, flag1C4, TlsScopedValue, gTlsValue, unk00 to unk127, unk1C5: GUESS(low); the embedded object at 0x128 has no recorded name
#pragma once

#include <cstdint>
#include <cstddef>

class MovementSubObject
{
public:
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void Slot04();       // 04
    virtual void unk05();
    virtual bool Slot06();       // 06
};

class MovementControllerNPC
{
public:
    void Unk_11(std::uint8_t a_flag);

    std::uint8_t unk00[0x128];
    MovementSubObject subObject;  // 0x128
    std::uint8_t unk130[0x94];
    std::uint8_t flag1C4;         // 0x1C4
};
static_assert(offsetof(MovementControllerNPC, subObject) == 0x128, "subObject offset");
static_assert(offsetof(MovementControllerNPC, flag1C4) == 0x1C4, "flag1C4 offset");

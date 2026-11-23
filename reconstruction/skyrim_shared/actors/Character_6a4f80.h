// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Character: STANDIN GUESS(low); a view of the members used, from offsets
// Character::Function6a4f80: CRASHLOGGER_PDB(59818@2026.10.24)
// unkC8 holder150: GUESS(low); a state word at 0xc8 and a pointer member at 0x150
// ControllerHolder ControllerInterface InterfaceId interfaceId324f0b0: GUESS(low); stand-ins for the objects the body reaches
// ControllerHolder::unk18 ControllerInterface::unk30: GUESS(low); virtual slot 3 looks an interface up by id, slot 6 is a bool query
#pragma once

#include <cstdint>
#include <cstddef>

struct InterfaceId;
extern const InterfaceId interfaceId324f0b0;

class ControllerInterface
{
public:
    virtual void unk00();
    virtual void unk08();
    virtual void unk10();
    virtual void unk18();
    virtual void unk20();
    virtual void unk28();
    virtual bool unk30();
};

class ControllerHolder
{
public:
    virtual void unk00();
    virtual void unk08();
    virtual void unk10();
    virtual ControllerInterface* unk18(const InterfaceId* a_id);
};

class Character
{
public:
    bool Function6a4f80();  // compared: 0x6a4f80

    std::uint8_t pad00[0xc8];
    std::uint32_t unkC8;
    std::uint8_t padCC[0x150 - 0xcc];
    ControllerHolder* holder150;
};

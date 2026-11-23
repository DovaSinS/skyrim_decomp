// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// MissileProjectile, MissileProjectile::Function7fa440, SlotOwner, GetSlotValue, owner: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class SlotOwner
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
    virtual void unk15();
    virtual void unk16();
    virtual void unk17();
    virtual void unk18();
    virtual void unk19();
    virtual void unk20();
    virtual void unk21();
    virtual void unk22();
    virtual void unk23();
    virtual void unk24();
    virtual void unk25();
    virtual void unk26();
    virtual void unk27();
    virtual void unk28();
    virtual void unk29();
    virtual void unk30();
    virtual void unk31();
    virtual void unk32();
    virtual void unk33();
    virtual void unk34();
    virtual void unk35();
    virtual void unk36();
    virtual void unk37();
    virtual void unk38();
    virtual void* GetSlotValue();
};

class MissileProjectile
{
public:
    bool Function7fa440();  // compared: 0x7fa440

    std::uint8_t unk00[0xE8];
    SlotOwner* owner;
};

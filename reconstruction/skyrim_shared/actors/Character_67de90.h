// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Character, Character::Function67de90: GUESS(low)
// Character::unkC0, Character::unk204, Character_SubC0: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Character_SubC0
{
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
    virtual void unk0A();
    virtual void unk0B();
    virtual void unk0C();
    virtual void unk0D();
    virtual void unk0E();
    virtual void unk0F();
    virtual void unk10();
    virtual void unk11();
    virtual void unk12();
    virtual void unk13();
    virtual void unk14();
    virtual void unk15(std::uint32_t a_arg);

    std::uint32_t flags;
};

class Character
{
public:
    void Function67de90();  // compared: 0x67de90

    std::uint8_t pad00[0xC0];
    Character_SubC0 unkC0;
    std::uint8_t padD0[0x204 - 0xD0];
    std::uint32_t unk204;
};

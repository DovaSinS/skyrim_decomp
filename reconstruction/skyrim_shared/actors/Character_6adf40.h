// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Character, Character::Function6adf40, Interface6adf40, Interface6adf40::unk03, Target6adf40, Target6adf40::unk02, g_type6adf40: GUESS(low)
#pragma once

class Target6adf40
{
public:
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();  // slot 2
};

class Interface6adf40
{
public:
    virtual ~Interface6adf40();
    virtual void unk01();
    virtual void unk02();
    virtual Target6adf40* unk03(const void* a_type);  // slot 3: query by type descriptor
};

extern const char g_type6adf40;

class Character
{
public:
    void Function6adf40();  // compared: 0x6adf40

    char pad000[0x150];
    Interface6adf40* held;  // 0x150
};

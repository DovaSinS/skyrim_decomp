// Source exposure: mixed (community headers; compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// NiObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); constructor, destructor and the 0x10 byte header only
// BSTempEffect::BSTempEffect: CRASHLOGGER_PDB(59818@2026.10.24); tier C: the unit renames the placeholder class to this class
// BSTempEffect, lifetime, pad14, cell, age, initialized, pad25, pad26, effectID, pad2C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; cell is declared void* here instead of TESObjectCELL*
#pragma once

#include <cstdint>

class NiObject
{
public:
    NiObject();
    virtual ~NiObject();

    std::uint32_t refCount;  // 08
    std::uint32_t pad0C;     // 0C
};

class BSTempEffect : public NiObject
{
public:
    BSTempEffect();
    ~BSTempEffect() override;

    float lifetime;          // 10
    std::uint32_t pad14;     // 14
    void* cell;              // 18
    float age;               // 20
    bool initialized;        // 24
    std::uint8_t pad25;      // 25
    std::uint16_t pad26;     // 26
    std::uint32_t effectID;  // 28
    std::uint32_t pad2C;     // 2C
};

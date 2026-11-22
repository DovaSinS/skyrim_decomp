// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiAVObject: GUESS(low); the class is the placeholder owner, its view carries the NiObjectNET base members (the PDB class of GetController)
// GetController: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb)
// NiTimeController, NiRTTI: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); members and slots only as far as the compared function needs
// controllers, next, baseRTTI, GetRTTI: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); controllers at 0x18, next at 0x40, GetRTTI is NiObject slot 2
// unk01, pad00, pad08, pad38: GUESS(low); unrecovered storage and slot placeholders
#pragma once

#include <cstdint>

class NiRTTI
{
public:
    const char* name;
    const NiRTTI* baseRTTI;
};

class NiTimeController
{
public:
    virtual ~NiTimeController();
    virtual void unk01();
    virtual const NiRTTI* GetRTTI() const;

    std::uint8_t pad08[0x38];
    NiTimeController* next;
};

class NiAVObject
{
public:
    NiTimeController* GetController(const NiRTTI* a_rtti) const;  // compared: 0xeeb7a0

    std::uint8_t pad00[0x18];
    NiTimeController* controllers;
};

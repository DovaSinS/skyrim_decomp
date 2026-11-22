// Source exposure: community-headers (names, layout), binary-analysis (offsets and slots from the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// MovementControllerNPC: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Func10: CRASHLOGGER_PDB(59818@2026.10.24); the address suffix of the recorded name is dropped, the slot is 0x0A
// Unk_01 to Unk_09, Unk_03: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NG names the slots Unk_xx, the unit declares them with the parameters the body needs
// IMovementSetSprinting, QClassType: CRASHLOGGER_PDB(59818@2026.10.24); stand-in class, the recorded name is IMovementSetSprinting::QClassType
// ClassType, Sprinting, SetFlag: GUESS(low); stand-in records and a slot name
// header-gap MovementControllerNPC: stand-in view with only the slots the body calls
#pragma once

#include <cstdint>
#include <cstddef>

struct ClassType;

class Sprinting
{
public:
    virtual void unk00();
    virtual void SetFlag(std::uint8_t a_flag);  // 01
};

class IMovementSetSprinting
{
public:
    static const ClassType* QClassType();  // compared elsewhere: 0x79ad20
};

class MovementControllerNPC
{
public:
    virtual ~MovementControllerNPC();                          // 00
    virtual void Unk_01();                                     // 01
    virtual void Unk_02();                                     // 02
    virtual Sprinting* Unk_03(const ClassType* a_classType);   // 03
    virtual void Unk_04();                                     // 04
    virtual void Unk_05();                                     // 05
    virtual void Unk_06();                                     // 06
    virtual void Unk_07();                                     // 07
    virtual void Unk_08();                                     // 08
    virtual void Unk_09();                                     // 09
    virtual void Func10(std::uint8_t a_flag);                  // 0A; compared: 0x7963c0
};

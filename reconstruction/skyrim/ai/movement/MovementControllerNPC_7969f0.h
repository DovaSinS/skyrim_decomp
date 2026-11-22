// Source exposure: community-headers (names, layout), binary-analysis (offsets and slots from the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// MovementControllerNPC, Unk_01 to Unk_0B, Unk_03, unk1C5, IMovementMotionDrivenControl, Unk_04, Unk_06: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NG names the slots Unk_xx and the byte member unk1C5, the sub-object at 0x128 is IMovementMotionDrivenControl; the unit declares only what the body needs
// GetAIDriven: CRASHLOGGER_PDB(59818@2026.10.24); NG names the slot Unk_0D
// ScopedValue, g_scopedValue, saved, Notified, ClassType, kClassType, MotionDriven: GUESS(low); a thread-local scope guard and stand-in records, the thread-local is bound by offset
// header-gap MovementControllerNPC: stand-in view with only the slots and members the body uses
#pragma once

#include <cstdint>
#include <cstddef>

struct ClassType;

extern const ClassType kClassType;
extern __declspec(thread) std::uint32_t g_scopedValue;

class Notified
{
public:
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void Notify();  // 03
};

class MotionDriven
{
public:
    virtual ~MotionDriven();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void Unk_04();                  // 04
    virtual void unk05();
    virtual bool Unk_06();                  // 06
};

class ScopedValue
{
public:
    explicit ScopedValue(std::uint32_t a_value) :
        saved(g_scopedValue)
    {
        g_scopedValue = a_value;
    }

    __forceinline ~ScopedValue()  // scope guard: the cleanup is inlined at every exit and in the unwind path
    {
        g_scopedValue = saved;
    }

    std::uint32_t saved;
};

class MovementControllerNPC
{
public:
    virtual ~MovementControllerNPC();                       // 00
    virtual void Unk_01();                                  // 01
    virtual void Unk_02();                                  // 02
    virtual Notified* Unk_03(const ClassType* a_classType); // 03
    virtual void Unk_04();                                  // 04
    virtual void Unk_05();                                  // 05
    virtual void Unk_06();                                  // 06
    virtual void Unk_07();                                  // 07
    virtual void Unk_08();                                  // 08
    virtual void Unk_09();                                  // 09
    virtual void Unk_0A();                                  // 0A
    virtual void Unk_0B();                                  // 0B
    virtual void Unk_0D();                                  // 0D; compared: 0x7969f0

    std::uint8_t pad08[0x128 - 0x8];
    MotionDriven motionDriven;                              // 128
    std::uint8_t pad130[0x1C5 - 0x130];
    std::uint8_t unk1C5;
};

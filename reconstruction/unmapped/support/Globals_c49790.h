// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// Func00e01710: GUESS(low); placeholder name
// Globals: GUESS(low); placeholder name
#pragma once
#include <new>

struct FinishFlag
{
    int value;
};

struct FinishingFlag
{
    int m_bFinishing;
    FinishingFlag() : m_bFinishing(0)
    {}
};

struct hkFinishMemberE01710
{
    void* m_ptr;
    hkFinishMemberE01710(FinishingFlag flag);
};


struct __declspec(align(16)) hkObjectE01710
{
    virtual ~hkObjectE01710();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    hkFinishMemberE01710 m_member18;
    hkFinishMemberE01710 m_member1c;

    hkObjectE01710(FinishingFlag flag) : m_member18(flag), m_member1c(flag)
    {}
};


struct __declspec(align(16)) FinishedObject
{
    void* vtable;
    int unk04;
    int unk08;
    int unk0c;
    void* secondaryVtable;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    FinishedObject(FinishFlag);
};

struct Globals
{
};

// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); destructor and the 0x10 byte header only
// BSMultiBoundShape, unk10, pad14: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the virtuals before slot 0x2D are placeholders
// BSMultiBoundShape::SetCenter: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); virtual slot 0x2D
// BSMultiBoundShape::CopyMembers: GUESS(low); direct base call at its own address, name follows the FO4 CopyMembers convention
// NiPoint3, NiCloningProcess: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NiPoint3 is plain data here, the process is opaque
// Unk_01 to Unk_2C: GUESS(low); placeholders that put SetCenter at its slot
// CopyMembers, Center, Radius: SYMBOLS(fo4-pdb); the FO4 names are BSMultiBoundSphere's. Tier C: the unit keeps the placeholder class BSMultiBoundAABB, whose header the lint requires

#pragma once

#include <cstdint>

class NiCloningProcess;

struct NiPoint3
{
    float x;
    float y;
    float z;
};

class NiObject
{
public:
    virtual ~NiObject();  // 00

    std::uint32_t refCount;  // 08
    std::uint32_t pad0C;     // 0C
};

class BSMultiBoundShape : public NiObject
{
public:
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void SetCenter(const NiPoint3& a_center);  // 2D
    void CopyMembers(BSMultiBoundShape* a_dest, NiCloningProcess& a_process);

    std::uint32_t unk10;  // 10
    std::uint32_t pad14;  // 14
};

class BSMultiBoundAABB : public BSMultiBoundShape
{
public:
    void CopyMembers(BSMultiBoundAABB* a_dest, NiCloningProcess& a_process);  // compared: 0xfe5250

    NiPoint3 Center;  // 18
    float Radius;     // 24
};

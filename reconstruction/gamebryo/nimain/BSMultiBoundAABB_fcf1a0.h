// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); destructor and the 0x10 byte header only
// BSMultiBoundShape, unk10, pad14: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the virtuals before slot 0x2C are placeholders
// BSMultiBoundShape::GetWithinPoint, BSMultiBoundShape::SetCenter: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); virtual slots 0x2C and 0x2D
// BSMultiBoundAABB, BSMultiBoundAABB::GetWithinPoint: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// center, size, pad18, pad28, pad38, pad3C: CRASHLOGGER_PDB(59818@2026.10.24); layout names from the CrashLogger type, offsets checked against the listing
// NiPoint3: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); plain data here
// Unk_01 to Unk_26: GUESS(low); placeholders that put GetWithinPoint at its slot
// Unk_27, Unk_28, Unk_29, Unk_2A, Unk_2B: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); names as in the community header, bodies unknown
#pragma once

#include <cstdint>

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
    virtual bool GetWithinPoint(const NiPoint3& a_pos);  // 2C
    virtual void SetCenter(const NiPoint3& a_center);    // 2D

    std::uint32_t unk10;  // 10
    std::uint32_t pad14;  // 14
};

class BSMultiBoundAABB : public BSMultiBoundShape
{
public:
    bool GetWithinPoint(const NiPoint3& a_pos) override;  // 2C

    std::uint32_t pad18;  // 18
    NiPoint3 center;      // 1C
    std::uint32_t pad28;  // 28
    NiPoint3 size;        // 2C
    std::uint32_t pad38;  // 38
    std::uint32_t pad3C;  // 3C
};

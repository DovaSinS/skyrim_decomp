// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// TESObjectREFR, NiPoint3Stand, PointVisitor, position, Unk_NN, TestPoint, CheckPosition: GUESS(low); stand-in view, layout only as far as the compared code reads it.
#pragma once

#include <cstdint>
#include <cstddef>

struct NiPoint3Stand
{
    float x;
    float y;
    float z;
};

class PointVisitor
{
public:
    virtual ~PointVisitor();
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
    virtual bool TestPoint(const NiPoint3Stand* a_point);  // slot 0x25
};

class TESObjectREFR
{
public:
    std::uint8_t unk00[0x54];
    NiPoint3Stand position;  // 54
    bool CheckPosition(PointVisitor* a_visitor) const;
};

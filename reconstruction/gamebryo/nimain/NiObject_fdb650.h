// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); layout only, base ctor is the matched out-of-line one
// BSOcclusionShape: CRASHLOGGER_PDB(59818@2026.10.24)
// BSOcclusionShape::BSOcclusionShape: CRASHLOGGER_PDB(59818@2026.10.24); the PDB name is CtorDefault
// BSOcclusionShape::unk10, BSOcclusionShape::unk1c, BSOcclusionShape::field40, BSOcclusionShape::unk44: GUESS(low)
// kZeroPoint, kIdentityRotation: GUESS(low)
#pragma once

#include <cstdint>

struct Point3
{
    float x;
    float y;
    float z;

    Point3() : x(0.0f), y(0.0f), z(0.0f) {}
};

struct Matrix3
{
    float entry[3][3];
};

extern const Point3 kZeroPoint;
extern const Matrix3 kIdentityRotation;

class NiObject
{
public:
    NiObject();
    virtual ~NiObject();

private:
    std::uint32_t refCount;
    std::uint32_t pad0c;
};

class BSOcclusionShape : public NiObject
{
public:
    BSOcclusionShape();
    ~BSOcclusionShape() override;

    Point3 unk10;
    Matrix3 unk1c;
    std::uint32_t field40;
    bool unk44;
};

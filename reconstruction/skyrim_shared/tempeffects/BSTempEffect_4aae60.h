// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BSTempEffectGeometryDecal, BSTempEffectGeometryDecal::BSTempEffectGeometryDecal: CRASHLOGGER_PDB(59818@2026.10.24)
// BSTempEffect, TESObjectCELL, NiPoint3, NiMatrix3: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSTempEffectGeometryDecal::decal, BSTempEffectGeometryDecal::attachedGeometry, BSTempEffectGeometryDecal::attachedGeometryParent, BSTempEffectGeometryDecal::decalNode, BSTempEffectGeometryDecal::queuedDecal, BSTempEffectGeometryDecal::texSet, BSTempEffectGeometryDecal::texSet2, BSTempEffectGeometryDecal::rotation, BSTempEffectGeometryDecal::origin, BSTempEffectGeometryDecal::direction, BSTempEffectGeometryDecal::unkA8, BSTempEffectGeometryDecal::flags, BSTempEffectGeometryDecal::unkB0: CRASHLOGGER_PDB(59818@2026.10.24); smart pointers are declared as plain pointers
#pragma once

#include <cstdint>

class TESObjectCELL;

struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct NiMatrix3
{
    float entry[3][3];
};

class BSTempEffect
{
public:
    BSTempEffect(TESObjectCELL* cell, float lifetime);
    virtual ~BSTempEffect();

private:
    std::uint8_t unk08[0x28];
};

class BSTempEffectGeometryDecal : public BSTempEffect
{
public:
    BSTempEffectGeometryDecal();
    ~BSTempEffectGeometryDecal() override;

    void* decal;
    void* attachedGeometry;
    void* attachedGeometryParent;
    void* decalNode;
    void* queuedDecal;
    void* texSet;
    void* texSet2;
    NiMatrix3 rotation;
    NiPoint3 origin;
    NiPoint3 direction;
    float width;
    std::uint32_t unkA8;
    std::uint32_t flags;
    bool unkB0;
};

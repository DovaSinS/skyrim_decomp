// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectCELL, bhkWorld, GetbhkWorld, parentCell: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); minimal views.
// TESObjectREFR, WorldHeader, WorldPart, WorldObject, unkC5C0, part, GetWorldObject: GUESS(low); stand-in view, the 0x10 base offset is read from the image.
#pragma once

#include <cstdint>
#include <cstddef>

class bhkWorld;

class TESObjectCELL
{
public:
    bhkWorld* GetbhkWorld() const;
};

struct WorldHeader
{
    void* header[2];
};

struct WorldPart
{
    void* unk00;
};

struct WorldObject : public WorldHeader, public WorldPart
{
};

class bhkWorld
{
public:
    std::uint8_t unk00[0xC5C0];
    WorldPart* part;  // C5C0
};

class TESObjectREFR
{
public:
    std::uint8_t unk00[0x60];
    TESObjectCELL* parentCell;  // 60
    static WorldObject* GetWorldObject(TESObjectREFR* a_ref);
};

// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// TESContainer, TESContainer::HasItem, ContainerObject, TESBoundObject: CRASHLOGGER_PDB(59818@2026.10.24); HasItem name only
// containerObjects, numContainerObjects, obj, count: SYMBOLS(fo4-pdb); same offsets observed in this build
#pragma once

#include <cstdint>
#include <cstddef>

class TESBoundObject;

struct ContainerObject
{
    std::int32_t count;
    std::uint32_t pad04;
    TESBoundObject* obj;
    void* itemExtra;
};

class TESContainer
{
public:
    bool HasItem(TESBoundObject* item);  // compared: 0x1e0a10

    std::uint8_t unk00[0x8];
    ContainerObject** containerObjects;
    std::uint32_t numContainerObjects;
};

// Source exposure: mixed (FO4 layout names; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// PathingDoor, DoorID, hDoor, ThisSideDoorLoc, OtherSideDoorLoc: SYMBOLS(fo4-pdb)
// Function4e0f00, PathingDoorReader, Slot0C, kNullHandle, unk00 to unk11, locFlags: GUESS(low); the reader's class is unknown, only its virtual slot 0x0C is used; the PDB lists Func4 for this address
#pragma once

#include <cstdint>
#include <cstddef>

class PathingDoorReader
{
public:
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual void unk07();
    virtual void unk08();
    virtual void unk09();
    virtual void unk0A();
    virtual void unk0B();
    virtual void Slot0C(void* a_dest);  // 0C
};

extern std::uint32_t kNullHandle;  // data at 0x219e55c

class PathingDoor
{
public:
    void Function4e0f00(PathingDoorReader* a_reader);

    std::uint8_t unk00[0x10];
    std::uint32_t DoorID;  // 0x10
    std::uint32_t hDoor;   // 0x14
    std::uint8_t unk18[0x2A];
    std::uint8_t locFlagsThisSide;   // 0x42
    std::uint8_t unk43[0x2F];
    std::uint8_t locFlagsOtherSide;  // 0x72
};
static_assert(offsetof(PathingDoor, DoorID) == 0x10, "DoorID offset");
static_assert(offsetof(PathingDoor, locFlagsOtherSide) == 0x72, "locFlagsOtherSide offset");

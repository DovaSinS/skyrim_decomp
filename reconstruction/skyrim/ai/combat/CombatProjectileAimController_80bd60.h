// Source exposure: mixed (CrashLogger and FO4 layout names; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// CombatProjectileAimController: CRASHLOGGER_PDB(59818@2026.10.24)
// Function80bd60, Slot05, NiPoint3, targetLocation, fireLocation, unk00 to unk73, unk8C: GUESS(low); NiPoint3 is a stand-in; CanFireNow is the CrashLogger name for this address but the listing does not show what it means, so the placeholder name stays
#pragma once

#include <cstdint>
#include <cstddef>

struct NiPoint3
{
    float x;
    float y;
    float z;
};

class CombatProjectileAimController
{
public:
    virtual ~CombatProjectileAimController();                  // 00
    virtual void unk01();                                      // 01
    virtual void unk02();                                      // 02
    virtual void unk03();                                      // 03
    virtual void unk04();                                      // 04
    virtual bool Slot05(void* a_arg, const NiPoint3& a_offset);       // 05

    bool Function80bd60(void* a_arg);

    std::uint8_t unk08[0x6C];
    NiPoint3 targetLocation;  // 0x74
    NiPoint3 fireLocation;    // 0x80
};
static_assert(offsetof(CombatProjectileAimController, targetLocation) == 0x74, "targetLocation offset");

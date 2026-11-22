// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BGSAIWorldLocation: GUESS(low); the class is the placeholder owner; layout is a minimal stand-in
// IsValid: SYMBOLS(fo4-pdb) CRASHLOGGER_PDB(59818@2026.10.24)
// unk08, unk09: GUESS(low); virtual slots 8 and 9, each returns a pointer the body tests for null
#pragma once

#include <cstdint>
#include <cstddef>

class BGSAIWorldLocation
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
    virtual void* unk08();
    virtual void* unk09();

    bool IsValid();
};

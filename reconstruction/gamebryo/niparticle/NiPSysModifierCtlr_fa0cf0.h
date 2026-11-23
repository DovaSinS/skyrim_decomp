// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// NiPSysModifierCtlr, NiSingleInterpController: STANDIN GUESS(low); the first is the placeholder owner, the second a base read from the listing
// NiPSysModifierCtlr::NiPSysModifierCtlr: GUESS(low); the CrashLogger name CControlRectTracker::CControlRectTracker is a placeholder for a constructor
// modifierName, modifier: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class NiSingleInterpController
{
public:
    NiSingleInterpController();
    virtual ~NiSingleInterpController();

    unsigned char unk08[0x48];
};
static_assert(sizeof(NiSingleInterpController) == 0x50, "base size");

class NiPSysModifierCtlr : public NiSingleInterpController
{
public:
    NiPSysModifierCtlr();
    ~NiPSysModifierCtlr() override;

    void* modifierName;
    void* modifier;
};
static_assert(offsetof(NiPSysModifierCtlr, modifier) == 0x58, "modifier offset");

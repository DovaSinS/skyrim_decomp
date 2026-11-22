// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// TESWeightForm: EXE_RTTI; class name from the image RTTI
// TESWeightForm::TESWeightForm: CRASHLOGGER_PDB(59818@2026.10.24); CrashLogger spells it ctor
// weight: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; layout view only
// ~TESWeightForm: GUESS(low); virtual slot 0 standing in for the vtable owner
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESWeightForm.cpp:14
#pragma once

#include <cstdint>

class TESWeightForm
{
public:
    TESWeightForm();
    virtual ~TESWeightForm();  // 00

    float weight;  // 08
};

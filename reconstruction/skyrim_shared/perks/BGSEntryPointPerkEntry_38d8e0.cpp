// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x38d8e0 BGSEntryPointPerkEntry::AbsoluteValue
// Adapted bodies: none
#include "BGSEntryPointPerkEntry_38d8e0.h"
#include <cmath>

void BGSEntryPointPerkEntry::AbsoluteValue(TESObjectREFR*, std::uint32_t a_functionType, std::uint8_t a_numArgs, void** a_args, BGSEntryPointFunctionData* a_data)
{
    if (a_functionType != 0) {
        return;
    }
    if (g_entryPointOneArgCount != a_numArgs) {
        return;
    }
    for (std::uint32_t i = 0; i < a_numArgs; ++i) {
        if (!a_args[i]) {
            return;
        }
    }
    if (a_data && a_data->GetType() != BGSEntryPointFunctionData::FunctionType::kInvalid) {
        return;
    }
    float* value = static_cast<float*>(a_args[0]);
    *value = static_cast<float>(std::fabs(static_cast<double>(*value)));
}

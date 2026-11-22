// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x38d2c0 BGSEntryPointPerkEntry::SetValue
// Adapted bodies: none
#include "BGSEntryPointPerkEntry_38d2c0.h"

void BGSEntryPointPerkEntry::SetValue(TESObjectREFR*, std::uint32_t a_functionType, std::uint8_t a_numArgs, void** a_args, BGSEntryPointFunctionData* a_data)
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
    if (a_data && a_data->GetType() != BGSEntryPointFunctionData::FunctionType::kOneValue) {
        return;
    }
    *static_cast<float*>(a_args[0]) = static_cast<BGSEntryPointFunctionDataOneValue*>(a_data)->data;
}

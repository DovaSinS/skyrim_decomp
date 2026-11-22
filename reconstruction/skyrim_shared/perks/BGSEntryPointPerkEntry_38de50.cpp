// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x38de50 BGSEntryPointPerkEntry::SelectSpellFunction
// Adapted bodies: none
#include "BGSEntryPointPerkEntry_38de50.h"

void BGSEntryPointPerkEntry::SelectSpellFunction(TESObjectREFR*, std::uint32_t a_functionType, std::uint8_t a_numArgs, void** a_args, BGSEntryPointFunctionData* a_data)
{
    if (a_functionType != 4) {
        return;
    }
    if (g_entryPointSpellArgCount != a_numArgs) {
        return;
    }
    for (std::uint32_t i = 0; i < a_numArgs; ++i) {
        if (!a_args[i]) {
            return;
        }
    }
    if (a_data && a_data->GetType() != BGSEntryPointFunctionData::FunctionType::kSpellItem) {
        return;
    }
    *static_cast<SpellItem**>(a_args[0]) = static_cast<BGSEntryPointFunctionDataSpellItem*>(a_data)->spell;
}

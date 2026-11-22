// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x396700 BGSEntryPointPerkEntry::ApplyPerkEntry
// Adapted bodies: none
#include "BGSEntryPointPerkEntry_396700.h"

void BGSEntryPointPerkEntry::ApplyPerkEntry(Actor* a_actor)
{
    RegisterPerkEntry(a_actor, this);
    BGSEntryPointFunctionData* data = GetFunctionData();
    if (data) {
        data->Unk_04(a_actor, this);
    }
}

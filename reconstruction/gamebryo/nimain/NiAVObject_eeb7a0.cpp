// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xeeb7a0 NiAVObject::GetController
// Adapted bodies: none
#include "NiAVObject_eeb7a0.h"

NiTimeController* NiAVObject::GetController(const NiRTTI* a_rtti) const
{
    for (NiTimeController* controller = controllers; controller; controller = controller->next) {
        for (const NiRTTI* rtti = controller->GetRTTI(); rtti; rtti = rtti->baseRTTI) {
            if (rtti == a_rtti) {
                return controller;
            }
        }
    }
    return nullptr;
}

// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x38b740 BGSBodyPartData::GetPartByActorValue
// Adapted bodies: none
#include "BGSBodyPartData_38b740.h"

BGSBodyPart* BGSBodyPartData::GetPartByActorValue(std::int32_t a_actorValue)
{
    for (std::int64_t i = 0; i < 6; ++i) {
        BGSBodyPart* part = parts[i];
        if (part && part->data.actorValue == a_actorValue) {
            return part;
        }
    }
    return nullptr;
}

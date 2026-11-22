// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x468360 BGSProcedureFind::InitActorAnimPose
// Adapted bodies: none
#include "BGSProcedureFind_468360.h"

// 0x468360 BGSProcedureFind::InitActorAnimPose
void BGSProcedureFind::InitActorAnimPose(BGSProcessContext& a_context)
{
    BGSProcessData* data = a_context.processData;
    unk09();
    if (!a_context.actorData->unk20Flag) {
        data->unk14Flag = 1;
        unk0C(a_context);
    }
}

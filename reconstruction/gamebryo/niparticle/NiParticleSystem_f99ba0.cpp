// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// 0xf99ba0 NiParticleSystem::SetSelectiveUpdateFlags
// Adapted bodies: none
#include "NiParticleSystem_f99ba0.h"

void NiParticleSystem::SetSelectiveUpdateFlags(bool& a_selectiveUpdate, bool, bool& a_rigid)
{
    a_selectiveUpdate = true;
    a_rigid = false;
    SetSelectiveUpdate(a_selectiveUpdate);
    SetSelectiveUpdateTransforms(true);
    SetSelectiveUpdateController(true);
    SetSelectiveUpdateRigid(a_rigid);
}

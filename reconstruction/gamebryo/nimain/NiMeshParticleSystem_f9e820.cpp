// Source exposure: binary-analysis (pinned image listing only).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xf9e820 NiMeshParticleSystem::SetSelectiveUpdateFlags
// Adapted bodies: none
#include "NiMeshParticleSystem_f9e820.h"

void NiMeshParticleSystem::SetSelectiveUpdateFlags(bool& selective, bool transforms, bool& rigid)
{
    NiParticleSystem::SetSelectiveUpdateFlags(selective, true, rigid);
    NiParticleMeshModifierTarget* target = unk158;
    target->unkA8->ApplyFlags(selective, true, rigid);
    rigid = false;
    target->unkA8->flagsF4 &= ~0x10u;
}

// Source exposure: binary-analysis (pinned image listing only).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xffbe80 BSMasterParticleSystem::HasActiveParticles
// Adapted bodies: none
#include "BSMasterParticleSystem_ffbe80.h"

bool BSMasterParticleSystem::HasActiveParticles()
{
    const std::uint32_t count = emitterCount150;
    for (std::uint32_t i = 0; i < count; ++i) {
        if (emitters140[i] && emitters140[i]->data158->GetParticleCount() != 0) {
            return true;
        }
    }
    return false;
}

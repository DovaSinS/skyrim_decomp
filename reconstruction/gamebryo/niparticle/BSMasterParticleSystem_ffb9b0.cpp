// Source exposure: binary-analysis (pinned image listing only).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xffb9b0 BSMasterParticleSystem::MarkEmittersDirty
// Adapted bodies: none
#include "BSMasterParticleSystem_ffb9b0.h"

void BSMasterParticleSystem::MarkEmittersDirty()
{
    const std::uint32_t count = emitterCount150;
    for (std::uint32_t i = 0; i < count; ++i) {
        if (emitters140[i]) {
            emitters140[i]->flag190 = true;
        }
    }
}

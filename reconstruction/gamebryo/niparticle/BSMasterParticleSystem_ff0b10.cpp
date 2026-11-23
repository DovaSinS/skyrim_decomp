// Source exposure: binary-analysis (pinned image listing only).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xff0b10 BSMasterParticleSystem::GetTotalParticleCount
// Adapted bodies: none
#include "BSMasterParticleSystem_ff0b10.h"

std::uint32_t BSMasterParticleSystem::GetTotalParticleCount()
{
    std::uint32_t total = 0;
    for (std::uint32_t i = 0; i < emitterCount150; ++i) {
        total += emitters140[i]->data158->GetParticleCount();
    }
    return total;
}

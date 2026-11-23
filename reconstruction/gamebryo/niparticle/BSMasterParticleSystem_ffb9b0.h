// Source exposure: binary-analysis (pinned image listing only).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BSMasterParticleSystem, EmitterObject, EmitterData: STANDIN GUESS(low); only the members the body touches
// BSMasterParticleSystem::MarkEmittersDirty: GUESS(low); the PDB has only a placeholder name for this address
// BSMasterParticleSystem::emitters140, BSMasterParticleSystem::emitterCount150, EmitterObject::flag190: GUESS(low)
#pragma once

#include <cstdint>

class EmitterObject
{
public:
    std::uint8_t unk00[0x190];
    bool flag190;
};

class BSMasterParticleSystem
{
public:
    void MarkEmittersDirty();

private:
    std::uint8_t unk00[0x140];
    EmitterObject** emitters140;
    std::uint32_t emitterCapacity148;
    std::uint32_t unk14C;
    std::uint32_t emitterCount150;
};

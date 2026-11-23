// Source exposure: binary-analysis (pinned image listing only).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BSMasterParticleSystem, EmitterObject, EmitterData: STANDIN GUESS(low); only the members the body touches
// BSMasterParticleSystem::HasActiveParticles: GUESS(low); the PDB has only a placeholder name for this address
// BSMasterParticleSystem::emitters140, BSMasterParticleSystem::emitterCount150, EmitterObject::data158, EmitterData::GetParticleCount: GUESS(low)
#pragma once

#include <cstdint>

class EmitterData
{
public:
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual void unk07();
    virtual void unk08();
    virtual void unk09();
    virtual void unk0A();
    virtual void unk0B();
    virtual void unk0C();
    virtual void unk0D();
    virtual void unk0E();
    virtual void unk0F();
    virtual void unk10();
    virtual void unk11();
    virtual void unk12();
    virtual void unk13();
    virtual void unk14();
    virtual void unk15();
    virtual void unk16();
    virtual void unk17();
    virtual void unk18();
    virtual void unk19();
    virtual void unk1A();
    virtual void unk1B();
    virtual void unk1C();
    virtual void unk1D();
    virtual void unk1E();
    virtual void unk1F();
    virtual void unk20();
    virtual void unk21();
    virtual void unk22();
    virtual void unk23();
    virtual void unk24();
    virtual void unk25();
    virtual std::uint16_t GetParticleCount();
};

class EmitterObject
{
public:
    std::uint8_t unk00[0x158];
    EmitterData* data158;
};

class BSMasterParticleSystem
{
public:
    bool HasActiveParticles();

private:
    std::uint8_t unk00[0x140];
    EmitterObject** emitters140;
    std::uint32_t emitterCapacity148;
    std::uint32_t unk14C;
    std::uint32_t emitterCount150;
};

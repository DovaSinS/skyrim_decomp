// Source exposure: binary-analysis (pinned image listing only).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// NiMeshParticleSystem::SetSelectiveUpdateFlags: CRASHLOGGER_PDB(59818@2026.10.24); the PDB spells the name with a suffix
// NiParticleSystem::SetSelectiveUpdateFlags: CRASHLOGGER_PDB(59818@2026.10.24)
// NiParticleSystem, NiMeshParticleSystem, NiParticleMeshModifierTarget, NiParticleMeshData: STANDIN GUESS(low); only the members the body touches
// NiMeshParticleSystem::unk158, NiParticleMeshModifierTarget::unkA8, NiParticleMeshData::flagsF4, NiParticleMeshData::ApplyFlags: GUESS(low)
#pragma once

#include <cstdint>

class NiParticleMeshData
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
    virtual void unk26();
    virtual void unk27();
    virtual void unk28();
    virtual void unk29();
    virtual void unk2A();
    virtual void ApplyFlags(bool& flag, bool value, bool& other);

    std::uint8_t pad08[0xEC];
    std::uint32_t flagsF4;
};

class NiParticleMeshModifierTarget
{
public:
    std::uint8_t unk00[0xA8];
    NiParticleMeshData* unkA8;
};

class NiParticleSystem
{
public:
    void SetSelectiveUpdateFlags(bool& selective, bool transforms, bool& rigid);

    std::uint8_t unk00[0x158];
};

class NiMeshParticleSystem : public NiParticleSystem
{
public:
    void SetSelectiveUpdateFlags(bool& selective, bool transforms, bool& rigid);

    NiParticleMeshModifierTarget* unk158;
};

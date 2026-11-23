// Source exposure: binary-analysis (names from CrashLogger output; shapes from the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Actor::Function6d51c0: CRASHLOGGER_PDB(59818@2026.10.24) GUESS(low); placeholder name for MagicTarget::Func9; the unit keeps the placeholder class Actor
// ActiveEffect, ActiveEffect::Function5bb090, ReturnLeaf1539e0, ReturnLeaf1539e0::Invoke, ActorProcess, ActorProcess::Function7271e0: CRASHLOGGER_PDB(59818@2026.10.24) GUESS(low); callee placeholders, declared as stand-ins
// EffectDataLike, ActiveEffect::unk48: GUESS(low); stand-ins for the effect's own data and the member the function tests
#pragma once

#include <cstdint>
#include <cstddef>

class EffectDataLike;

class ActiveEffect
{
public:
    EffectDataLike* Function5bb090();

    std::uint8_t unk00[0x48];
    void* unk48;
};

struct ReturnLeaf1539e0
{
    static std::int32_t Invoke(EffectDataLike* a_data);
};

class ActorProcess
{
public:
    void Function7271e0();
};

class Actor
{
public:
    void Function6d51c0(ActiveEffect* a_effect);

    std::uint8_t unk00[0x58];
    ActorProcess* unk58;
};

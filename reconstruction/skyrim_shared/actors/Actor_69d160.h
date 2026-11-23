// Source exposure: binary-analysis (names from CrashLogger output; shapes from the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Actor::Function69d160: CRASHLOGGER_PDB(59818@2026.10.24) GUESS(low); placeholder name for Character::sub_1405F77C0
// ActorValueOwnerLike, ActorValueOwnerLike::unk00, ActorValueOwnerLike::Function8: GUESS(low); stand-in for the embedded object at 0xB8
#pragma once

#include <cstdint>
#include <cstddef>

class ActorValueOwnerLike
{
public:
    virtual void unk00();
    virtual float Function8(std::uint32_t a_arg);
};

class Actor
{
public:
    std::int32_t Function69d160();

    std::uint8_t unk00[0xB8];
    ActorValueOwnerLike unkB8;
};

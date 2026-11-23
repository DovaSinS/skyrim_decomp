// Source exposure: binary-analysis (names from CrashLogger output; shapes from the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// PlayerCharacter::Function6d45e0: CRASHLOGGER_PDB(59818@2026.10.24) GUESS(low); placeholder name for PlayerCharacter::sub_14062FBA0
// ActorProcess::Function7270a0: GUESS(low); callee placeholder, declared as a stand-in
#pragma once

#include <cstdint>
#include <cstddef>

class ActorProcess
{
public:
    float Function7270a0();
};

class PlayerCharacter
{
public:
    float Function6d45e0();

    std::uint8_t unk00[0xF8];
    ActorProcess* unkF8;
};

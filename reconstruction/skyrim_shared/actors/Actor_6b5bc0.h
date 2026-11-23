// Source exposure: binary-analysis (names from CrashLogger output; shapes from the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Actor::Function6b5bc0: CRASHLOGGER_PDB(59818@2026.10.24) GUESS(low); placeholder name for ActorState::Func16_14060EDD0; the unit keeps the placeholder class Actor
// ActorProcess::Function7012f0: CRASHLOGGER_PDB(59818@2026.10.24) GUESS(low); callee placeholder, declared as a stand-in
#pragma once

#include <cstdint>
#include <cstddef>

class ActorProcess
{
public:
    bool Function7012f0();
};

class Actor
{
public:
    bool Function6b5bc0();

    std::uint8_t unk00[0x38];
    ActorProcess* unk38;
};

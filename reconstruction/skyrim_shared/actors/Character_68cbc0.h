// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Character, Character::Function68cbc0: GUESS(low)
// Character::unkF8, ActorProcess: GUESS(low)
// ActorProcess::Function6f6470: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include <cstdint>
#include <cstddef>

struct ActorProcess
{
    std::int32_t Function6f6470();
};

class Character
{
public:
    std::int32_t Function68cbc0();  // compared: 0x68cbc0

    std::uint8_t pad00[0xF8];
    ActorProcess* unkF8;
};

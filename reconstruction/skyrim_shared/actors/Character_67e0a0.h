// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Character: STANDIN GUESS(low); a view of the members used, from offsets
// Character::Function67e0a0: CRASHLOGGER_PDB(59818@2026.10.24)
// ActorProcess: STANDIN CRASHLOGGER_PDB(59818@2026.10.24); only the type name
// ActorProcess::Function6f6fc0: CRASHLOGGER_PDB(59818@2026.10.24); float parameter guessed from the call site
// Character::currentProcess: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); at 0xf8
#pragma once

#include <cstdint>
#include <cstddef>

class ActorProcess
{
public:
    void Function6f6fc0(float a_value);
};

class Character
{
public:
    void Function67e0a0();  // compared: 0x67e0a0

    std::uint8_t pad00[0xf8];
    ActorProcess* currentProcess;
};

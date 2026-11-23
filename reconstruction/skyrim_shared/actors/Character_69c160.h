// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Character: STANDIN GUESS(low); a view of the members used, from offsets
// Character::Function69c160: CRASHLOGGER_PDB(59818@2026.10.24)
// ActorProcess: STANDIN CRASHLOGGER_PDB(59818@2026.10.24); only the type name
// ActorProcess::Function6f6470: CRASHLOGGER_PDB(59818@2026.10.24); returns an int, compared with 7
// Character::currentProcess: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); at 0xf8
#pragma once

#include <cstdint>
#include <cstddef>

class ActorProcess
{
public:
    int Function6f6470();
};

class Character
{
public:
    bool Function69c160();  // compared: 0x69c160

    std::uint8_t pad00[0xf8];
    ActorProcess* currentProcess;
};

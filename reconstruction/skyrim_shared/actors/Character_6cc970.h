// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Character, Character::Function6cc970, ProcessHolder, ProcessHolder::Query6cc970: GUESS(low)
#pragma once

class ProcessHolder
{
public:
    bool Query6cc970();  // callee at 0x728690, called with the process pointer as this
};

class Character
{
public:
    bool Function6cc970();  // compared: 0x6cc970

    char pad000[0xF8];
    ProcessHolder* process;  // 0xF8
};

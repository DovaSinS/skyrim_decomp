// Source exposure: mixed (community headers; compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// Character: GUESS(low); the class is the placeholder owner
// IsMeleeAttackState: CRASHLOGGER_PDB(59818@2026.10.24)
// actorState1: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the word at this offset, the leading window is padding
#pragma once

#include <cstdint>
#include <cstddef>

class Character
{
public:
    bool IsMeleeAttackState();  // compared: 0x6cb9d0

    std::uint8_t unk00[0xC8];
    std::uint32_t actorState1;
};

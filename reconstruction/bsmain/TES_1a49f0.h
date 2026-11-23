// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// TES, DeadCountNode, DeadCountEntry, GetDeadCountOf: GUESS(low); stand-in view, layout only as far as the compared code reads it.
// deadCount: CRASHLOGGER_PDB(59818@2026.10.24); a singly linked list of (actor base, count) tuples embedded in TES at 0x150.
#pragma once

#include <cstdint>
#include <cstddef>

class TESNPC;

struct DeadCountEntry
{
    TESNPC* npc;           // 00
    std::uint16_t count;   // 08
};

struct DeadCountNode
{
    DeadCountEntry* item;  // 00
    DeadCountNode* next;   // 08
};

class TES
{
public:
    std::uint8_t unk00[0x150];
    DeadCountNode deadCount;  // 150
    std::uint16_t GetDeadCountOf(const TESNPC* a_npc) const;
};

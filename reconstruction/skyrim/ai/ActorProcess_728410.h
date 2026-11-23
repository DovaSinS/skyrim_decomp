// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// PerkEntryVisitor, Visit, BGSPerkEntry, ForEachResult, kContinue: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActorProcess, Function728410, middleHigh, perkEntries, MiddleHighData, PerkEntryArray, kPerkEntryPointCount: GUESS(low); ActorProcess is the placeholder owner, NG calls the class AIProcess
// data, capacity, size, pad08, pad0C, pad288: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class BGSPerkEntry;

enum class ForEachResult : std::int32_t {
    kStop = 0,
    kContinue = 1
};

class PerkEntryVisitor
{
public:
    virtual ForEachResult Visit(BGSPerkEntry* a_perkEntry) = 0;  // 00
};

struct PerkEntryArray
{
    BGSPerkEntry** data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
    std::uint32_t size;
    std::uint32_t pad14;
};
static_assert(sizeof(PerkEntryArray) == 0x18, "PerkEntryArray size");

struct MiddleHighData
{
    std::uint8_t pad00[0x288];
    PerkEntryArray* perkEntries;
};

class ActorProcess
{
public:
    void Function728410(std::uint8_t a_entryPoint, PerkEntryVisitor& a_visitor);

    std::uint8_t pad00[0x8];
    MiddleHighData* middleHigh;
};

constexpr std::uint8_t kPerkEntryPointCount = 0x5C;

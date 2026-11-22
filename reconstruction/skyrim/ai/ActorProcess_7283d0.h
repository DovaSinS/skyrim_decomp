// Source exposure: community-headers (names, layout), binary-analysis (offsets from the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// ActorProcess: GUESS(low); the class is the placeholder owner
// HasPerkEntries: SYMBOLS(fo4-pdb); FO4 names it on AIProcess, the unit keeps the placeholder class ActorProcess
// AIProcess::middleHigh, perkData, MiddleHighProcessData, AIPerkData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); MiddleHighProcessData and AIPerkData are stand-ins with only what the body reads
// PerkEntryList, entries, size: GUESS(low); a 24-byte per-entry-point array header whose count is read
#pragma once

#include <cstdint>
#include <cstddef>

struct PerkEntryList
{
    std::uint8_t pad00[0x10];
    std::uint32_t size;
    std::uint32_t pad14;
};

struct AIPerkData
{
    PerkEntryList entries[1];
};

struct MiddleHighProcessData
{
    std::uint8_t pad00[0x288];
    AIPerkData* perkData;
};

class ActorProcess
{
public:
    bool HasPerkEntries(std::uint8_t a_entryPoint) const;  // compared: 0x7283d0

    std::uint8_t pad00[0x8];
    MiddleHighProcessData* middleHigh;
};

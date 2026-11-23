// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSPerkRankArray, BGSPerkRankArray::perks, BGSPerkRankArray::perkCount, PerkRankData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; names and offsets only
// BGSPerkRankArray::sub_14018AA70: CRASHLOGGER_PDB(59818@2026.10.24); placeholder name of the compared function
// BGSPerkRankArray::VisitPerks, PerkRankVisitor, PerkRankVisitor::Visit, unk00, unk14: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct PerkRankData
{
    unsigned char unk00[0x10];
};

class PerkRankVisitor
{
public:
    virtual int Visit(PerkRankData* a_perk) = 0;
};

class BGSPerkRankArray
{
public:
    void VisitPerks(PerkRankVisitor* a_visitor);

    unsigned char unk00[8];
    PerkRankData* perks;
    std::uint32_t perkCount;
    std::uint32_t unk14;
};
static_assert(sizeof(BGSPerkRankArray) == 0x18, "array size");

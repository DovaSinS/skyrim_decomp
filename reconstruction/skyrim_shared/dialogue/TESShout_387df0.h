// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESShout, TESShout::Variation, word, spell, recoveryTime, pad14, variations, TESWordOfPower, SpellItem: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; names and offsets only
// TESShout::sub_140329AC0: CRASHLOGGER_PDB(59818@2026.10.24); placeholder name of the compared function
// TESShout::GetLastUnlockedIndex: GUESS(low)
// flagsHigh, unk00: GUESS(low); the third byte of the community form flag word
// unk00: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class SpellItem;

class TESWordOfPower
{
public:
    unsigned char unk00[0x12];
    std::uint8_t flagsHigh;
};

class TESShout
{
public:
    struct Variation
    {
        TESWordOfPower* word;
        SpellItem* spell;
        float recoveryTime;
        std::uint32_t pad14;
    };

    int GetLastUnlockedIndex();

    unsigned char unk00[0x60];
    Variation variations[3];
};
static_assert(sizeof(TESShout::Variation) == 0x18, "variation size");
static_assert(offsetof(TESShout, variations) == 0x60, "variations offset");

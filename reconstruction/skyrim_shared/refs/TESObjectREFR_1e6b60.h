// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectREFR, TESObjectREFR::Function1e6b60, TESObjectREFR::Unk_01..Unk_09: GUESS(low)
// TESForm::inGameFormFlags, TESForm::AddChange: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the class models TESForm here, slot 0x0A
#pragma once

#include <cstdint>
#include <cstddef>

class TESObjectREFR
{
public:
    virtual ~TESObjectREFR();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual bool AddChange(std::uint32_t a_changeFlags);  // 0A

    void Function1e6b60(std::uint16_t a_mask, bool a_set);

    unsigned char pad08[0x10];
    std::uint16_t inGameFormFlags;  // 18
};

// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// PeakValueModifierEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the class is a stand-in that only holds the layout
// ActiveEffect, EffectSetting, TESForm: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// PeakValueModifierEffect::Function5da3a0, ActiveEffect::Function5bb090, EffectSetting::Function14b4f0, ActiveEffect::pad08, ActiveEffect::unk90: GUESS(low)
#pragma once

#include <cstdint>

class TESForm;

class EffectSetting
{
public:
    TESForm* Function14b4f0() const;
};

class ActiveEffect
{
public:
    virtual ~ActiveEffect();

    EffectSetting* Function5bb090() const;

    std::uint8_t pad08[0x88];
    std::uint32_t unk90;
};

class PeakValueModifierEffect : public ActiveEffect
{
public:
    bool Function5da3a0(ActiveEffect* other) const;
};

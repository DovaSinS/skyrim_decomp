// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SpellItem, SpellItem::Function151330, EffectSettingData::flagsLow, EffectSettingData::flagsHigh: GUESS(low); the flags word is split into bytes so the bit-24 test reads one byte
// SpellItem::effects, Effect, Effect::baseEffect, EffectSetting, EffectSetting::data, EffectSettingData, EffectSettingData::flags: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

struct EffectSettingData
{
    std::uint8_t flagsLow[3];
    std::uint8_t flagsHigh;
};

struct EffectSetting
{
    std::uint8_t unk00[0x68];
    EffectSettingData data;
};

struct Effect
{
    std::uint8_t unk00[0x10];
    EffectSetting* baseEffect;
};

struct EffectArray
{
    Effect** data;
    std::uint32_t capacity;
    std::uint32_t pad0c;
    std::uint32_t size;
};

class SpellItem
{
public:
    bool Function151330() const;

private:
    std::uint8_t unk00[0x58];
    EffectArray effects;
};

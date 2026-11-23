// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1dd430 TESActorBaseData::Function1dd430
// Adapted bodies: none
#include "TESActorBaseData_1dd430.h"

// TESActorBase: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class TESActorBase : public TESBoundAnimObject, public TESActorBaseData {};

// kBaseDataChange: STANDIN GUESS(low)
constexpr std::uint32_t kBaseDataChange = 1u << 1;

void TESActorBaseData::Function1dd430(std::uint16_t value)
{
    level = value;
    if (auto* actor = static_cast<TESActorBase*>(this)) {
        actor->AddChange(kBaseDataChange);
    }
}

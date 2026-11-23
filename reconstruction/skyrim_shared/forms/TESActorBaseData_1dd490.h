// Source exposure: mixed (project form layouts, CommonLibSSE-NG, and the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// Function1dd490: GUESS(low)
// TESActorBase: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include "TESBoundAnimObject.h"

class TESActorBaseData : public BaseFormComponent
{
public:
    void Function1dd490(std::uint16_t value);

private:
    // actorData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); layout collapsed to unknown bytes
    std::uint8_t unk08[0x8];
    std::uint16_t level;
    std::uint16_t calcLevelMin;
    std::uint16_t calcLevelMax;
    std::uint16_t speedMult;
    std::uint16_t baseDisposition;
};

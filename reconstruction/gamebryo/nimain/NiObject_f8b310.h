// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); layout only, base ctor is the matched out-of-line one
// NiObjectF8B310, NiObjectF8B310::unk10, NiObjectF8B310::unk14, NiObjectF8B310::unk18, NiObjectF8B310::unk1c, NiObjectF8B310::unk20: GUESS(low)
#pragma once

#include <cstdint>

class NiObject
{
public:
    NiObject();
    virtual ~NiObject();

private:
    std::uint32_t refCount;
    std::uint32_t pad0c;
};

class NiObjectF8B310 : public NiObject
{
public:
    NiObjectF8B310(float first, std::int32_t second, float third, std::int32_t fourth);
    ~NiObjectF8B310() override;

    std::uint32_t unk10;
    float unk14;
    std::int32_t unk18;
    float unk1c;
    std::int32_t unk20;
};

// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); layout only, base ctor is the matched out-of-line one
// NiObjectF86900, NiObjectF86900::unk10, NiObjectF86900::unk14, NiObjectF86900::unk18, NiObjectF86900::unk20, NiObjectF86900::unk24: GUESS(low)
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

class NiObjectF86900 : public NiObject
{
public:
    NiObjectF86900();
    ~NiObjectF86900() override;

    std::uint32_t unk10;
    std::uint32_t unk14;
    void* unk18;
    std::uint32_t unk20;
    bool unk24;
};

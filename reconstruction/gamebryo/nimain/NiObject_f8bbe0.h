// Source exposure: binary-analysis (pinned image listing only).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the base constructor and a virtual destructor are declared
// NiObjectF8bbe0: GUESS(low); placeholder for an unidentified NiObject-derived class
// NiObjectF8bbe0::kind10, NiObjectF8bbe0::scale14, NiObjectF8bbe0::scale18, NiObjectF8bbe0::count1c: GUESS(low)
#pragma once

#include <cstdint>

class NiObject
{
public:
    NiObject();
    virtual ~NiObject();

private:
    std::uint64_t unk08;
};

class NiObjectF8bbe0 : public NiObject
{
public:
    NiObjectF8bbe0(float a14, float a18, std::uint32_t a1c);
    ~NiObjectF8bbe0() override;

private:
    std::uint32_t kind10;
    float scale14;
    float scale18;
    std::uint32_t count1c;
};

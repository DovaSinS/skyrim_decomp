// Source exposure: binary-analysis (pinned image listing only).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the base constructor and a virtual destructor are declared
// NiObject10c2ef0: GUESS(low); placeholder for an unidentified NiObject-derived class
// NiObject10c2ef0::unk10, NiObject10c2ef0::unk18, NiObject10c2ef0::unk20, NiObject10c2ef0::unk28: GUESS(low)
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

class NiObject10c2ef0 : public NiObject
{
public:
    NiObject10c2ef0();
    ~NiObject10c2ef0() override;

private:
    std::uint32_t unk10;
    void* unk18;
    std::uint32_t unk20;
    void* unk28;
};

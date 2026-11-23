// Source exposure: binary-analysis (pinned image listing only).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the base constructor and a virtual destructor are declared
// bhkRagdollShareData: CRASHLOGGER_PDB(59818@2026.10.24); the constructor name only, not evidence of identity
// bhkRagdollShareData::unk10, bhkRagdollShareData::unk18, bhkRagdollShareData::unk20, bhkRagdollShareData::unk28, bhkRagdollShareData::unk30, bhkRagdollShareData::unk38: GUESS(low)
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

class bhkRagdollShareData : public NiObject
{
public:
    bhkRagdollShareData();
    ~bhkRagdollShareData() override;

private:
    void* unk10;
    void* unk18;
    void* unk20;
    void* unk28;
    void* unk30;
    void* unk38;
};

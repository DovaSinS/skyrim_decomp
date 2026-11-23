// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSSceneAction, BGSSceneAction::LoadBuffer, BGSLoadGameBuffer, BGSLoadGameBuffer::LoadDataEndian: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the callees, slot 09 per NG
// BGSSceneActionTimer::LoadBuffer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) CRASHLOGGER_PDB(59818@2026.10.24)
// BGSSceneActionTimer::unk24, BGSSceneActionTimer::unk28: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG declares unk28 as 64-bit
// BGSSceneActionTimer::unk29: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class BGSLoadGameBuffer
{
public:
    void LoadDataEndian(void* a_data, std::uint32_t a_offset, std::uint32_t a_size);
};

class BGSSceneAction
{
public:
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual void unk07();
    virtual void unk08();
    virtual void LoadBuffer(void* a_arg1, BGSLoadGameBuffer* a_buf);

    std::uint8_t pad08[0x18];
};

class BGSSceneActionTimer : public BGSSceneAction
{
public:
    void LoadBuffer(void* a_arg1, BGSLoadGameBuffer* a_buf) override;

    std::uint8_t pad20[0x4];
    std::uint32_t unk24;
    std::uint8_t unk28;
    std::uint8_t unk29;
};

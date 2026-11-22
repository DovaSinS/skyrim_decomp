// Source exposure: mixed (community headers; compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// BGSSceneAction: GUESS(low); the class is the placeholder owner; layout is a minimal stand-in
// LoadBuffer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) CRASHLOGGER_PDB(59818@2026.10.24)
// BGSLoadGameBuffer, LoadDataEndian: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the callee
// loadsFirst, loadsSecond: GUESS(low); the two low bits of the byte at 0x14 that the body fills from the buffer
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
    void LoadBuffer(void* a_arg1, BGSLoadGameBuffer* a_buf);

    std::uint8_t pad00[0x14];
    std::uint8_t loadsFirst : 1;   // 14 bit 0
    std::uint8_t loadsSecond : 1;  // 14 bit 1
};

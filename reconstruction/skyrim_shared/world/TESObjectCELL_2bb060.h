// Source exposure: mixed (community headers; compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// TESObjectCELL: GUESS(low); the class is the placeholder owner; layout is a minimal stand-in
// GetEditorId: CRASHLOGGER_PDB(59818@2026.10.24)
// ExtraDataList: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the one callee
// extraList, cellFlags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG declares cellFlags as a 16-bit enumeration, only the low byte is tested
// Function1704d0: GUESS(low); placeholder name for the callee at 0x1704d0
// kEmptyString: GUESS(low); global at RVA 0x1b58020, the empty text
// pFallbackName: GUESS(low); global pointer at RVA 0x207b9c8, the text returned for an exterior cell
#pragma once

#include <cstdint>
#include <cstddef>

extern const char  kEmptyString[];
extern const char* pFallbackName;

class ExtraDataList
{
public:
    const char* Function1704d0();

    std::uint8_t pad00[8];
};

class TESObjectCELL
{
public:
    const char* GetEditorId();

    std::uint8_t  pad00[0x40];
    std::uint8_t  cellFlags;  // 40
    std::uint8_t  pad41[7];
    ExtraDataList extraList;  // 48
};

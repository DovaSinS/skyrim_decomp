// Source exposure: mixed (community headers; compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// Character: GUESS(low); the class is the placeholder owner
// GetCurrentPackageTarget: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb); the PDB class is Actor, this unit keeps the placeholder class
// ObjectRefHandle: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); stand-in handle, one 32-bit word
// kNullHandle: GUESS(low); named after the symbol map, a data constant in the image
// currentProcess: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); at this build's offset 0xF8
// ProcessView, packageTarget: GUESS(low); the process view only holds the one handle read at 0x30
#pragma once

#include <cstdint>
#include <cstddef>

struct ObjectRefHandle
{
    ObjectRefHandle& operator=(const ObjectRefHandle& a_rhs)
    {
        native = a_rhs.native;
        return *this;
    }

    std::uint32_t native;
};

extern const ObjectRefHandle kNullHandle;

class ProcessView
{
public:
    std::uint8_t unk00[0x30];
    ObjectRefHandle packageTarget;
};

class Character
{
public:
    ObjectRefHandle& GetCurrentPackageTarget(ObjectRefHandle& a_handle);  // compared: 0x67f580

    std::uint8_t unk00[0xF8];
    ProcessView* currentProcess;
};

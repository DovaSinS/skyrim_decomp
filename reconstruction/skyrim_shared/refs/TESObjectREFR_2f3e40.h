// Source exposure: mixed (community headers; compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// TESObjectREFR: GUESS(low); the class is the placeholder owner; layout is a minimal stand-in
// GetSaveParentCell: SYMBOLS(fo4-pdb) CRASHLOGGER_PDB(59818@2026.10.24)
// ExtraDataList, TESObjectCELL, formFlags, parentCell, extraList: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); stand-in declarations
// GetPersistentCell: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// cellFlags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG declares a 16-bit enumeration, only the low byte is tested
#pragma once

#include <cstdint>
#include <cstddef>

class TESObjectCELL
{
public:
    std::uint8_t pad00[0x40];
    std::uint8_t cellFlags;  // 40
};

class ExtraDataList
{
public:
    TESObjectCELL* GetPersistentCell();

    std::uint8_t pad00[8];
};

class TESObjectREFR
{
public:
    TESObjectCELL* GetSaveParentCell();

    std::uint8_t   pad00[0x10];
    std::uint32_t  formFlags;   // 10
    std::uint8_t   pad14[0x4C];
    TESObjectCELL* parentCell;  // 60
    std::uint8_t   pad68[8];
    ExtraDataList  extraList;   // 70
};

// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSEntryPointPerkEntry: GUESS(low); the class is the placeholder owner of a static entry point function
// BGSEntryPointPerkEntry::SelectSpellFunction: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb); FO4 and CrashLogger place it in BGSEntryPointFunction, the unit keeps the placeholder class; the parameter list follows the FO4 prototype
// BGSEntryPointFunctionData, BGSEntryPointFunctionData::FunctionType, ::GetType, kInvalid, kOneValue, kSpellItem: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slots 00 and 01 only
// BGSEntryPointFunctionDataOneValue, BGSEntryPointFunctionDataOneValue::data, BGSEntryPointFunctionDataSpellItem, BGSEntryPointFunctionDataSpellItem::spell: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; only the value at +08 is read
// TESObjectREFR, SpellItem: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the type names only
// g_entryPointSpellArgCount: GUESS(low); a global count the function compares with the argument count, read from the listing
#pragma once

#include <cstdint>

class TESObjectREFR;
class SpellItem;

class BGSEntryPointFunctionData
{
public:
    enum class FunctionType
    {
        kInvalid = 0,
        kOneValue = 1,
        kSpellItem = 5
    };

    virtual ~BGSEntryPointFunctionData();                  // 00
    virtual FunctionType GetType() const = 0;              // 01
};

class BGSEntryPointFunctionDataSpellItem : public BGSEntryPointFunctionData
{
public:
    SpellItem* spell;  // 08
};

extern std::uint32_t g_entryPointSpellArgCount;

class BGSEntryPointPerkEntry
{
public:
    static void SelectSpellFunction(TESObjectREFR* a_refr, std::uint32_t a_functionType, std::uint8_t a_numArgs, void** a_args, BGSEntryPointFunctionData* a_data);
};

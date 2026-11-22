// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSEntryPointPerkEntry, BGSEntryPointPerkEntry::CheckConditionFilters, ::GetFunction, ::GetFunctionData, ::~BGSEntryPointPerkEntry, ::GetType, ::ClearData, ::InitItem, ::Load, ::SetParent, ::GetID, ::ApplyPerkEntry: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot order 00 to 0A
// BGSEntryPointPerkEntry::ApplyPerkEntry: CRASHLOGGER_PDB(59818@2026.10.24); the PDB placeholder name carries index 10, which is the NG slot of ApplyPerkEntry, a name hint only
// BGSEntryPointFunctionData, BGSEntryPointFunctionData::Unk_04, Actor, TESFile, BGSPerk: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slots 00 to 04
// BGSEntryPointFunctionData::Unk_04: OBSERVED; NG declares it with no parameters, the call passes the actor and the perk entry
// BGSEntryPointFunctionData::unk00, ::unk01, ::unk02, ::unk03: GUESS(low); placeholders that put Unk_04 at slot 04
// RegisterPerkEntry: GUESS(low); the call to the image function at 0x69f950, which the pack names PlayerCharacter::Function69f950
#pragma once

#include <cstdint>

class Actor;
class TESFile;
class BGSPerk;
class BGSEntryPointPerkEntry;

class BGSEntryPointFunctionData
{
public:
    virtual ~BGSEntryPointFunctionData();   // 00
    virtual void unk01();                   // 01
    virtual void unk02();                   // 02
    virtual void unk03();                   // 03
    virtual void Unk_04(Actor* a_actor, BGSEntryPointPerkEntry* a_entry);  // 04
};

void RegisterPerkEntry(Actor* a_actor, BGSEntryPointPerkEntry* a_entry);

class BGSEntryPointPerkEntry
{
public:
    virtual bool CheckConditionFilters(std::uint32_t a_numArgs, void* a_args);  // 00
    virtual std::uint32_t GetFunction();                                         // 01
    virtual BGSEntryPointFunctionData* GetFunctionData() const;                  // 02
    virtual ~BGSEntryPointPerkEntry();                                           // 03
    virtual std::uint32_t GetType() const;                                       // 04
    virtual void ClearData();                                                    // 05
    virtual void InitItem(TESFile* a_owner);                                     // 06
    virtual bool Load(TESFile* a_file);                                          // 07
    virtual void SetParent(BGSPerk* a_parent);                                   // 08
    virtual std::uint16_t GetID() const;                                         // 09
    virtual void ApplyPerkEntry(Actor* a_actor);                                 // 0A
};

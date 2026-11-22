// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESTopic, TESTopic::priorityAndJournalIndex, ::ownerBranch, ::ownerQuest, ::topicInfos, ::numTopicInfos, ::firstFileOffset, ::formEditorID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESTopic::ResetTopics: SYMBOLS(fo4-pdb) CRASHLOGGER_PDB(59818@2026.10.24); the NG header has no such method
// TESTopicInfo, TESForm, TESForm::SetAltered: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the virtual slots up to SetAltered
// TESForm::unk01 to TESForm::unk23: GUESS(low); placeholders that put SetAltered at slot 24
// TESTopic::unk00, ::unk38Ptr: GUESS(low); padding for the base classes and the members this function does not touch
#pragma once

#include <cstdint>

class TESForm
{
public:
    virtual ~TESForm();                              // 00
    virtual void unk01();                    // 01
    virtual void unk02();                    // 02
    virtual void unk03();                    // 03
    virtual void unk04();                    // 04
    virtual void unk05();                    // 05
    virtual void unk06();                    // 06
    virtual void unk07();                    // 07
    virtual void unk08();                    // 08
    virtual void unk09();                    // 09
    virtual void unk0A();                    // 0A
    virtual void unk0B();                    // 0B
    virtual void unk0C();                    // 0C
    virtual void unk0D();                    // 0D
    virtual void unk0E();                    // 0E
    virtual void unk0F();                    // 0F
    virtual void unk10();                    // 10
    virtual void unk11();                    // 11
    virtual void unk12();                    // 12
    virtual void unk13();                    // 13
    virtual void unk14();                    // 14
    virtual void unk15();                    // 15
    virtual void unk16();                    // 16
    virtual void unk17();                    // 17
    virtual void unk18();                    // 18
    virtual void unk19();                    // 19
    virtual void unk1A();                    // 1A
    virtual void unk1B();                    // 1B
    virtual void unk1C();                    // 1C
    virtual void unk1D();                    // 1D
    virtual void unk1E();                    // 1E
    virtual void unk1F();                    // 1F
    virtual void unk20();                    // 20
    virtual void unk21();                    // 21
    virtual void unk22();                    // 22
    virtual void unk23();                    // 23
    virtual void SetAltered(bool a_set);        // 24
};

class TESTopicInfo : public TESForm
{
};

class TESTopic
{
public:
    void ResetTopics();

    std::uint8_t unk00[0x34];                     // 00 (TESForm and TESFullName bases)
    std::uint32_t priorityAndJournalIndex;      // 34
    void* ownerBranch;                    // 38
    void* ownerQuest;                     // 40
    TESTopicInfo** topicInfos;            // 48
    std::uint32_t numTopicInfos;        // 50
    std::uint32_t firstFileOffset;      // 54
    void* formEditorID;                   // 58
};
static_assert(sizeof(TESTopic) == 0x60, "TESTopic size");

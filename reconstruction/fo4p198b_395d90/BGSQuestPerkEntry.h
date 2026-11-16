// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: authorized sibling and community declarations
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x395d90, 59 bytes: BGSQuestPerkEntry::ApplyPerkEntry
// BGSQuestPerkEntry::ApplyPerkEntry: SIBLING(fo4-private@1b765c70, author-permission); adapted using target evidence
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Character/BGSPerk.cpp:260
// BGSPerkEntry: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted from include/RE/B/BGSPerkEntry.h
// names: GUESS(low); derived declarations and signatures remain provisional
// MIT License
//
// Copyright (c) 2018 Ryan-rsm-McKenzie
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
#pragma once
#include <cstdint>
class Actor; class TESFile; class BGSPerk;
class TESQuest { public: bool EnsureQuestStarted(bool& delayed, bool value); void SetStage(std::uint16_t stage); };
class BGSPerkEntry {
public:
    virtual bool CheckConditionFilters(std::uint32_t, void*);
    virtual int GetFunction();
    virtual void* GetFunctionData() const;
    virtual ~BGSPerkEntry();
    virtual int GetType() const = 0;
    virtual void ClearData();
    virtual void InitItem(TESFile*);
    virtual bool Load(TESFile*);
    virtual void SetParent(BGSPerk*);
    virtual std::uint16_t GetID() const;
    virtual void ApplyPerkEntry(Actor*) = 0;
    virtual void RemovePerkEntry(Actor*) = 0;
    struct Header { std::uint8_t rank; std::uint8_t priority; std::uint16_t unknown; std::uint32_t reserved; } header;
};
class BGSQuestPerkEntry : public BGSPerkEntry {
public:
    void ApplyPerkEntry(Actor*) override;
    struct Data { TESQuest* quest; std::uint16_t stage; } data;
};

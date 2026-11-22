// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSTextureSet, BGSTextureSet::ClearData, BGSTextureSet::textures, BGSTextureSet::decalData, BGSTextureSet::flags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESTexture, TESTexture::ClearDataComponent: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the virtual slots up to ClearDataComponent
// DecalData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); opaque, sized from the delete call
// DecalData::~DecalData: GUESS(low); the out-of-line callee run before the delete
// BGSTextureSet::unk01, ::unk02, ::unk03: GUESS(low); placeholders that put ClearData at virtual slot 5 (with unk04)
// BGSTextureSet::unk04: GUESS(low); the InitializeData slot, not used here
// activeTag, TagScope: GUESS(low); a thread-local value held at 0x65 while the texture data is cleared
#pragma once

#include <cstdint>
#include <cstddef>

struct DecalData
{
    unsigned char data[0x24];
    ~DecalData();
};

extern __declspec(thread) std::uint32_t activeTag;

struct TagScope
{
    std::uint32_t saved;
    TagScope() : saved(activeTag) { activeTag = 0x65; }
    ~TagScope() { activeTag = saved; }
};

class TESTexture
{
public:
    virtual ~TESTexture();                   // 00
    virtual void InitializeDataComponent();  // 01
    virtual void ClearDataComponent();       // 02

    void* textureName;                       // 08
};

class BGSTextureSet
{
public:
    virtual ~BGSTextureSet();                // 00
    virtual void unk01();                    // 01
    virtual void unk02();                    // 02
    virtual void unk03();                    // 03
    virtual void unk04();                    // 04
    virtual void ClearData();                // 05

    unsigned char unk08[0x38];
    TESTexture textures[8];                  // 40
    DecalData* decalData;                    // C0
    std::uint16_t flags;                     // C8
};

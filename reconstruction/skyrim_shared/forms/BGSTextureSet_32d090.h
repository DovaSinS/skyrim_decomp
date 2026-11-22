// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSTextureSet, BGSTextureSet::InitializeData, BGSTextureSet::textures, BGSTextureSet::decalData, BGSTextureSet::flags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESTexture, TESTexture::InitializeDataComponent: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the virtual slots up to ClearDataComponent
// BGSTextureSet::unk01, ::unk02, ::unk03: GUESS(low); placeholders that put InitializeData at virtual slot 4
// DecalData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); opaque here
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSTextureSet.cpp:30 (similar body; written from the listing, shape coincides)
#pragma once

#include <cstdint>
#include <cstddef>

struct DecalData;

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
    virtual void InitializeData();           // 04

    unsigned char unk08[0x38];
    TESTexture textures[8];                  // 40
    DecalData* decalData;                    // C0
    std::uint16_t flags;                     // C8
};

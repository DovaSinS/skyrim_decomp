// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSHeadPart, BGSHeadPart::InitializeData, BGSHeadPart::flags, BGSHeadPart::type, BGSHeadPart::textureSet, BGSHeadPart::morphs, BGSHeadPart::color, BGSHeadPart::validRaces: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); members the body writes, at NG offsets
// TESModelTri, TESModelTri::InitializeDataComponent: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); size 0x28, only the BaseFormComponent slots up to InitializeDataComponent
// BGSHeadPart::unk01, ::unk02, ::unk03: GUESS(low); placeholders that put InitializeData at virtual slot 4
// BGSHeadPart::unk08: GUESS(low); the base-class region before the flags
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Character/BGSHeadPart.cpp:23 (similar body; written from the listing, shape coincides)
#pragma once

#include <cstdint>
#include <cstddef>

class BGSTextureSet;
class BGSColorForm;
class BGSListForm;

class TESModelTri
{
public:
    virtual ~TESModelTri();                  // 00
    virtual void InitializeDataComponent();  // 01

    unsigned char unk08[0x20];
};

class BGSHeadPart
{
public:
    virtual ~BGSHeadPart();                  // 00
    virtual void unk01();                    // 01
    virtual void unk02();                    // 02
    virtual void unk03();                    // 03
    virtual void InitializeData();           // 04

    unsigned char unk08[0x60];
    std::uint8_t flags;                      // 68
    unsigned char unk69[3];
    std::uint32_t type;                      // 6C
    unsigned char unk70[0x18];
    BGSTextureSet* textureSet;               // 88
    TESModelTri morphs[3];                   // 90
    BGSColorForm* color;                     // 108
    BGSListForm* validRaces;                 // 110
};

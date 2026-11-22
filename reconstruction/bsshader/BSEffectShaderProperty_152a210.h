// Source exposure: mixed (community headers; compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// BSEffectShaderProperty: GUESS(low); the class is the placeholder owner
// ForEachTexture: SYMBOLS(fo4-pdb) COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); BSShaderProperty slot 33
// BSShaderProperty, BSShaderProperty::ForEachVisitor, BSEffectShaderMaterial, NiSourceTexture: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); members and slots only as far as the compared function needs
// ForEachVisitor, Accept, material, sourceTexture, greyscaleTexture: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk00, unk78: GUESS(low); unrecovered storage and slot placeholders
#pragma once

#include <cstdint>

class NiSourceTexture;

class BSEffectShaderMaterial
{
public:
    std::uint8_t unk00[0x58];
    NiSourceTexture* sourceTexture;
    NiSourceTexture* greyscaleTexture;
};

class BSShaderProperty
{
public:
    class ForEachVisitor
    {
    public:
        virtual ~ForEachVisitor();
        virtual std::uint32_t Accept(NiSourceTexture* a_texture) = 0;
    };
};

class BSEffectShaderProperty
{
public:
    std::int32_t ForEachTexture(BSShaderProperty::ForEachVisitor& a_visitor);  // compared: 0x152a210

    std::uint8_t unk00[0x78];
    BSEffectShaderMaterial* material;
};

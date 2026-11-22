// Source exposure: mixed (community headers; compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// BSLightingShaderProperty: GUESS(low); the class is the placeholder owner
// RegisterStreamables: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb); a virtual (slot 0x1A) in the image, declared non-virtual here because only this body is compared
// BSShaderProperty, BSLightingShaderMaterialBase, BSTextureSet, NiStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); members and slots only as far as the compared function needs
// material, textureSet, RegisterStreamables: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); material at 0x78 in BSShaderProperty, textureSet at 0x78 in the material
// unk00, unk00_mat, unk01 to unk19: GUESS(low); unrecovered storage and slot placeholders
#pragma once

#include <cstdint>

class NiStream;

class BSTextureSet
{
public:
    virtual ~BSTextureSet();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual void unk07();
    virtual void unk08();
    virtual void unk09();
    virtual void unk0A();
    virtual void unk0B();
    virtual void unk0C();
    virtual void unk0D();
    virtual void unk0E();
    virtual void unk0F();
    virtual void unk10();
    virtual void unk11();
    virtual void unk12();
    virtual void unk13();
    virtual void unk14();
    virtual void unk15();
    virtual void unk16();
    virtual void unk17();
    virtual void unk18();
    virtual void unk19();
    virtual bool RegisterStreamables(NiStream& a_stream);
};

class BSLightingShaderMaterialBase
{
public:
    std::uint8_t unk00_mat[0x78];
    BSTextureSet* textureSet;
};

class BSShaderProperty
{
public:
    bool RegisterStreamables(NiStream& a_stream);

    std::uint8_t unk00[0x78];
    BSLightingShaderMaterialBase* material;
};

class BSLightingShaderProperty : public BSShaderProperty
{
public:
    bool RegisterStreamables(NiStream& a_stream);  // compared: 0x1518b80
};

// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESBoundObject: GUESS(low); the class is the placeholder owner, the function is a static helper of another class
// GetFormAsBipedModel: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb); TESBipedModelForm::GetFormAsBipedModel in the PDB
// TESForm, TESForm::formType: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the type byte, at offset 0x1A
// TESBipedModelForm: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); opaque here
// TESObjectARMO, TESObjectARMO::bipedComponent: GUESS(low); armour form whose biped component sits at offset 0xB0
// kArmor: GUESS(low); form type value 0x1A
#pragma once

#include <cstdint>
#include <cstddef>

class TESForm
{
public:
    unsigned char unk00[0x1A];
    std::uint8_t formType;  // 1A
};

class TESBipedModelForm
{
public:
    unsigned char unk00[8];
};

class TESObjectARMO : public TESForm
{
public:
    unsigned char unk1B[0xB0 - 0x1B];
    TESBipedModelForm bipedComponent;  // B0
};

class TESBoundObject
{
public:
    static TESBipedModelForm* GetFormAsBipedModel(TESForm* form);  // compared: 0x1df590
};

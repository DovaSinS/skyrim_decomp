// Source exposure: binary-analysis (pinned image listing only).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BSShaderProperty::CanMerge: SYMBOLS(fo4-pdb) CRASHLOGGER_PDB(59818@2026.10.24)
// BSShaderProperty, BSShaderMaterialBase: STANDIN GUESS(low); only the members CanMerge touches
// BSShaderProperty::shaderFlags38, BSShaderProperty::material78, BSShaderMaterialBase::IsEqual: GUESS(low)
#pragma once

#include <cstdint>

class BSShaderProperty;

class BSShaderMaterialBase
{
public:
    virtual ~BSShaderMaterialBase();
    virtual void unk01();
    virtual void unk02();
    virtual bool IsEqual(const BSShaderMaterialBase* other) const;
};

class BSShaderProperty
{
public:
    bool CanMerge(const BSShaderProperty* other) const;

private:
    std::uint8_t unk00[0x38];
    std::uint64_t shaderFlags38;
    std::uint8_t unk40[0x38];
    BSShaderMaterialBase* material78;
};

// Source exposure: mixed (community headers; compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// BSShaderMaterial, DoIsCopy, Create, CopyMembers, ComputeCRC32, GetDefault, GetFeature, GetType, texCoordOffset, texCoordScale: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSShaderMaterial::DoIsCopy: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPoint2: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// refCountPad: GUESS(low); the intrusive reference count word
#pragma once

#include <cstdint>
#include <cstddef>

struct NiPoint2
{
    float x;
    float y;
};

class BSShaderMaterial
{
public:
    virtual ~BSShaderMaterial();
    virtual BSShaderMaterial* Create();
    virtual void CopyMembers(BSShaderMaterial* a_other);
    virtual bool DoIsCopy(BSShaderMaterial* a_other);
    virtual std::uint32_t ComputeCRC32();
    virtual BSShaderMaterial* GetDefault();
    virtual std::uint32_t GetFeature() const;
    virtual std::uint32_t GetType() const;

    std::uint32_t refCountPad;
    NiPoint2 texCoordOffset[2];
    NiPoint2 texCoordScale[2];
    std::uint32_t hashKey;
    std::uint32_t unk30;
    std::uint32_t unk34;
};
static_assert(offsetof(BSShaderMaterial, texCoordScale) == 0x1C, "texCoordScale offset");

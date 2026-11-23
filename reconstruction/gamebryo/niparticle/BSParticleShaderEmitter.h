// Source exposure: mixed (community declarations and the contributor-owned pack).
// 0x2a0ba0 compared function
// Code origin: original reconstruction from binary analysis; no external implementation code copied.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Base form: shared header declarations/NiRefObject.h for NiRefObject.
// BSParticleShaderEmitter, BSParticleShaderEmitter::~BSParticleShaderEmitter, BSParticleShaderEmitter::GetBoundsObject, BSParticleShaderEmitter::Generate: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiAVObject, NiPoint3: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown10: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include "declarations/NiRefObject.h"

class NiAVObject;
class NiPoint3;

class BSParticleShaderEmitter : public NiRefObject
{
public:
    virtual ~BSParticleShaderEmitter();  // compared: 0x2a0ba0  // slot 00
    virtual NiAVObject* GetBoundsObject();  // 02
    virtual bool Generate(bool a_arg1, NiPoint3& a_arg2, NiPoint3& a_arg3) = 0;  // 03
    BSParticleShaderEmitter();

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown10[0xEC0];  // 10
};
static_assert(sizeof(BSParticleShaderEmitter) == 0xED0, "BSParticleShaderEmitter size");

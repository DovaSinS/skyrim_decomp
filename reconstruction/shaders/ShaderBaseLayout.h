// Build: sse-steam-1-7-104
// Evidence: findings/ghidra-import.md
// Source exposure: mixed (community declarations and local RTTI analysis).
// Drafted by GPT-6.1 Sol; p155 shader inheritance representation.
// Labels: v2
// Adapted declarations: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a; MIT.
// Declaration source: include/RE/B/BSShader.h
// BSShader: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ShaderBaseLayout: GUESS(medium) STANDIN
// Original declarations derived from the pinned community sources. No implementation bodies copied. Omitted methods are not reconstructed.
// Fields are represented individually; compiler alignment supplies alignment space.
// Layout assertions establish representation only, not byte matches or behavior.
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
#include <cstddef>
#include "ShaderRefLayout.h"
#include "NiBoneMatrixSetterLayout.h"
#include "ReloadShaderLayout.h"
#include "ShaderTableLayout.h"
namespace ResearchLayouts {
class ShaderBaseLayout : public ShaderRefLayout, public NiBoneMatrixSetterLayout, public ReloadShaderLayout {
public:
    ShaderBaseLayout();
    ~ShaderBaseLayout() override;
    std::int32_t shaderType;
    ShaderTableLayout vertexShaders;
    ShaderTableLayout pixelShaders;
    const char* fxpFilename;
};
static_assert(sizeof(ShaderBaseLayout) == 0x90, "shader represented size");
static_assert(offsetof(ShaderBaseLayout, shaderType) == 0x20, "shader type offset");
static_assert(offsetof(ShaderBaseLayout, vertexShaders) == 0x28, "vertex table offset");
static_assert(offsetof(ShaderBaseLayout, pixelShaders) == 0x58, "pixel table offset");
static_assert(offsetof(ShaderBaseLayout, fxpFilename) == 0x88, "filename offset");
}

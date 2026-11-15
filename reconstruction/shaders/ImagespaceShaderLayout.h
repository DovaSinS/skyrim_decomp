// Build: sse-steam-1-7-104
// Evidence: findings/ghidra-import.md
// Source exposure: mixed (community declarations and local RTTI analysis).
// Drafted by GPT-6.1 Sol; p155 shader inheritance representation.
// Labels: v2
// Adapted declarations: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a; MIT.
// Declaration source: include/RE/B/BSImagespaceShader.h
// BSImagespaceShader: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ImagespaceShaderLayout: GUESS(medium) STANDIN
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
#include "ShaderBaseLayout.h"
#include "ImageEffectLayout.h"
namespace ResearchLayouts {
class ImagespaceShaderLayout : public ShaderBaseLayout, public ImageEffectLayout {
public:
    ImagespaceShaderLayout();
    ~ImagespaceShaderLayout() override;
    std::uint64_t unknown120;
    std::uint64_t unknown128;
    std::uint64_t unknown130;
    std::uint64_t unknown138;
    std::uint64_t unknown140;
    std::uint64_t unknown148;
    std::uint64_t unknown150;
    std::uint64_t unknown158;
    std::uint64_t unknown160;
    std::uint64_t unknown168;
    std::uint64_t unknown170;
    std::uint64_t unknown178;
    std::uint64_t unknown180;
    std::uint64_t unknown188;
    std::uint64_t unknown190;
    std::uint64_t unknown198;
    std::uint64_t unknown1A0;
};
static_assert(sizeof(ImagespaceShaderLayout) == 0x1A8, "imagespace shader represented size");
static_assert(offsetof(ImagespaceShaderLayout, unknown120) == 0x120, "imagespace data offset");
}

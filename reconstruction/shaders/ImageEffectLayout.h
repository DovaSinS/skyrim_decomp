// Build: sse-steam-1-7-104
// Evidence: findings/ghidra-import.md
// Source exposure: mixed (community declarations and local RTTI analysis).
// Drafted by GPT-6.1 Sol; p155 shader inheritance representation.
// Labels: v2
// Adapted declarations: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a; MIT.
// Declaration source: include/RE/I/ImageSpaceEffect.h
// Declaration source: include/RE/N/NiTArray.h
// ImageSpaceEffect, NiTArray: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ImageEffectLayout: GUESS(medium) STANDIN
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
namespace ResearchLayouts {
template<class T> class EffectArrayLayout {
public:
    virtual ~EffectArrayLayout();
    T* data;
    std::uint16_t capacity;
    std::uint16_t freeIndex;
    std::uint16_t size;
    std::uint16_t growthSize;
};
class ImageEffectLayout {
public:
    ImageEffectLayout();
    virtual ~ImageEffectLayout();
    bool active;
    bool unknown09;
    EffectArrayLayout<void*> effects;
    EffectArrayLayout<void*> effectParams;
    EffectArrayLayout<void*> effectTextures;
    EffectArrayLayout<void*> effectInputs;
    EffectArrayLayout<std::int32_t> unknown70;
    bool unknown88;
};
static_assert(sizeof(EffectArrayLayout<void*>) == 0x18, "array storage");
static_assert(sizeof(ImageEffectLayout) == 0x90, "image effect size");
static_assert(offsetof(ImageEffectLayout, effects) == 0x10, "effects offset");
static_assert(offsetof(ImageEffectLayout, unknown88) == 0x88, "effect flag offset");
}

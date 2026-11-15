// Build: sse-steam-1-7-104
// Source exposure: mixed (pinned community declarations and local target access/RTTI analysis).
// Drafted by GPT-6.1 Sol; p144 layout preparation, owner awarebayes, 2026-11-15.
// Evidence: findings/represented-layout-preparation.md
// Labels: v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a; include/RE/I/IFormFactory.h; MIT.
// Code origin: adapted data declarations only; no external implementation bodies.
// IFormFactoryLayout: GUESS(medium) STANDIN; represented declaration aliases, not original type identities.
// Field spellings below retain the cited community declarations unless explicitly guessed.
// Omitted methods and pointee semantics are unassessed. Compiler alignment supplies padding.
// Each assertion proves its stated layout property; Mac comparisons cover only the indexed functions.
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
#include <cstddef>
#include <cstdint>
namespace ResearchLayouts {
class IFormFactoryLayout {
public:
    virtual ~IFormFactoryLayout();
};
static_assert(sizeof(IFormFactoryLayout) == 8, "community interface size");
}

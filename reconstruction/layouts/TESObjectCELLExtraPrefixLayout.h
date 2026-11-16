// Build: sse-steam-1-7-104
// Source exposure: mixed (pinned target image, community headers).
// Drafted by GPT-6.1 Terra. Labels: v2
// Code origin: adapted pinned community declarations and target-informed typed prefix stand-ins; no sibling body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a; MIT.
// Adapted type and member spellings use community declarations; prefix models and unlisted
// wrapper/callee names or types remain inferred. The target establishes the addressed member
// offsets and tail callees, not the source names, complete type sizes or member semantics.
// These are partial layouts, not a claim about complete original class declarations.
// Prefix layout names and inferred members: GUESS(low) STANDIN
// Community type and member names: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
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
#include "ExtraDataList.h"
namespace ResearchLayouts {
class TESObjectCELLExtraPrefixLayout : public TESForm, public TESFullName {
public:
    TESGlobal* GetGlobal() const; // Inferred unless supported by community declarations
    unsigned int GetDetachTime() const; // Inferred unless supported by community declarations
    BGSAcousticSpace* GetAcousticSpace() const; // Inferred unless supported by community declarations
    BSSpinLock grassCreateLock;
    BSSpinLock grassTaskLock;
    std::uint16_t cellFlags;
    std::uint16_t cellGameFlags;
    std::uint8_t cellState;
    bool autoWaterLoaded;
    bool cellDetached;
    std::uint8_t pad047;
    ExtraDataList extraList;
};
static_assert(offsetof(TESObjectCELLExtraPrefixLayout, extraList) == 0x48, "target member address");
}

// Build: sse-steam-1-7-104
// Source exposure: mixed (pinned target image, community headers).
// Drafted by GPT-6.1 Terra. Labels: v2
// Code origin: target-informed original member-delegation bodies; GetLinkedRef follows the trivial delegation in CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/T/TESObjectREFR.cpp (MIT). No sibling body reused.
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
// Evidence: findings/target-pin.md.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// GetGlobal: RVA 0x2be5d0, 9 bytes
// GetDetachTime: RVA 0x2be600, 9 bytes
// GetAcousticSpace: RVA 0x2bf300, 9 bytes
#include "TESObjectCELLExtraPrefixLayout.h"
namespace ResearchLayouts {
TESGlobal* TESObjectCELLExtraPrefixLayout::GetGlobal() const { return extraList.GetGlobal(); }
unsigned int TESObjectCELLExtraPrefixLayout::GetDetachTime() const { return extraList.GetDetachTime(); }
BGSAcousticSpace* TESObjectCELLExtraPrefixLayout::GetAcousticSpace() const { return extraList.GetAcousticSpace(); }
}

// Build: sse-steam-1-7-104
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (pinned public base declarations and independent target RTTI/table/target binding).
// Drafted by GPT-6.1 Sol; supplemental public camera and cell prefixes.
// Labels: v2
// Code origin: original narrowed public-data prefix composition, no external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/{T/ThirdPersonState.h,T/TESObjectCELL.h,T/TESCameraState.h,P/PlayerInputHandler.h,T/TESForm.h,T/TESFullName.h}; MIT.
// ThirdPersonState, TESObjectCELL, TESCameraState, PlayerInputHandler, TESForm, TESFullName: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ThirdPersonInputPrefixLayout, CellFullNamePrefixLayout and mirror names: GUESS(medium) STANDIN
// Each48-byte view contains only the two initial public base subobjects at0/32, independently corroborated by the original owner COL/nonvirtual PMD/secondary destructor slot and primary jump target. Later data, total original sizes, virtual methodsets/signatures, instantiability, identity and lifetimes/behavior are unclaimed. No allocation/deletion size supplies layout. Only the two listed compiler adjustors are compared; constructors and primary destruction remain external to that scope. Assertions check represented layout only.
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
// RVA 0x55d450; 9 bytes
// RVA 0x2d3410; 9 bytes
#include "ThirdPersonInputPrefixLayout.h"
namespace ResearchLayouts {
ThirdPersonInputPrefixLayout::ThirdPersonInputPrefixLayout() = default;
CellFullNamePrefixLayout::CellFullNamePrefixLayout() = default;
}

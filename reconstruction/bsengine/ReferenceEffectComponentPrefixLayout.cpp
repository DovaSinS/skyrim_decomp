// Build: sse-steam-1-7-104
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (public component declarations, pinned public temp-effect storage and independent target RTTI/slot analysis).
// Drafted by GPT-6.1 Sol; shared reference-effect primary storage recovery.
// Labels: v2
// Code origin: adapted community storage declarations and original narrowed prefix construction; no external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/{R/ReferenceEffect.h,B/BSTempEffect.h,M/ModelReferenceEffect.h,S/SummonPlacementEffect.h,B/BGSMovableStatic.h,T/TESObjectSTAT.h}; MIT.
// ReferenceEffect, BSTempEffect, ModelReferenceEffect, SummonPlacementEffect, BGSMovableStatic, TESObjectSTAT: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// All ResearchLayouts names ending Layout or PrefixLayout and storage-only member names: GUESS(medium) STANDIN
// ReferenceEffect72 is represented through public BSTempEffect48 fields over the NiRefObject16 prefix, flattening fieldless NiObject ancestry and controller pointer, two32-bit handles, and two booleans. Handles are storage-only views; no ownership/lifetime behavior is claimed. Public explicit padding is omitted and natural alignment gaps remain unassessed.
// The two effect owners expose only their initial reference/graph-holder/event prefix. BGSMovableStatic exposes only its initial FullName/Destructible/BoundObject/ModelTextureSwap components, flattening fieldless TESObjectSTAT ancestry. Later fields/bases, complete original definitions, unassessed methods, original source identity/instantiability and behavior remain unclaimed.
// Independent target RTTI/COL, virtual destructor slots and primary targets agree with all represented offsets. No deletion-size argument supplies a layout. Only listed compiler-generated secondary destructor adjustors are compared; other construction/destruction/methods are outside the claim.
// Typed size/offset assertions are layout checks, not function passes. No raw byte array, invented padding, helper body or emission attribute is introduced.
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
// RVA 0x264450; 9 bytes
// RVA 0x26445c; 9 bytes
// RVA 0x5d87b0; 9 bytes
// RVA 0x5d87bc; 9 bytes
// RVA 0x5e5208; 9 bytes
// RVA 0x5e51fc; 9 bytes
#include "ReferenceEffectComponentPrefixLayout.h"
namespace ResearchLayouts {
BGSMovableStaticRecoveredComponentPrefixLayout::BGSMovableStaticRecoveredComponentPrefixLayout() = default;
ModelReferenceEffectRecoveredComponentPrefixLayout::ModelReferenceEffectRecoveredComponentPrefixLayout() = default;
SummonPlacementEffectRecoveredComponentPrefixLayout::SummonPlacementEffectRecoveredComponentPrefixLayout() = default;
}

// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed (local target analysis, public declarations and permitted sibling).
// Origin: reconstructed from target and sibling hints.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// names: GUESS(low); signatures and type names are hypotheses.
// TESObjectREFR::GetCurrentBiped: SIBLING(fo4-private@1b765c70, author-permission); adapted virtual forwarding.
// TESObjectREFR::Get3D: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); body adapted from src/RE/T/TESObjectREFR.cpp:102; declaration from include/RE/T/TESObjectREFR.h.
// TESObjectREFR::MoveHavok: SIBLING(fo4-private@1b765c70, author-permission); adapted simulation reset.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESObjectREFR.cpp:2436
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESObjectREFR.cpp:3193
// TESObjectREFR and virtual declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted declarations.
// RVA 0x2ef670, 10 bytes; RVA 0x2f9f40, 10 bytes; RVA 0x2f10d0, 34 bytes.
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
#include "TESObjectREFR.h"
const BSTSmartPointer<BipedAnim>& TESObjectREFR::GetCurrentBiped() const { return GetBiped2(); }
NiAVObject* TESObjectREFR::Get3D() const { return Get3D2(); }
void TESObjectREFR::MoveHavok(bool force) { bhkNPCollisionObject::ResetSim(Get3D2(), force); }

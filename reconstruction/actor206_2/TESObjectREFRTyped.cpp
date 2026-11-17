// Build: sse-steam-1-7-104.
// Source exposure: mixed.
// Origin: Original reconstruction informed by target access witnesses and community declarations.
// Drafted by gpt-6.1-terra.
// RVA 0x2f1010, 47 bytes; RVA 0x301500, 49 bytes; RVA 0x301540, 49 bytes.
// Evidence: findings/community-resources.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Layout and ownership are provisional; unspecified declarations only support compilation.
// TESObjectREFRTyped: STANDIN GUESS(low); receiver identity is provisional.
// Labels: v2
//
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

#include "TESObjectREFRTyped.h"
namespace P2062 {
void TESObjectREFRTyped::Function2f1010(float z) { NiPoint3 p{data.location.x,data.location.y,z}; UpdatePosition(p); }
void TESObjectREFRTyped::Function301500() { if (auto s=FindState()) { SetFlag(s->value,false); Notify(); } }
void TESObjectREFRTyped::Function301540() { if (auto s=FindState()) { SetFlag(s->value,true); Notify(); } }
}

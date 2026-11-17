// Build: sse-steam-1-7-104.
// Source exposure: mixed.
// Origin: Original reconstruction informed by target access witnesses and community declarations.
// Drafted by gpt-6.1-terra.
// RVA 0x673cc0, 51 bytes; RVA 0x6aec10, 51 bytes.
// Evidence: findings/community-resources.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Compared methods only; all other declarations support compilation.
// Labels: v2
// ActorGraphFlags, GraphHolder, KeyTable, GraphKey, GetKeyTable, SetBool, Function673cc0, Function6aec10: STANDIN GUESS(low); inferred from receiver offsets and target calls.
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

#include "ActorGraphFlags.h"
namespace P2062 {
void ActorGraphFlags::Function673cc0(bool value) { auto keys=GetKeyTable(); reinterpret_cast<GraphHolder*>(&reference.animationGraphHolder)->SetBool(keys->injured,value); }
void ActorGraphFlags::Function6aec10(bool value) { auto keys=GetKeyTable(); reinterpret_cast<GraphHolder*>(&reference.animationGraphHolder)->SetBool(keys->sprint,value); }
}

// Labels: v2
// Build: sse-steam-1-7-104
// RVA 0x6a6920, 21 bytes: ForwardA.
// RVA 0x6a6960, 21 bytes: ForwardB.
// RVA 0x6a6c90, 21 bytes: ForwardC.
// RVA 0x6a5b00, 30 bytes: ForwardD.
// RVA 0x6a5bc0, 30 bytes: ForwardE.
// RVA 0x6a7020, 30 bytes: ForwardF.
// Evidence: findings/ghidra-import.md
// Origin: original reconstruction; Character class name from CommonLibSSE-NG include/RE/C/Character.h.
// Source exposure: mixed (binary-analysis and community headers).
// Drafted by: gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Only forwarding methods are compared. Callees and parameter types are incomplete guesses.
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
// Character: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// CharacterRuntime: STANDIN GUESS(low)
// ForwardA, ForwardB, ForwardC, ForwardD, ForwardE, ForwardF, GetRuntime, ApplyA, ApplyB, ApplyC, ApplyD, ApplyE, ApplyF: GUESS(low)
#pragma once
class CharacterRuntime { public:
 void ApplyA();
 void ApplyB();
 void ApplyC();
 void ApplyD(void* value);
 void ApplyE(void* value);
 void ApplyF(void* value);
 };
class Character { public:
 CharacterRuntime* GetRuntime();
 void ForwardA();
 void ForwardB();
 void ForwardC();
 void ForwardD(void* value);
 void ForwardE(void* value);
 void ForwardF(void* value);
 };

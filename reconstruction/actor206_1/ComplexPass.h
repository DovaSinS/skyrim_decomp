// ComplexPass: STANDIN GUESS(low); ordinary receiver identity is provisional.
// Build sse-steam-1-7-104. Labels: v2
// Source exposure: mixed (binary-analysis and community-headers).
// Drafted by gpt-6.1-terra. Origin: original reconstruction; community declarations adapted as noted.
// Compared: UpdateCombatControllerSettings, DestroyActorMover, Func261, IsCombatTarget.
// RVA 0x6b15f0, 41 bytes; RVA 0x6b5200, 48 bytes.
// RVA 0x6cc460, 41 bytes; RVA 0x6c9f60, 45 bytes.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Unknown regions and unverified signatures do not assert a complete layout.
// CommonLibSSE-NG MIT licence notice:
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
#include "actors/ActorTargetPrefix.h"
namespace P206Target { class ActorMover { public: virtual ~ActorMover(); }; }
namespace P2061 {
// ComplexPass, ActorVtable, CombatGroup: STANDIN GUESS(low); object and interface identity is provisional.
// ActorMover: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); target owner and destruction semantics require review.
class ComplexPass; struct Item; struct CombatGroup { bool Contains(ComplexPass*); };
struct ActorVtable {
 void* unknown000[90]; void (*AddObject)(ComplexPass*,Item*,void*,int,void*);
 void* unknown091[121]; CombatGroup* (*GetCombatGroup)(ComplexPass*);
 void* unknown213[14]; bool (*IsInCombat)(ComplexPass*);
};
class ComplexPass : public P206Target::ActorTargetPrefix<> {
public:
 // UpdateCombatControllerSettings, DestroyActorMover: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); target primary slots 283 and 293.
 // Func261, IsCombatTarget, UpdateSettings: GUESS(low); names or signature remain provisional.
 void UpdateCombatControllerSettings(); void DestroyActorMover(); void Func261(Item*); bool IsCombatTarget(ComplexPass*); void UpdateSettings();
};
}

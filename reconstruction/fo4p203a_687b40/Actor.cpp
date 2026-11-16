// Build: sse-steam-1-7-104; RVA 0x687b40; 80 bytes
// Labels: v2
// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// Actor::SetRestrained: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:2720
// Actor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/A/Actor.h, ActorState.h, ActorValueOwner.h, ActorMagicCaster.h, include/RE/M/MagicCaster.h and the base declarations in reconstruction/fo4b4c_686600/Actor.h.
// Base declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted from include/RE/A/Actor.h, ActorState.h, ActorValueOwner.h, RE/T/TESObjectREFR.h, TESForm.h, RE/E/ExtraDataList.h, RE/M/MagicTarget.h, RE/B/BSHandleRefObject.h, BSAtomic.h, BSTEvent.h, RE/T/TESNPC.h, TESActorBase.h, TESActorBaseData.h, TESContainer.h, TESSpellList.h, TESAIForm.h, TESFullName.h, TESRaceForm.h, RE/B/BGSKeywordForm.h, BGSAttackDataForm.h, BGSPerkRankArray.h, BGSSkinForm.h, BGSDestructibleObjectForm.h and RE/I/IAnimationGraphManagerHolder.h.
// names: GUESS(low); names and original signatures are tentative.
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
#include "Actor.h"
void Actor::SetRestrained(bool value) { if (value) { SetLifeState(6); StopMoving(1.0f); } else if ((actorState1 & 0x1e00000) == 0xc00000) SetLifeState(0); }

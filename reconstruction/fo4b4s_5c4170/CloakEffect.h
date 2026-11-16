// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-sol.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// Declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted from include/RE/C/CloakEffect.h, RE/A/ActiveEffect.h, ActiveEffectReferenceEffectController.h, RE/R/ReferenceEffectController.h and RE/B/BSSoundHandle.h.
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
// names: GUESS(low); tick import and helper identities inferred from target.
#pragma once
class ActiveEffect; class MagicItem; class Effect; class MagicTarget; class TESBoundObject; class NiNode; class ReferenceEffect;
struct NiPoint3 { float x,y,z; }; class ReferenceEffectController { public: virtual ~ReferenceEffectController(); };
class ActiveEffectReferenceEffectController : public ReferenceEffectController { public: ActiveEffect* effect; unsigned target; NiPoint3 windPoint; };
struct BSSoundHandle { unsigned soundID; bool assumeSuccess; unsigned state; };
class ActiveEffect { public: virtual ~ActiveEffect(); ActiveEffectReferenceEffectController hitEffectController; BSSoundHandle persistentSound; unsigned caster; NiNode* sourceNode; MagicItem* spell; Effect* effect; MagicTarget* target; TESBoundObject* source; void* hitEffects; MagicItem* displacementSpell; float elapsedSeconds, duration, magnitude; unsigned flags, conditionStatus; unsigned short uniqueID, pad86; unsigned castingSource; };
extern "C" __declspec(dllimport) unsigned long long __stdcall GetTickCount64();
class CloakEffect : public ActiveEffect { public: unsigned long long nextTargetCheck; void FindTargets(float); void Update(float); };

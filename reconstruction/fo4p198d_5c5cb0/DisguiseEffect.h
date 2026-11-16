// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// Declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted from include/RE/D/DisguiseEffect.h, RE/A/ActiveEffect.h, ActiveEffectReferenceEffectController.h, RE/R/ReferenceEffectController.h and RE/B/BSSoundHandle.h.
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
// names: GUESS(low); helper identity and signatures need independent review.
#pragma once
class BGSSaveFormBuffer { public: void SaveDataEndian(const void*, unsigned, unsigned, unsigned); };
class ActiveEffect; class MagicItem; class Effect; class MagicTarget; class TESBoundObject; class NiNode; class ReferenceEffect; class BGSLoadFormBuffer { public: void LoadDataEndian(void*, unsigned, unsigned); };
struct NiPoint3 { float x,y,z; };
class ReferenceEffectController { public: virtual ~ReferenceEffectController(); };
class ActiveEffectReferenceEffectController : public ReferenceEffectController { public: ActiveEffect* effect; unsigned target; NiPoint3 windPoint; };
struct BSSoundHandle { unsigned soundID; bool assumeSuccess; unsigned state; };
class ActiveEffect { public: virtual ~ActiveEffect(); void SaveGame(BGSSaveFormBuffer*) const; void FinishLoadGame(BGSLoadFormBuffer*); void LoadGame(BGSLoadFormBuffer*); ActiveEffectReferenceEffectController hitEffectController; BSSoundHandle persistentSound; unsigned caster; NiNode* sourceNode; MagicItem* spell; Effect* effect; MagicTarget* target; TESBoundObject* source; void* hitEffects; MagicItem* displacementSpell; float elapsedSeconds, duration, magnitude; unsigned flags, conditionStatus; unsigned short uniqueID, pad86; unsigned castingSource; };
class DisguiseEffect : public ActiveEffect { public: unsigned state; void SaveGame(BGSSaveFormBuffer*) const; void InitiateDetectionCheck(); void FinishLoadGame(BGSLoadFormBuffer*); void LoadGame(BGSLoadFormBuffer*); };

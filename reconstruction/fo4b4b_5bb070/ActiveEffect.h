// Build: sse-steam-1-7-104; RVA 0x5bb070; 19 bytes; RVA 0x5bcda0; 45 bytes
// Labels: v2
// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling hint, and public declarations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// ActiveEffect::GetVisualsTarget, ActiveEffect::CanFinish: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ActiveEffect.cpp:12
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ActiveEffect.cpp:203
// ActiveEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declaration adapted from include/RE/A/ActiveEffect.h and include/RE/A/ActiveEffectReferenceEffectController.h, include/RE/M/MagicTarget.h.
// names: GUESS(low); original source names are uncertain.
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
class ActiveEffect;
class MagicItem { public: bool IsPermanent() const; };
class MagicTarget { public: virtual ~MagicTarget(); virtual bool AddTarget(void*); virtual void* GetTargetStatsObject(); };
struct Point3 { float x, y, z; };
struct EffectController { virtual ~EffectController(); ActiveEffect* effect; unsigned target; Point3 windPoint; };
struct SoundHandle { unsigned soundID; bool assumeSuccess; unsigned char pad; unsigned short pad2; unsigned state; };
class ActiveEffect {
public:
    virtual void* GetVisualsTarget();
    bool CanFinish() const;
    EffectController hitEffectController;
    SoundHandle persistentSound;
    unsigned caster;
    void* sourceNode;
    MagicItem* spell;
    void* effect;
    MagicTarget* target;
    void* source;
    void* hitEffects;
    void* displacementSpell;
    float elapsedSeconds, duration, magnitude;
    unsigned flags, conditionStatus;
    unsigned short uniqueID, pad86;
    unsigned castingSource;
};

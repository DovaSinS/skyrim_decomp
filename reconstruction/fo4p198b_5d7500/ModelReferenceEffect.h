// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: authorized sibling and community declarations
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x5d7500, 14 bytes: ModelReferenceEffect::GetAttachRoot
// ModelReferenceEffect::GetAttachRoot: SIBLING(fo4-private@1b765c70, author-permission); adapted using target evidence
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ModelReferenceEffect.cpp:219
// ModelReferenceEffect, ReferenceEffect, RefAttachTechniqueInput: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted from include/RE/M/ModelReferenceEffect.h, include/RE/R/ReferenceEffect.h, include/RE/R/RefAttachTechniqueInput.h and related base headers
// names: GUESS(low); declarations and signatures remain provisional
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
class NiAVObject; class NiNode; class TESObjectCELL; class ReferenceEffectController; class TESObjectREFR; class TESRace; class bhkWorld; class BGSArtObject; class BGSArtObjectCloneTask; class BSAnimationGraphManager; class SimpleAnimationGraphManagerLoadingTask;
class NiRefObject { public: virtual ~NiRefObject(); virtual void DeleteThis(); std::uint32_t refCount; };
class NiObject : public NiRefObject {};
class BSTempEffect : public NiObject { public: float lifetime; TESObjectCELL* cell; float age; bool initialized; std::uint32_t effectID; };
class ReferenceEffect : public BSTempEffect {
public:
    virtual NiAVObject* GetAttachRoot();
    ReferenceEffectController* controller;
    std::uint32_t target;
    std::uint32_t aimAtTarget;
    bool finished;
    bool ownController;
};
class IAnimationGraphManagerHolder { public: virtual ~IAnimationGraphManagerHolder(); };
class SimpleAnimationGraphManagerHolder : public IAnimationGraphManagerHolder { public: BSAnimationGraphManager* animationGraphManager; SimpleAnimationGraphManagerLoadingTask* loadingTask; };
class AnimationGraphEventSink { public: virtual ~AnimationGraphEventSink(); };
class AttachTechniqueInput { public: virtual ~AttachTechniqueInput(); virtual void Clear(); NiNode* current3DRoot; NiAVObject* attachedArt; std::uint32_t attachPoint; };
class RefAttachTechniqueInput : public AttachTechniqueInput { public: TESObjectREFR* actor; TESRace* actorRace; bhkWorld* physicsWorld; std::uint32_t collisionFilter; const char* nodeName; };
class ModelReferenceEffect : public ReferenceEffect, public SimpleAnimationGraphManagerHolder, public AnimationGraphEventSink {
public:
    NiAVObject* GetAttachRoot() override;
    RefAttachTechniqueInput hitEffectArtData;
    char* loadGameSubBuffer;
    BGSArtObject* artObject;
    BGSArtObjectCloneTask* cloneTask;
    NiAVObject* artObject3D;
    std::uint32_t flags;
};

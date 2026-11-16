// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// Declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted from include/RE/S/ShaderReferenceEffect.h, RE/R/ReferenceEffect.h, RE/B/BSTempEffect.h, BSTArray.h, BSSoundHandle.h, and RE/N/NiRefObject.h.
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
// names: GUESS(low); names and method signatures require independent review.
#pragma once
class NiAVObject; class NiSourceTexture; class TESBoundObject; class TESEffectShader; class BSEffectShaderData; class TESObjectCELL; class ReferenceEffectController;
template<class T> struct ArrayAllocator { T* data; unsigned capacity; };
struct ArrayBase { unsigned size; };
template<class T> struct Array : ArrayAllocator<T>, ArrayBase {};
class NiRefObject { public: virtual ~NiRefObject(); unsigned refCount; };
class BSTempEffect : public NiRefObject { public: float lifetime; TESObjectCELL* cell; float age; bool initialized; unsigned effectID; };
class ReferenceEffect : public BSTempEffect { public: ReferenceEffectController* controller; unsigned target, aimAtTarget; bool finished, ownController; };
struct BSSoundHandle { unsigned soundID; bool assumeSuccess; unsigned state; };
class ShaderReferenceEffect : public ReferenceEffect {
public:
 struct TextureRequest { unsigned long long unknown; NiSourceTexture* texture; };
 struct ParticleShader { void* property; void* emitter; };
 Array<TextureRequest> textureRequests; Array<NiAVObject*> addonModels; Array<void*> unknownArray; Array<ParticleShader> particleShaders; Array<void*> shaderObjects;
 BSSoundHandle soundHandle; NiSourceTexture* particleShaderTexture; NiSourceTexture* particlePaletteTexture; NiSourceTexture* fillTexture; NiSourceTexture* holesTexture; NiSourceTexture* paletteTexture; NiAVObject* lastRootNode;
 TESBoundObject* wornObject; TESEffectShader* effectData; BSEffectShaderData* effectShaderData; NiAVObject* targetRoot; float alphaTimer, addonAlpha, addonScale, effectShaderAge; unsigned flags, pushCount;
 NiAVObject* Get3D(); void Push();
};

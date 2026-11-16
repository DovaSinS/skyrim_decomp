// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from target and anonymous sibling, community declarations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// names: GUESS(low); names and signatures are hypotheses.
// TESObjectMISC::LoadGame: SIBLING(fo4-private@1b765c70, author-permission); adapted behavior.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESObjectMISC.cpp:241
// TESObjectMISC, TESForm, TESObject, TESBoundObject, TESFullName, TESModel, TESModelTextureSwap, TESTexture, TESIcon, TESValueForm, BaseFormComponent: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/T/TESObjectMISC.h, TESForm.h, TESObject.h, TESBoundObject.h, TESFullName.h, TESModel.h, TESModelTextureSwap.h, TESTexture.h, TESIcon.h, TESValueForm.h and include/RE/B/BaseFormComponent.h.
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
class BGSLoadFormBuffer;
class BaseFormComponent { public: virtual ~BaseFormComponent(); };
class TESForm : public BaseFormComponent { public: void LoadGame(BGSLoadFormBuffer*); void* sourceFiles; std::uint32_t formFlags, formID; std::uint16_t inGameFormFlags; std::uint8_t formType, pad1B; std::uint32_t pad1C; };
class TESObject : public TESForm {};
struct NiNPShortPoint3 { std::int16_t x,y,z; };
class TESBoundObject : public TESObject { public: NiNPShortPoint3 boundMin, boundMax; std::uint32_t pad2C; };
class TESFullName : public BaseFormComponent { public: const char* fullName; };
class TESModel : public BaseFormComponent { public: const char* model; void* textures; std::uint32_t* addons; std::uint16_t numTextures, numAddons; std::uint32_t pad24; };
class TESModelTextureSwap : public TESModel { public: void* alternateTextures; std::uint32_t numAlternateTextures, pad34; };
class TESTexture : public BaseFormComponent { public: const char* textureName; };
class TESIcon : public TESTexture {};
class TESValueForm : public BaseFormComponent { public: void LoadGame(BGSLoadFormBuffer*); std::int32_t value; std::uint32_t pad0C; };
class TESObjectMISC : public TESBoundObject, public TESFullName, public TESModelTextureSwap, public TESIcon, public TESValueForm { public: void LoadGame(BGSLoadFormBuffer*); };

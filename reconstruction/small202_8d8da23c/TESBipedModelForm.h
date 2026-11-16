// TESBipedModelForm, build sse-steam-1-7-104.
// Labels: v2
// Origin: adapted declarations from CommonLibSSE-NG, MIT, b93280e832f263dbef44e44cbe2936622a02f91a.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// TESBipedModelForm: EXE_RTTI
// Compared functions:
// RVA 0x1df480, 47 bytes: TESBipedModelForm::Function1df480.
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
// BaseFormComponent, BSFixedString, TESModel, TESModelTextureSwap, TESBipedModelForm, model, textures, addons, numTextures, numAddons, pad24, alternateTextures, numAlternateTextures, pad34, worldModels: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Function1df480, Apply, value: GUESS(low)
class BaseFormComponent { public: virtual ~BaseFormComponent(); };
class BSFixedString { public: const char* value; };
namespace BSResource { struct ID; }
class BGSTextureSet;
class TESModel : public BaseFormComponent {
public:
 BSFixedString model;
 BSResource::ID* textures;
 std::uint32_t* addons;
 std::uint16_t numTextures;
 std::uint16_t numAddons;
 std::uint32_t pad24;
};
class TESModelTextureSwap : public TESModel {
public:
 struct AlternateTexture;
 void Apply(void* value);
 AlternateTexture* alternateTextures;
 std::uint32_t numAlternateTextures;
 std::uint32_t pad34;
};
class TESBipedModelForm : public BaseFormComponent {
public:
 void Function1df480(void* value);
 TESModelTextureSwap worldModels[2];
};

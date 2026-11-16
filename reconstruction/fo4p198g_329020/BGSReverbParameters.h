// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// BGSReverbParameters::~BGSReverbParameters: SIBLING(fo4-private@1b765c70, author-permission); adapted to observed target behavior.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSReverbParameters.cpp:33
// BGSReverbParameters: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted from include/RE/B/BGSReverbParameters.h, include/RE/B/BSIReverbType.h, include/RE/T/TESForm.h and include/RE/B/BaseFormComponent.h.
// names: GUESS(low); constructor is represented to emit the destructor.
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
class TESFileArray; class BaseFormComponent { public: virtual ~BaseFormComponent(); };
class TESForm : public BaseFormComponent { public: ~TESForm() override; TESFileArray* sourceFiles; unsigned formFlags, formID; unsigned short inGameFormFlags; unsigned char formType; };
class BSIReverbType { public: virtual int DoGetRoomLevel() const = 0; virtual int DoGetRoomHFLevel() const = 0; virtual float DoGetDecayTime() const = 0; virtual float DoGetDecayHFRatio() const = 0; virtual int DoGetReflectionLevel() const = 0; virtual float DoGetReflectionDelay() const = 0; virtual int DoGetReverbLevel() const = 0; virtual float DoGetReverbDelay() const = 0; virtual float DoGetDiffusion() const = 0; virtual float DoGetDensity() const = 0; virtual float DoGetHFReference() const = 0; };
class BGSReverbParameters : public TESForm, public BSIReverbType { public: struct ReverbParams { std::uint16_t decayTime,hfReference; std::int8_t roomFilter,roomHFFilter,reflections,reverb,decayHFRatio,reflectionDelay,reverbDelay,diffusionPct,densityPct; }; BGSReverbParameters(); ~BGSReverbParameters() override; int DoGetRoomLevel() const override; int DoGetRoomHFLevel() const override; float DoGetDecayTime() const override; float DoGetDecayHFRatio() const override; int DoGetReflectionLevel() const override; float DoGetReflectionDelay() const override; int DoGetReverbLevel() const override; float DoGetReverbDelay() const override; float DoGetDiffusion() const override; float DoGetDensity() const override; float DoGetHFReference() const override; ReverbParams data; };
static_assert(sizeof(BGSReverbParameters)==0x38, "reverb layout");

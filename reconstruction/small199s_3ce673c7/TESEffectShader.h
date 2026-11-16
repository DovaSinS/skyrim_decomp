// TESEffectShader, build sse-steam-1-7-104.
// Labels: v2
// Inferred names: GUESS(low)
// Origin: declarations adapted from CommonLibSSE-NG b93280e, MIT; bodies original reconstruction.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Drafted by gpt-6.1-sol, adapting the Terra draft.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0x26cf70, 41 bytes: TESEffectShader::Function26cf70.
// RVA 0x26cfa0, 41 bytes: TESEffectShader::Function26cfa0.
// MIT License
// Copyright (c) 2018 Ryan-rsm-McKenzie
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// TESEffectShader, TESForm, BaseFormComponent, EffectShaderData, Color: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// sourceFiles, formFlags, formID, inGameFormFlags, formType, pad1B, pad1C, data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk00, membraneShaderSourceBlendMode, membraneShaderBlendOperation, membraneShaderZTestFunction, fillTextureEffectColorKey1, fillTextureEffectAlphaFadeInTime, fillTextureEffectFullAlphaTime, fillTextureEffectAlphaFadeOutTime, fillTextureEffectPersistentAlphaRatio, fillTextureEffectAlphaPulseAmplitude, fillTextureEffectAlphaPulseFrequency, fillTextureEffectTextureAnimationSpeedU, fillTextureEffectTextureAnimationSpeedV, edgeEffectFallOff, edgeEffectColor, edgeEffectAlphaFadeInTime, edgeEffectFullAlphaTime, edgeEffectAlphaFadeOutTime, edgeEffectPersistentAlphaRatio, edgeEffectAlphaPulseAmplitude, edgeEffectAlphaPulseFrequency: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function26cf70, Function26cfa0, radiansPerCycle: GUESS(low)
#pragma once
#include <cstdint>
class BaseFormComponent { public: virtual ~BaseFormComponent(); };
class TESForm : public BaseFormComponent { public: void* sourceFiles; std::uint32_t formFlags; std::uint32_t formID; std::uint16_t inGameFormFlags; std::uint8_t formType; std::uint8_t pad1B; std::uint32_t pad1C; };
struct Color { std::uint8_t red, green, blue, alpha; };
struct EffectShaderData {
 std::uint32_t unk00; std::uint32_t membraneShaderSourceBlendMode, membraneShaderBlendOperation, membraneShaderZTestFunction;
 Color fillTextureEffectColorKey1;
 float fillTextureEffectAlphaFadeInTime, fillTextureEffectFullAlphaTime, fillTextureEffectAlphaFadeOutTime, fillTextureEffectPersistentAlphaRatio, fillTextureEffectAlphaPulseAmplitude, fillTextureEffectAlphaPulseFrequency, fillTextureEffectTextureAnimationSpeedU, fillTextureEffectTextureAnimationSpeedV;
 float edgeEffectFallOff; Color edgeEffectColor;
 float edgeEffectAlphaFadeInTime, edgeEffectFullAlphaTime, edgeEffectAlphaFadeOutTime, edgeEffectPersistentAlphaRatio, edgeEffectAlphaPulseAmplitude, edgeEffectAlphaPulseFrequency;
};
constexpr float radiansPerCycle = 6.2831854820251465f;
class TESEffectShader : public TESForm { public: float Function26cf70(float); float Function26cfa0(float); EffectShaderData data; };

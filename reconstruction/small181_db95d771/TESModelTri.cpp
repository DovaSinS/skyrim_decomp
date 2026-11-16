// Labels: v2
// Build: sse-steam-1-7-104
// RVA 0x390cc0, 33 bytes: constructor.
// Evidence: findings/ghidra-import.md
// Origin: original reconstruction; declarations adapted from CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/T/TESModel.h and TESModelTri.h.
// Source exposure: mixed (binary-analysis and community headers).
// Drafted by: gpt-6.1-terra; identity/base repair by gpt-6.1-sol
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Constructor is compared; base constructor and virtual members are declarations only; layouts are per-unit stand-ins.
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
// TESModelTri, TESModel, BaseFormComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// TESModelTri::TESModelTri, TESModel::TESModel: GUESS(low)
// TESModel, BaseFormComponent: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// model, textures, addons, numTextures, numAddons: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#include "TESModelTri.h"
TESModelTri::TESModelTri() {}

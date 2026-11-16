// Build: sse-steam-1-7-104
// BGSDialogueBranch::ClearData, build sse-steam-1-7-104, RVA 0x38cae0, 7 bytes.
// Labels: v2
// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: original reconstruction using target listing and anonymous sibling hints.
// ClearData: SIBLING(fo4-private@1b765c70, author-permission); src/Shared/TESForms/Character/BGSDialogueBranch.cpp:45; adapted behavior.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Semantic names and types: GUESS(low); except where separately attributed.
// BaseFormComponent, TESForm, BGSDialogueBranch and virtual declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); notice below.
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
#pragma once
class BaseFormComponent { public: virtual ~BaseFormComponent(); virtual void InitializeDataComponent() = 0; virtual void ClearDataComponent() = 0; virtual void CopyComponent(BaseFormComponent*); };
class TESForm : public BaseFormComponent { public: virtual void InitializeData(); virtual void ClearData(); };
class BGSDialogueBranch : public TESForm { public: void InitializeData() override; void ClearData() override; };

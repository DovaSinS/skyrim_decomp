// Build: sse-steam-1-7-104; RVA 0x25de70; 21 bytes
// Labels: v2
// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// BGSConstructibleObject::InitializeData: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/BGSConstructibleObject.cpp:109
// BGSConstructibleObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/B/BGSConstructibleObject.h, include/RE/T/TESForm.h, include/RE/T/TESContainer.h and include/RE/T/TESCondition.h.
// names: GUESS(low); names and original signatures are tentative.
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
struct FileContainer { void* array; };
class BaseFormComponent { public: virtual ~BaseFormComponent(); virtual void InitializeDataComponent(); };
class TESForm : public BaseFormComponent { public: FileContainer sourceFiles; unsigned formFlags, formID; unsigned short inGameFlags; unsigned char formType, pad; unsigned pad2; };
class TESContainer : public BaseFormComponent { public: void** containerObjects; unsigned numContainerObjects; };
struct TESCondition { void* head; };
class BGSConstructibleObject : public TESForm { public: TESContainer requiredItems; TESCondition conditions; TESForm* createdItem; void* benchKeyword; void InitializeData(); };

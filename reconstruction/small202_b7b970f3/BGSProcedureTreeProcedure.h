// BGSProcedureTreeProcedure, build sse-steam-1-7-104.
// Labels: v2
// Origin: declarations adapted from CommonLibSSE-NG b93280e832f263dbef44e44cbe2936622a02f91a (MIT); body original.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0x48a840, 50 bytes: BGSProcedureTreeProcedure::sub.
// BGSProcedureTreeProcedure, BGSProcedureBase, BGSTypedItem, BGSProcedureTreeConditionalItem, IProcedureTreeItem, TESCondition, head, conditions, procedure: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// SetProcedure: GUESS(low)
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
struct TESConditionItem;
struct TESCondition { TESConditionItem* head; };
class IProcedureTreeItem { public: virtual ~IProcedureTreeItem(); };
class BGSProcedureTreeConditionalItem : public IProcedureTreeItem { public: TESCondition conditions; };
template<class Child, class Parent> class BGSTypedItem : public Parent {};
class BGSProcedureBase { public: virtual ~BGSProcedureBase(); };
class BGSProcedureTreeProcedure : public BGSTypedItem<BGSProcedureTreeProcedure, BGSProcedureTreeConditionalItem> {
public:
 void SetProcedure(BGSProcedureBase* value);
 BGSProcedureBase* procedure;
};

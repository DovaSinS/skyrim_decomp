// TESConditionItem::Copy, build sse-steam-1-7-104, RVA 0x4a7690, 74 bytes.
// Labels: v2
// Source exposure: mixed (target listing, public declarations, sibling hint).
// Origin: public declarations and anonymous sibling code.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// TESConditionItem::Copy: SIBLING(fo4-private@1b765c70, author-permission); adapted member copy.
// Sibling source: fo4-private@1b765c70 src/Shared/AI/TESConditionItem.cpp:91
// TESConditionItem, CONDITION_ITEM_DATA, FUNCTION_DATA: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declarations adapted from include/RE/T/TESCondition.h.
// Copy, TESParameters, TESForm: GUESS(low); names and signature remain unverified.
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
class TESForm;
struct FUNCTION_DATA { std::uint16_t function, pad02; std::uint32_t pad04; void* params[2]; };
struct CONDITION_ITEM_DATA {
    union { void* global; float value; } comparisonValue;
    std::uint32_t runOnRef;
    std::uint32_t dataID;
    FUNCTION_DATA functionData;
    std::uint8_t flags, object;
};
class TESParameters { public: static void Copy(const FUNCTION_DATA& from, FUNCTION_DATA& to); };
class TESConditionItem {
public:
    void Copy(const TESConditionItem* from, TESForm* owner);
    TESConditionItem* next;
    CONDITION_ITEM_DATA data;
};

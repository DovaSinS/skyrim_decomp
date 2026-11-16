// BGSScene, build sse-steam-1-7-104.
// Labels: v2
// Inferred names: GUESS(low)
// Origin: declarations adapted from CommonLibSSE-NG b93280e, MIT; body original reconstruction.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0x3a8a70, 35 bytes: BGSScene::Function3a8a70.
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
// BGSScene, TESForm, BaseFormComponent, BSTArray, BSTArrayHeapAllocator, BSTArrayBase, TESCondition: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// sourceFiles, formFlags, formID, inGameFormFlags, formType, pad1B, pad1C, phases, actors, actorFlags, actorProgressionFlags, actions, parentQuest, flags, padA4, conditions, isPlaying, unkB1, unkB2, unkB3: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetScene, Function3a8a70: GUESS(low)
#pragma once
#include <cstdint>
class BGSScenePhase; class BGSSceneAction; class TESQuest; class TESConditionItem;
class BaseFormComponent { public: virtual ~BaseFormComponent(); };
class TESForm : public BaseFormComponent { public: void* sourceFiles; std::uint32_t formFlags; std::uint32_t formID; std::uint16_t inGameFormFlags; std::uint8_t formType; std::uint8_t pad1B; std::uint32_t pad1C; };
class BSTArrayHeapAllocator { public: void* _data; std::uint32_t _capacity; };
class BSTArrayBase { public: std::uint32_t _size; };
template <class T> class BSTArray : public BSTArrayHeapAllocator, public BSTArrayBase {};
class TESCondition { public: TESConditionItem* head; };
class BGSScene : public TESForm { public:
    void Function3a8a70(); BGSScene* GetScene();
    BSTArray<BGSScenePhase*> phases; BSTArray<std::uint32_t> actors; BSTArray<std::uint32_t> actorFlags; BSTArray<std::uint32_t> actorProgressionFlags; BSTArray<BGSSceneAction*> actions;
    TESQuest* parentQuest; std::uint32_t flags; std::uint32_t padA4; TESCondition conditions; bool isPlaying; std::uint8_t unkB1; std::uint8_t unkB2; std::uint8_t unkB3;
};

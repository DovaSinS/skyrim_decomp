// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed (local target analysis, public declarations and permitted sibling).
// Origin: reconstructed from target and sibling hints.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// names: GUESS(low); signatures and type names are hypotheses.
// TaskQueueInterface::QueueNodeDetach: SIBLING(fo4-private@1b765c70, author-permission); adapted task construction.
// TaskQueueInterface::QueueActorKnockParalyze: SIBLING(fo4-private@1b765c70, author-permission); adapted task construction.
// Sibling source: fo4-private@1b765c70 src/Game/Misc/TaskQueueInterface.cpp:213
// Sibling source: fo4-private@1b765c70 src/Game/Misc/TaskQueueInterface.cpp:432
// NiRefObject and BSHandleRefObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted reference-count declarations.
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
#include "TESForm.h"
#include <cstdint>
class NiRefObject { public: virtual ~NiRefObject(); virtual void DeleteThis(); volatile long refCount; };
class NiAVObject : public NiRefObject {};
class BSHandleRefObject : public NiRefObject {};
class TESObjectREFR : public TESForm, public BSHandleRefObject {};
class Actor : public TESObjectREFR {};
union PackedTaskData { std::uint32_t integer; void* pointer; };
struct BSPackedTask { PackedTaskData data[16]; };
class TaskQueueInterface {
public:
    void QueueIfActive(BSPackedTask& task);
    void QueueNodeDetach(NiAVObject* object);
    void QueueActorKnockParalyze(Actor* actor);
};

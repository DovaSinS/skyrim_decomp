// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: authorized sibling and community declarations
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x667a80, 69 bytes: TaskQueueInterface::QueueNodeAttach
// TaskQueueInterface::QueueNodeAttach: SIBLING(fo4-private@1b765c70, author-permission); adapted using target evidence
// Sibling source: fo4-private@1b765c70 src/Game/Misc/TaskQueueInterface.cpp:199
// TaskQueueInterface, NiRefObject, NiAVObject, NiNode: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/T/TaskQueueInterface.h and include/RE/N/NiRefObject.h
// names: GUESS(low); task layout and helper signature are provisional
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
#include "TaskQueueInterface.h"
#include <intrin.h>
void TaskQueueInterface::QueueNodeAttach(NiAVObject* child, NiNode* parent, bool firstAvailable, bool updateProperties) {
    BSPackedTask task;
    task.data[0].integer = 4;
    task.data[1].pointer = child;
    task.data[2].pointer = parent;
    task.data[4].boolean = updateProperties;
    task.data[3].boolean = firstAvailable;
    // Intrinsic preserves atomic reference ownership.
    _InterlockedIncrement(&child->refCount);
    // Intrinsic preserves atomic reference ownership.
    _InterlockedIncrement(&parent->refCount);
    QueueIfActive(task);
}

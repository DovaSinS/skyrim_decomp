// Build: sse-steam-1-7-104; RVA 0x29d390; 373 bytes (Add).
// Task: p117_29d390
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by GPT-6.1 Sol; unaccepted candidate.
// Source exposure: mixed (binary-analysis, community-headers).
// Community source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT.
// Adapted event-source algorithms: include/RE/B/BSTEvent.h; allocator interface declarations: include/RE/B/BSTArray.h.
// Array storage, indexed search, append and removal reconstructed from the selected build.
// Specialization identity, helper signatures and event type remain unknown. Only listed functions are compared.
// No runtime behavior or original-source identity is claimed. Other declarations are minimal ABI stand-ins.
// Labels: v2
// LockedSource_F063_29d390, Sink, Event, ArrayFunctor, ArrayStorage, ArrayBase, Lock, Guard: GUESS(low) STANDIN
// Add, Remove, Push, Find, At, Erase, EraseExternal, Reserve, Move, Allocate, Reallocate, Deallocate, Unlock: GUESS(low)
// data, capacity, size, array, owner, count, sinks, pendingRegisters, pendingUnregisters, lock, notifying, ProcessEvent: GUESS(low)
// GetCurrentThreadId: OBSERVED
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
#include "LockedSource_F063_29d390.h"
namespace p117_29d390 {
void LockedSource_F063_29d390::Add(Sink* const sink) {
    if (!sink) return;
    Guard guard(lock);
    if (notifying) {
        if (pendingRegisters.Find(sink) == ~0u) pendingRegisters.Push(sink);
    } else {
        if (sinks.Find(sink) == ~0u) sinks.Push(sink);
    }
    unsigned index = pendingUnregisters.Find(sink);
    if (index != ~0u) pendingUnregisters.Erase(index);
}
}

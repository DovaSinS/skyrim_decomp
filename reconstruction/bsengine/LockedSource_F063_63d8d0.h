// Build: sse-steam-1-7-104; RVA 0x63d8d0; 373 bytes (Add).
// Task: p117_63d8d0
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
// LockedSource_F063_63d8d0, Sink, Event, ArrayFunctor, ArrayStorage, ArrayBase, Lock, Guard: GUESS(low) STANDIN
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
#pragma once
#include "LockedArray_63d8d0.h"
#include <intrin.h>
namespace p117_63d8d0 {
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
struct Lock {
    std::uint32_t owner, count;
    void Unlock() {
        // Order the ownership query after prior protected reads.
        _mm_lfence();
        if (owner == GetCurrentThreadId()) {
            if (count == 1) {
                owner = 0;
                // Publish owner clearance before releasing the recursion count.
                _mm_mfence();
                // Release the final recursive hold atomically.
                _InterlockedCompareExchange(reinterpret_cast<volatile long*>(&count), 0, 1);
            } else {
                // A nested hold releases one recursion level atomically.
                _InterlockedDecrement(reinterpret_cast<volatile long*>(&count));
            }
        }
    }
};
struct Guard { Lock* lock; Guard(Lock&) noexcept; ~Guard() { if (lock) lock->Unlock(); } };
class LockedSource_F063_63d8d0 {
public:
 LockedArray_63d8d0<Sink*> sinks,pendingRegisters,pendingUnregisters;
 Lock lock;
 bool notifying;
 void Add(Sink*);
 void Remove(Sink*);
};
static_assert(sizeof(LockedSource_F063_63d8d0)==0x58,"source layout");
}

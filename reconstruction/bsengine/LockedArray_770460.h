// Build: sse-steam-1-7-104; Supporting pointer-array declarations; append is outside this family claim.
// Task: p117_770460
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
// LockedArray_770460, Sink, Event, ArrayFunctor, ArrayStorage, ArrayBase, Lock, Guard: GUESS(low) STANDIN
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
#include <cstdint>
#include <new>
namespace p117_770460 {
struct Event;
class LockedSource_F063_770460;
struct Sink { virtual ~Sink(); virtual unsigned ProcessEvent(const Event*, LockedSource_F063_770460*)=0; };
struct ArrayFunctor {
 virtual bool Allocate(unsigned,unsigned);
 virtual bool Reallocate(unsigned,unsigned,unsigned,unsigned,unsigned);
 virtual void Deallocate();
 virtual ~ArrayFunctor() {}
 void* array;
 explicit ArrayFunctor(void* object) : array(object) {}
};
struct ArrayBase { unsigned size; void Move(void*,unsigned,unsigned,unsigned,unsigned); unsigned Reserve(ArrayFunctor&&,unsigned,unsigned); };
template<class T> struct ArrayStorage { T* data; unsigned capacity; };
template<class T> inline void Construct(T* destination,const T& value) { ::new(static_cast<void*>(destination)) T(value); }
template<class T> struct LockedArray_770460 : ArrayStorage<T>, ArrayBase {
 unsigned Find(const T& value) const {
  unsigned found=~0u; unsigned count=this->size;
  for(unsigned i=0;i<count;++i) { if(found!=~0u) break; auto* entries=this->data; const unsigned index=i; if(entries[index]==value) found=index; }
  return found;
 }
 T& At(unsigned index) const { return this->data[index]; }
 // The selected append has its own body at the independently extracted append RVA; retain that call boundary while comparing it separately.
 __declspec(noinline) void Push(const T& value) {
  unsigned index=Reserve(ArrayFunctor(this),this->capacity,sizeof(T));
  if(index!=~0u) Construct(this->data+index,value);
 }
 void Erase(unsigned index,unsigned amount=1) {
  unsigned remaining=this->size-index-amount;
  unsigned moved=remaining<amount?remaining:amount;
  Move(this->data,index,this->size-moved,moved,sizeof(T)); this->size-=amount;
 }
 void EraseExternal(unsigned,unsigned);
 T* begin() { return this->size?this->data:nullptr; }
 T* end() { return this->size?this->data+this->size:nullptr; }
 void Clear() { if(this->data) this->size=0; }
};
static_assert(sizeof(LockedArray_770460<Sink*>)==0x18,"pointer array stride");
}

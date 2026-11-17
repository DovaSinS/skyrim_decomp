// Build: sse-steam-1-7-104.
// Source exposure: mixed.
// Origin: Original reconstruction informed by target access witnesses and community declarations.
// Drafted by gpt-6.1-terra.
// RVA 0x301130, 42 bytes; RVA 0x3010a0, 50 bytes; RVA 0x3010e0, 50 bytes;
// Evidence: findings/community-resources.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Declarations besides compared functions support compilation; layout and owner are provisional.
// Labels: v2
// REFRAdditionalTyped: STANDIN GUESS(low); receiver and signatures inferred from accesses.
// ExtraDataList, TESBoundObject, TESObjectREFR: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Record, State, Value, FindRecord, FindState, Resolve, Lookup, GetA, GetB, Read, DefaultValue, Function2e6a40, Function2f6310, Function301130, Function3010a0, Function3010e0: GUESS(low); inferred from target accesses and calls.
//
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
#include "actors/ActorTargetPrefix.h"
namespace P2062 {
struct Value;
struct Record { std::uint64_t unknown0; Value* value; };
struct StateAdditional { Value* GetA(); Value* GetB(); };
struct ExtraListAdditional : P206Target::ExtraDataListPrefix {
  void* FindRecord(); Record* FindState(); void* Resolve();
};
struct TESBoundObject { std::uint8_t unknown0[0x1a]; std::uint8_t formType; };
class REFRAdditionalTyped : public P206Target::ReferencePrefix<ExtraListAdditional> {
public:
 
  void* Function2f6310();
  Value* Function301130();
  Value* Function3010a0();
  Value* Function3010e0();
  void* FindObject();
};
void* Read(void*);
StateAdditional* Lookup(void*);
Value* ReadRecord(Record*);
extern Value DefaultValue;
extern Value OtherDefaultValue;
}

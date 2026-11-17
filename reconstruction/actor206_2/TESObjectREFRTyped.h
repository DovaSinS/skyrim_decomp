// Build: sse-steam-1-7-104.
// Source exposure: mixed.
// Origin: Original reconstruction informed by target access witnesses and community declarations.
// Drafted by gpt-6.1-terra.
// RVA 0x2f1010, 47 bytes; RVA 0x301500, 49 bytes; RVA 0x301540, 49 bytes.
// Evidence: findings/community-resources.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Layout and ownership are provisional; unspecified declarations only support compilation.
// TESObjectREFRTyped: STANDIN GUESS(low); receiver identity is provisional.
// Labels: v2
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
// NiPoint3, TESObjectREFR, OBJ_REFR, ExtraDataList: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// ExtraAnim: GUESS(low); return payload based on observed access.
// Function2f1010, Function2f1050, Function2f1090, Function301500, Function301540, UpdatePosition, FindType, FindState, SetFlag, Notify: GUESS(low); signatures are inferred.
// GetAnimNoteReceiver: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
using NiPoint3 = P206Target::NiPoint3;
struct BSAnimNoteReceiver;
struct ExtraAnim { std::uint64_t unknown0, unknown8; BSAnimNoteReceiver* receiver; };
struct ExtraListRef : P206Target::ExtraDataListPrefix { ExtraAnim* FindType(unsigned); };
struct StateRef { std::uint64_t unknown0, unknown8; void* value; };
class TESObjectREFRTyped : public P206Target::ReferencePrefix<ExtraListRef> {
public:
  BSAnimNoteReceiver* GetAnimNoteReceiver();
  void Function2f1010(float);
  void Function2f1050(float);
  void Function2f1090(float);
  void Function301500();
  void Function301540();
  void UpdatePosition(const NiPoint3&);
  StateRef* FindState();
  void Notify();
};
void SetFlag(void*,bool);
}

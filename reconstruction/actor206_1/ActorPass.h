// ActorPass: STANDIN GUESS(low); receiver identity is provisional.
// P2061 additive Actor declarations for build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (binary-analysis and community-headers).
// Drafted by gpt-6.1-terra. Origin: original reconstruction; community declarations adapted as noted.
// Compared: Function68be20, GetEquippedWeapon, Function690b20, unk_IsInDialogue.
// RVA 0x68be20, 35 bytes; RVA 0x6ca140, 41 bytes.
// RVA 0x690b20, 46 bytes; RVA 0x6a15e0, 46 bytes.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Ordinary-function receiver identity, helper names, and types remain provisional.
// Unaccessed gaps are unknown and do not assert complete object layout.
// CommonLibSSE-NG MIT licence notice:
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
namespace P2061 {
// Actor, ExtraDataList, AIProcess: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); receiver is provisional.
// InventoryData, EquippedEntry, PackageData: STANDIN GUESS(low); accessed shapes are provisional.
struct InventoryData { void* UnknownValue(); };
struct ExtraDataList : P206Target::ExtraDataListPrefix { InventoryData* Inventory(); };
struct EquippedEntry { void* form; };
struct PackageData { std::uint8_t unknown00[0x24]; std::uint8_t kind; };
struct AIProcess { EquippedEntry* EquippedWeapon(bool); PackageData* RunningPackage(); };
// Actor: STANDIN GUESS(low); ordinary receiver identity has not been established.
class ActorPass : public P206Target::ActorTargetPrefix<ExtraDataList, AIProcess> {
public:
 // Function68be20, GetEquippedWeapon, Function690b20, unk_IsInDialogue: GUESS(low); names and signatures provisional.
 void* Function68be20(); void* GetEquippedWeapon(bool leftHand); bool Function690b20(); bool unk_IsInDialogue();
};
}

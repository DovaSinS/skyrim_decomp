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
#include "ActorPass.h"
namespace P2061 {
// Function68be20, GetEquippedWeapon, Function690b20, unk_IsInDialogue: GUESS(low); receiver and callee identity are provisional.
void* ActorPass::Function68be20() { auto* inventory = reference.extraList.Inventory(); if (inventory) return inventory->UnknownValue(); return nullptr; }
void* ActorPass::GetEquippedWeapon(bool leftHand) { if (currentProcess) { auto* item = currentProcess->EquippedWeapon(leftHand); if (item) return item->form; } return nullptr; }
bool ActorPass::Function690b20() { if (currentProcess) { auto* pkg = currentProcess->RunningPackage(); if (pkg && pkg->kind == 0x17) return true; } return false; }
bool ActorPass::unk_IsInDialogue() { if (currentProcess) { auto* pkg = currentProcess->RunningPackage(); if (pkg && pkg->kind == 0x1c) return true; } return false; }
}

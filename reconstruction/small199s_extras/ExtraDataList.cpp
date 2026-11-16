// ExtraDataList accessors, build sse-steam-1-7-104.
// Labels: v2
// Origin: original reconstruction; partial declarations adapted from pinned public CommonLibSSE-NG and CommonLibSSE-po3 headers.
// Source exposure: mixed (local binary analysis and public declarations).
// Drafted by gpt-6.1-sol.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// GPL-3.0 declarations: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944, include/RE/E/ExtraTerminalState.h.
// Public names and all signatures remain inferred; only checked byte matches are claimed.
// Inferred accessor names and stateFlags: GUESS(low)
// Compared functions:
// RVA 0x1635e0, 35 bytes.
// RVA 0x164cf0, 35 bytes.
// RVA 0x164510, 36 bytes.
// RVA 0x164540, 36 bytes.
// RVA 0x164d20, 37 bytes.
// RVA 0x1623e0, 38 bytes.
// RVA 0x169bf0, 41 bytes.
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
#include "ExtraDataList.h"
std::uint8_t ExtraDataList::LockLevel() { const auto* extra=static_cast<ExtraTerminalState*>(GetByType(79)); if (!extra) return 255; return extra->lockLevel; }
std::uint8_t ExtraDataList::Flag0() { const auto* extra=static_cast<ExtraPackage*>(GetByType(25)); return extra ? static_cast<std::uint8_t>(extra->stateFlags & 1) : 0; }
std::uint8_t ExtraDataList::Flag1() { const auto* extra=static_cast<ExtraPackage*>(GetByType(25)); return extra ? static_cast<std::uint8_t>((extra->stateFlags >> 1) & 1) : 0; }
std::uint8_t ExtraDataList::Flag2() { const auto* extra=static_cast<ExtraPackage*>(GetByType(25)); return extra ? static_cast<std::uint8_t>((extra->stateFlags >> 2) & 1) : 0; }
TESForm* ExtraDataList::OwnerFaction() { const auto* extra=static_cast<ExtraOwnership*>(GetByType(33)); return extra && extra->owner->formType==43 ? extra->owner : nullptr; }
TESForm* ExtraDataList::OwnerNPC() { const auto* extra=static_cast<ExtraOwnership*>(GetByType(33)); return extra && extra->owner->formType==11 ? extra->owner : nullptr; }
bool ExtraDataList::HasInteraction() { bool present=false; if (GetByType(147)) present=true; return present; }

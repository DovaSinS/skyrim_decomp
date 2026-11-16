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
#pragma once
#include <cstdint>
// BSExtraData, next, TESForm, sourceFiles, formFlags, formID, inGameFormFlags, formType, ExtraPackage, unk10, index, target, ExtraOwnership, owner, ExtraDataList, GetByType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
class BSExtraData { public: virtual ~BSExtraData(); BSExtraData* next; };
// ExtraTerminalState, flags, lockLevel, pad12, pad14: COMMUNITY(powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944, GPL-3.0)
class ExtraTerminalState : public BSExtraData { public: std::uint8_t flags; std::uint8_t lockLevel; std::uint16_t pad12; std::uint32_t pad14; };
class TESPackage;
// stateFlags: GUESS(low)
class ExtraPackage : public BSExtraData { public: TESPackage* unk10; std::int32_t index; std::uint32_t target; std::uint8_t stateFlags; };
class TESForm { public: virtual ~TESForm(); void* sourceFiles; std::uint32_t formFlags; std::uint32_t formID; std::uint16_t inGameFormFlags; std::uint8_t formType; };
class ExtraOwnership : public BSExtraData { public: TESForm* owner; };
// LockLevel, Flag0, Flag1, Flag2, OwnerFaction, OwnerNPC, HasInteraction: GUESS(low)
class ExtraDataList { public:
 BSExtraData* GetByType(std::uint32_t type);
 std::uint8_t LockLevel(); std::uint8_t Flag0(); std::uint8_t Flag1(); std::uint8_t Flag2();
 TESForm* OwnerFaction(); TESForm* OwnerNPC(); bool HasInteraction();
};

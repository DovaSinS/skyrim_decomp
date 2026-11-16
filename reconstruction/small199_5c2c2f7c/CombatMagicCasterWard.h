// CombatMagicCasterWard, build sse-steam-1-7-104.
// Labels: v2
// Inferred names: GUESS(low)
// Origin: declarations adapted from CommonLibSSE-NG b93280e, MIT; body original reconstruction.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0x834610, 43 bytes: CombatMagicCasterWard::sub.
// MIT License
// Copyright (c) 2018 Ryan-rsm-McKenzie
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// CombatMagicCasterWard, CombatMagicCaster, CombatObject, NiRefObject, AITimer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// LoadGame, cooldownTimer, aiTimer, timer, inventoryItem, magicItem, _refCount, _pad0C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// AITimer::Load: GUESS(low)
#pragma once
#include <cstdint>
class BGSLoadGameBuffer;
class BGSSaveGameBuffer;
class CombatInventoryItemMagic;
class MagicItem;
class NiRefObject { public: virtual ~NiRefObject(); virtual void DeleteThis(); std::uint32_t _refCount; std::uint32_t _pad0C; };
class CombatObject : public NiRefObject { public: virtual std::uint32_t GetObjectType(); virtual void SaveGame(BGSSaveGameBuffer*); virtual void LoadGame(BGSLoadGameBuffer*); };
class CombatMagicCaster : public CombatObject { public: void LoadGame(BGSLoadGameBuffer*) override; CombatInventoryItemMagic* inventoryItem; MagicItem* magicItem; };
struct AITimer { void Load(BGSLoadGameBuffer*); float aiTimer; float timer; };
class CombatMagicCasterWard : public CombatMagicCaster { public: void LoadGame(BGSLoadGameBuffer*) override; AITimer cooldownTimer; };

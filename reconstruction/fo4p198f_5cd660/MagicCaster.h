// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: authorized sibling and community declarations
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x5cd660, 72 bytes: MagicCaster::FinishLoadGame
// MagicCaster::FinishLoadGame: SIBLING(fo4-private@1b765c70, author-permission); adapted using target evidence
// Sibling source: fo4-private@1b765c70 src/Game/Magic/MagicCaster.cpp:379
// MagicCaster, MagicCaster::PrepareSound, MagicCaster::currentSpell: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/M/MagicCaster.h
// names: GUESS(low); signature and local iteration are provisional
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
class MagicItem; class Actor; class ActiveEffect; class TESObjectREFR; class NiNode; class BGSSaveGameBuffer; class BGSLoadGameBuffer;
namespace MagicSystem { enum class SoundID : int {}; enum class CannotCastReason : int {}; enum class CastingSource : int {}; }
struct BSSoundHandle { std::uint32_t soundID; bool assumeSuccess; std::uint32_t state; };
template<class T> struct BSTArray { T* data; std::uint32_t capacity; std::uint32_t pad; std::uint32_t size; std::uint32_t pad2; };
class MagicCaster {
public:
 virtual ~MagicCaster();
 virtual void CastSpellImmediate(MagicItem*, bool, TESObjectREFR*, float, bool, float, Actor*);
 virtual void FindTouchTarget();
 virtual void RequestCastImpl();
 virtual bool StartChargeImpl();
 virtual bool StartReadyImpl();
 virtual void StartCastImpl();
 virtual void FinishCastImpl();
 virtual void InterruptCastImpl(bool);
 virtual void SpellCast(bool, std::uint32_t, MagicItem*);
 virtual bool CheckCast(MagicItem*, bool, float*, MagicSystem::CannotCastReason*, bool);
 virtual TESObjectREFR* GetCasterStatsObject() const;
 virtual Actor* GetCasterAsActor() const;
 virtual TESObjectREFR* GetCasterObjectReference(Actor**) const;
 virtual NiNode* GetMagicNode();
 virtual void ClearMagicNode();
 virtual void SetCurrentSpellImpl(MagicItem*);
 virtual void SelectSpellImpl();
 virtual void DeselectSpellImpl();
 virtual void SetSkipCheckCast();
 virtual void SetCastingTimerForCharge();
 virtual MagicSystem::CastingSource GetCastingSource() const;
 virtual bool GetIsDualCasting() const;
 virtual void SetDualCasting(bool);
 virtual void SaveGame(BGSSaveGameBuffer*);
 virtual void LoadGame(BGSLoadGameBuffer*);
 virtual void FinishLoadGame(BGSLoadGameBuffer*);
 virtual void PrepareSound(MagicSystem::SoundID, MagicItem*);
 virtual void AdjustActiveEffect(ActiveEffect*, float, bool);
 BSTArray<BSSoundHandle> sounds;
 std::uint32_t desiredTarget;
 std::uint32_t pad24;
 MagicItem* currentSpell;
};

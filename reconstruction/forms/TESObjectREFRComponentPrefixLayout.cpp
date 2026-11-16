// Build: sse-steam-1-7-104
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (pinned community storage declarations; independent target RTTI and exact secondary-slot analysis).
// Drafted by GPT-6.1 Sol; shared TESObjectREFR component prefix recovery.
// Labels: v2
// Code origin: adapted community storage declarations and original narrowed prefix construction. No external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/{T/TESObjectREFR.h,B/BSHandleRefObject.h,N/NiRefObject.h,B/BSTEvent.h,I/IAnimationGraphManagerHolder.h}; MIT.
// TESObjectREFR, BSHandleRefObject, NiRefObject, BSTEventSink, BSAnimationGraphEvent, IAnimationGraphManagerHolder: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// All ResearchLayouts type names ending Layout, StorageLayout or PrefixLayout, and physical mirror member names: GUESS(medium) STANDIN
// TESObjectREFR's represented prefix consists of its public TESForm32, BSHandleRefObject16 and two fieldless eight-byte interface subobjects. Independent target RTTI places these at0,32,48,56 for every selected owner.
// NiRefObject count storage and TESForm component fields are represented by the included pinned community declarations. No owner size is derived from deletion size.
// These declarations represent only the shared initial64-byte component prefix. TESObjectREFR data from64 onward, derived-owner fields, other bases, unassessed method sets, source identity and original instantiability/behavior are unclaimed.
// Fieldless interface methods beyond destructor slot0 are omitted. Intermediate fieldless inheritance is flattened in each owner's prefix view; this is not a complete original owner definition.
// Only listed ordinary compiler-emitted secondary destructor adjustors are compared; constructors, primary destruction and all other methods remain outside the byte-match claim.
// Typed size/offset assertions check represented storage, never a function pass. No raw arrays, explicit padding, helper body or code-emission attribute is introduced.
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
// RVA 0x6bbce4; 9 bytes
// RVA 0x6bbcf0; 9 bytes
// RVA 0x6bbcfc; 9 bytes
// RVA 0x7de724; 9 bytes
// RVA 0x7de730; 9 bytes
// RVA 0x7de73c; 9 bytes
// RVA 0x7dfb54; 9 bytes
// RVA 0x7dfb60; 9 bytes
// RVA 0x7dfb6c; 9 bytes
// RVA 0x7e1058; 9 bytes
// RVA 0x7e1064; 9 bytes
// RVA 0x7e1070; 9 bytes
// RVA 0x64c6b8; 9 bytes
// RVA 0x64c6c4; 9 bytes
// RVA 0x64c6d0; 9 bytes
// RVA 0x73aa9c; 9 bytes
// RVA 0x73aaa8; 9 bytes
// RVA 0x73aab4; 9 bytes
// RVA 0x7e3350; 9 bytes
// RVA 0x7e335c; 9 bytes
// RVA 0x7e3368; 9 bytes
// RVA 0x7e9c7c; 9 bytes
// RVA 0x7e9c88; 9 bytes
// RVA 0x7e9c94; 9 bytes
// RVA 0x7eb4ec; 9 bytes
// RVA 0x7eb4f8; 9 bytes
// RVA 0x7eb504; 9 bytes
// RVA 0x7eccfc; 9 bytes
// RVA 0x7ecd08; 9 bytes
// RVA 0x7ecd14; 9 bytes
// RVA 0x7ef6b4; 9 bytes
// RVA 0x7ef6c0; 9 bytes
// RVA 0x7ef6cc; 9 bytes
// RVA 0x7f51e4; 9 bytes
// RVA 0x7f51f0; 9 bytes
// RVA 0x7f51fc; 9 bytes
// RVA 0x7692b4; 9 bytes
// RVA 0x7692fc; 9 bytes
// RVA 0x769308; 9 bytes
// RVA 0x804c74; 9 bytes
// RVA 0x804c80; 9 bytes
// RVA 0x804c8c; 9 bytes
#include "TESObjectREFRComponentPrefixLayout.h"
namespace ResearchLayouts {
ActorReferenceComponentPrefixLayout::ActorReferenceComponentPrefixLayout() = default;
ArrowProjectileReferenceComponentPrefixLayout::ArrowProjectileReferenceComponentPrefixLayout() = default;
BarrierProjectileReferenceComponentPrefixLayout::BarrierProjectileReferenceComponentPrefixLayout() = default;
BeamProjectileReferenceComponentPrefixLayout::BeamProjectileReferenceComponentPrefixLayout() = default;
ChainExplosionReferenceComponentPrefixLayout::ChainExplosionReferenceComponentPrefixLayout() = default;
CharacterReferenceComponentPrefixLayout::CharacterReferenceComponentPrefixLayout() = default;
ConeProjectileReferenceComponentPrefixLayout::ConeProjectileReferenceComponentPrefixLayout() = default;
ExplosionReferenceComponentPrefixLayout::ExplosionReferenceComponentPrefixLayout() = default;
FlameProjectileReferenceComponentPrefixLayout::FlameProjectileReferenceComponentPrefixLayout() = default;
GrenadeProjectileReferenceComponentPrefixLayout::GrenadeProjectileReferenceComponentPrefixLayout() = default;
HazardReferenceComponentPrefixLayout::HazardReferenceComponentPrefixLayout() = default;
MissileProjectileReferenceComponentPrefixLayout::MissileProjectileReferenceComponentPrefixLayout() = default;
PlayerCharacterReferenceComponentPrefixLayout::PlayerCharacterReferenceComponentPrefixLayout() = default;
ProjectileReferenceComponentPrefixLayout::ProjectileReferenceComponentPrefixLayout() = default;
}

// Build: sse-steam-1-7-104
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (pinned community and permitted FNV sibling declarations; independent target RTTI/slot/transfer analysis).
// Drafted by GPT-6.1 Sol; shared collision-filter layout recovery.
// Labels: v2
// Code origin: adapted declarations and original narrowed owner-prefix construction; no external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/H/{hkBaseObject,hkReferencedObject,hkpCollisionFilter,hkpCollidableCollidableFilter,hkpShapeCollectionFilter,hkpRayShapeCollectionFilter,hkpRayCollidableFilter,hkpEntityListener}.h; MIT.
// Declaration source: momusdigital/fnv_decomp@91e1b6e8d8bb0f9a33e8cf88e77268757449e0a6 include/hkpConstraintListener.h; maintainer permission.
// hkBaseObject, hkReferencedObject, hkpCollisionFilter, hkpCollidableCollidableFilter, hkpShapeCollectionFilter, hkpRayShapeCollectionFilter, hkpRayCollidableFilter, hkpEntityListener: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// memSizeAndFlags, referenceCount, pad0C, pad30, pad34, type, pad3C, pad40, pad44, GetClassType, CalcContentStatistics, IsCollisionEnabled, NumShapeKeyHitsLimitBreached, Init, EntityAddedCallback, EntityRemovedCallback, EntityShapeSetCallback, EntitySetMotionTypeCallback, EntityDeletedCallback: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// hkpConstraintListener, ConstraintAddedCallback, ConstraintRemovedCallback: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
// All ResearchLayouts class/struct names ending Layout and PrefixLayout and forward-declared type spellings: GUESS(medium) STANDIN
// hkpConstrainedSystemFilter, hkpConstraintCollisionFilter, hkpDisableEntityCollisionFilter, hkpCollisionFilterList, hkpGroupCollisionFilter, hkpGroupFilter, hkpNullCollisionFilter, hkpPairCollisionFilter, bhkCollisionFilter, Clear1nTracksFilter, NeverCollideFilter: EXE_RTTI
// CollisionFilterLayout represents the pinned community collision-filter storage and its interfaces, not any derived owner's data tail.
// Owner prefix views represent that ancestor at offset0; constrained/disable prefixes additionally represent their trailing fieldless listener contract at72.
// The constraint filter's intervening PairCollisionFilter data suffix and listener at96 are deliberately unassessed and omitted; its offset96 adjustor is not included.
// bhk singleton/data bases and all other owner-specific data tails are omitted. Assertions cover only represented prefixes; no whole-owner size, instantiability or behavior is claimed.
// Unassessed owner methods and listener methods beyond the named declarations are omitted rather than invented.
// Public inheritance comments place some interfaces eight bytes too early; declarations' natural sizes plus target RTTI establish16/24/32/40, which are independently checked for every target.
// The FNV listener declaration is a reuse source, not evidence about Skyrim. Target RTTI independently binds its identity and start offset; no claim about a complete original listener definition is made.
// No deletion-size argument, added byte array, emission attribute or helper body supplies any layout.
// Only listed ordinary compiler-emitted secondary deleting-destructor adjustors are compared. Constructor, primary destructor and event/filter behavior stay outside the byte-match claim.
// Size and offset assertions are layout checks, not function passes or original-source identity claims.
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
// RVA 0x10a5d2c; 9 bytes
// RVA 0x10a5d38; 9 bytes
// RVA 0x10a5d44; 9 bytes
// RVA 0x10a5d50; 9 bytes
// RVA 0x10a5d5c; 9 bytes
// RVA 0x10a5d68; 9 bytes
// RVA 0x10a5d74; 9 bytes
// RVA 0x10a5d80; 9 bytes
// RVA 0x107f2c8; 9 bytes
// RVA 0x107f2d4; 9 bytes
// RVA 0x107f2e0; 9 bytes
// RVA 0x107f2ec; 9 bytes
// RVA 0xb3cdf8; 9 bytes
// RVA 0xb3ce04; 9 bytes
// RVA 0xb3ce10; 9 bytes
// RVA 0xb3ce1c; 9 bytes
// RVA 0xb3db2c; 9 bytes
// RVA 0xb3db38; 9 bytes
// RVA 0xb3db44; 9 bytes
// RVA 0xb3db50; 9 bytes
// RVA 0xb9bc54; 9 bytes
// RVA 0xb9bc60; 9 bytes
// RVA 0xb9bc6c; 9 bytes
// RVA 0xb9bc78; 9 bytes
// RVA 0xb9bc84; 9 bytes
// RVA 0xb51884; 9 bytes
// RVA 0xb51890; 9 bytes
// RVA 0xb5189c; 9 bytes
// RVA 0xb518a8; 9 bytes
// RVA 0xb9bc90; 9 bytes
// RVA 0xb9bc9c; 9 bytes
// RVA 0xb9bca8; 9 bytes
// RVA 0xb9bcb4; 9 bytes
// RVA 0xb9bcc0; 9 bytes
// RVA 0xb9bccc; 9 bytes
// RVA 0xb9bcd8; 9 bytes
// RVA 0xb9bce4; 9 bytes
// RVA 0xb9bcf0; 9 bytes
// RVA 0xb3c4f4; 9 bytes
// RVA 0xb3c500; 9 bytes
// RVA 0xb3c50c; 9 bytes
// RVA 0xb3c518; 9 bytes
// RVA 0xb364fc; 9 bytes
// RVA 0xb36508; 9 bytes
// RVA 0xb36514; 9 bytes
// RVA 0xb36520; 9 bytes
// RVA 0xb518c0; 9 bytes
// RVA 0xb518cc; 9 bytes
// RVA 0xb518d8; 9 bytes
// RVA 0xb518e4; 9 bytes
#include "CollisionFilterLayout.h"
namespace ResearchLayouts {
ClearOneTracksFilterPrefixLayout::ClearOneTracksFilterPrefixLayout() = default;
NeverCollideFilterPrefixLayout::NeverCollideFilterPrefixLayout() = default;
BhkCollisionFilterPrefixLayout::BhkCollisionFilterPrefixLayout() = default;
CollisionFilterLayout::CollisionFilterLayout() = default;
CollisionFilterListPrefixLayout::CollisionFilterListPrefixLayout() = default;
ConstrainedSystemFilterPrefixLayout::ConstrainedSystemFilterPrefixLayout() = default;
ConstraintCollisionFilterPrimaryPrefixLayout::ConstraintCollisionFilterPrimaryPrefixLayout() = default;
DisableEntityCollisionFilterPrefixLayout::DisableEntityCollisionFilterPrefixLayout() = default;
GroupCollisionFilterPrefixLayout::GroupCollisionFilterPrefixLayout() = default;
GroupFilterPrefixLayout::GroupFilterPrefixLayout() = default;
NullCollisionFilterPrefixLayout::NullCollisionFilterPrefixLayout() = default;
PairCollisionFilterPrimaryPrefixLayout::PairCollisionFilterPrimaryPrefixLayout() = default;
}

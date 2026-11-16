// Build: sse-steam-1-7-104
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (pinned public data declarations and independent target RTTI/secondary slot/target binding).
// Drafted by GPT-6.1 Sol; remaining shared owner-prefix recovery.
// Labels: v2
// Code origin: public data-only storage adaptations and original narrowed prefix composition. No external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/{B/BSTArray.h,B/BSTEvent.h,B/BSAtomic.h,B/BSNavmesh.h,B/BSResourceNiBinaryStream.h,E/ExtraMagicCaster.h,I/IAIWorldLocationHandle.h,I/IPackageData.h,I/IPackageDataAIWorldLocationHandle.h,M/MagicCaster.h,M/MenuControls.h,M/Main.h,N/NavMesh.h,N/NiBinaryStream.h,P/PlayerInputHandler.h,T/TES.h,T/TESCameraState.h,S/SimpleAnimationGraphManagerHolder.h}; MIT.
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/{B/BSTask.h,I/IOTask.h,Q/QueuedFile.h,B/BSResourceEntryDB.h,B/BSTObjectDictionary.h,B/BSPathing.h,P/Pathing.h,F/FindTriangleForLocationFilterCheckDeltaZ.h}; GPL-3.0.
// QueuedFile, BSTask, IOTask, PostFlushNotify, BSTObjectDictionary, BSPathing, BSPathingCellManager, FindTriangleForLocationFilterCheckDeltaZ: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// MagicCaster, SimpleAnimationGraphManagerHolder, TESCameraState, PlayerInputHandler, BSTEventSource, BSTEventSink, ICellAttachDetachEventSource, BSNavmesh, TESChildCell, BSResourceNiBinaryStream, NiBinaryStream, IPackageData, IAIWorldLocationHandle, IPackageDataAIWorldLocationHandle: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// New storage classes and contract names, identity tags, mirror fields and pointee names: GUESS(medium) STANDIN
// Data follows the cited public declarations. Empty singleton/intermediate ancestry and unassessed methods are omitted. Public explicit padding fields are omitted; natural alignment gaps remain unclaimed. Generic contracts represent only actual independently RTTI-bound vptr prefixes, not complete original interfaces.
// Each owner is ONLY its initial contiguous represented subobject prefix through the selected base. Later data/bases, total original size, methodsets/signatures, source identity, lifetimes, behavior and instantiability are unclaimed. A prefix may stop inside its final base. No allocation/deletion size supplies any field or base.
// Every selected secondary table owner, COL offset, nonvirtual PMD, destructor slot and primary target is independently checked against the target. BSPathingCellManager preserves destructor slot10. Only listed compiler-emitted adjustors are compared; constructors and primary destruction remain outside the claim. Assertions prove represented layout only.
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
// RVA 0x5c2878; 9 bytes
// RVA 0x5c2884; 9 bytes
// RVA 0x44e980; 9 bytes
// RVA 0x44eac8; 9 bytes
// RVA 0x44e9d0; 9 bytes
// RVA 0x450d90; 9 bytes
// RVA 0x4537b4; 9 bytes
// RVA 0x44ea9c; 9 bytes
// RVA 0x4537a8; 9 bytes
// RVA 0x152448; 9 bytes
// RVA 0x25d680; 9 bytes
// RVA 0x152374; 9 bytes
// RVA 0x19ba40; 9 bytes
// RVA 0xfd75e0; 9 bytes
// RVA 0xbc6ad0; 9 bytes
// RVA 0x434928; 9 bytes
// RVA 0x11722b4; 9 bytes
// RVA 0x7db01c; 9 bytes
// RVA 0x7db028; 9 bytes
// RVA 0x8fc464; 9 bytes
// RVA 0x8fc470; 9 bytes
// RVA 0x661a8c; 9 bytes
// RVA 0x960b08; 9 bytes
// RVA 0x4c02e8; 9 bytes
// RVA 0x4c02f4; 9 bytes
// RVA 0x5d97c0; 9 bytes
// RVA 0x4deeb0; 9 bytes
// RVA 0x4deebc; 9 bytes
// RVA 0x19ba4c; 9 bytes
// RVA 0x19ba64; 9 bytes
// RVA 0x19ba88; 9 bytes
// RVA 0x19ba94; 9 bytes
// RVA 0x19baa0; 9 bytes
// RVA 0x1b4400; 9 bytes
// RVA 0x1b440c; 9 bytes
#include "QueuedFileDataStorageLayout.h"
namespace ResearchLayouts {
RemainingOwner18f6150PrefixLayout::RemainingOwner18f6150PrefixLayout() = default;
RemainingOwner18c4ab0PrefixLayout::RemainingOwner18c4ab0PrefixLayout() = default;
RemainingOwner18c4d48PrefixLayout::RemainingOwner18c4d48PrefixLayout() = default;
RemainingOwner18c4e80PrefixLayout::RemainingOwner18c4e80PrefixLayout() = default;
RemainingOwner18c5718PrefixLayout::RemainingOwner18c5718PrefixLayout() = default;
RemainingOwner18c5d00PrefixLayout::RemainingOwner18c5d00PrefixLayout() = default;
RemainingOwner18c4de0PrefixLayout::RemainingOwner18c4de0PrefixLayout() = default;
RemainingOwner18c5de0PrefixLayout::RemainingOwner18c5de0PrefixLayout() = default;
RemainingOwner17e2d08PrefixLayout::RemainingOwner17e2d08PrefixLayout() = default;
RemainingOwner180b9f8PrefixLayout::RemainingOwner180b9f8PrefixLayout() = default;
RemainingOwner17e2c48PrefixLayout::RemainingOwner17e2c48PrefixLayout() = default;
RemainingOwner17ef048PrefixLayout::RemainingOwner17ef048PrefixLayout() = default;
RemainingOwner1a6b088PrefixLayout::RemainingOwner1a6b088PrefixLayout() = default;
RemainingOwner1a060a8PrefixLayout::RemainingOwner1a060a8PrefixLayout() = default;
RemainingOwner18bf698PrefixLayout::RemainingOwner18bf698PrefixLayout() = default;
RemainingOwner1a9aaa8PrefixLayout::RemainingOwner1a9aaa8PrefixLayout() = default;
RemainingOwner193ba10PrefixLayout::RemainingOwner193ba10PrefixLayout() = default;
RemainingOwner193b9d0PrefixLayout::RemainingOwner193b9d0PrefixLayout() = default;
RemainingOwner196d8f0PrefixLayout::RemainingOwner196d8f0PrefixLayout() = default;
RemainingOwner196d9f0PrefixLayout::RemainingOwner196d9f0PrefixLayout() = default;
RemainingOwner1914158PrefixLayout::RemainingOwner1914158PrefixLayout() = default;
RemainingOwner197c1e8PrefixLayout::RemainingOwner197c1e8PrefixLayout() = default;
RemainingOwner18d9388PrefixLayout::RemainingOwner18d9388PrefixLayout() = default;
RemainingOwner18f9ce0PrefixLayout::RemainingOwner18f9ce0PrefixLayout() = default;
RemainingOwner18dcdd0PrefixLayout::RemainingOwner18dcdd0PrefixLayout() = default;
RemainingOwner17ef750PrefixLayout::RemainingOwner17ef750PrefixLayout() = default;
RemainingOwner17ef848PrefixLayout::RemainingOwner17ef848PrefixLayout() = default;
RemainingOwner17ef960PrefixLayout::RemainingOwner17ef960PrefixLayout() = default;
RemainingOwner17ef2e8PrefixLayout::RemainingOwner17ef2e8PrefixLayout() = default;
RemainingOwner17ef658PrefixLayout::RemainingOwner17ef658PrefixLayout() = default;
RemainingOwner17f3ea0PrefixLayout::RemainingOwner17f3ea0PrefixLayout() = default;
}

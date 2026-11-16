// Build: sse-steam-1-7-104
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (pinned community data storage and independent target field-operation/subobject analysis).
// Drafted by GPT-6.1 Sol; typed field recovery after component-prefix recovery.
// Labels: v2
// Code origin: adapted community storage declarations, existing original represented-field template bodies and a defaulted owner constructor. No external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/{T/TESObjectREFR.h,B/BGSBodyPartData.h,B/BGSBodyPartDefs.h,H/hkpCharacterProxy.h,H/hkArray.h,H/hkVector4.h,N/NonActorMagicTarget.h,B/BSExtraData.h,M/MagicTarget.h,B/BSTList.h}; MIT.
// TESObjectREFR, OBJ_REFR, BGSBodyPartData, hkpCharacterProxy, hkArray, hkVector4, NonActorMagicTarget, BSExtraData, MagicTarget, BSSimpleList: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// All ResearchLayouts names ending Layout, PrefixLayout or StorageLayout, storage-only member names and physical views: GUESS(medium) STANDIN
// The reference data first pointer at64, body-parts array at80, character-proxy arrays at32/48/64/80 and vector at96, and non-actor target/list fields follow the pinned public declarations; exact target load/address operations independently agree.
// FieldLeaf source containers add no storage and claim no recovered original method signature. Actor name comes from a community anchor; the Explosion ownership hint is not an independently established class identity.
// Explosion ownership hint: GUESS(low) STANDIN
// NonActorMagicTarget has a public64-byte storage model and a separately represented MagicTarget-relative48-byte view: target/list absolute40/48 correspond to relative24/32. Independent target secondary COL16 and exact slots2/7 establish the this context. Scroll's selected getter similarly belongs to its menu-display subobject and reads the public pointer at relative8; no complete ScrollItem layout is claimed.
// These are storage views only. Pointee definitions, original ownership/lifetimes, unassessed method sets, source identity and original instantiability remain unclaimed. Public explicit padding fields are omitted; natural gaps remain unassessed.
// Typed pointer arrays are actual public container/member storage, never raw code or padding arrays. No deletion-size argument supplies fields or bases. A layout assertion alone is not a function pass.
// Only the listed trivial pointer/address operations and one compiler-generated secondary destructor adjustor are compared. Other methods and all construction/destruction behavior remain outside the byte-match claim.
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
// RVA 0x69dcd0; 5 bytes
// RVA 0x7e5160; 5 bytes
// RVA 0x38b6a0; 5 bytes
// RVA 0xb9dd70; 5 bytes
// RVA 0xb9ddd0; 5 bytes
// RVA 0x17ee20; 5 bytes
// RVA 0x5d98f0; 5 bytes
// RVA 0x155350; 5 bytes
// RVA 0x17bf28; 9 bytes
#include "FieldRecoveryStorageLayout.h"
namespace ResearchLayouts {
NonActorMagicTargetRecoveredLayout::NonActorMagicTargetRecoveredLayout() = default;
}
// Build: sse-steam-1-7-104; RVA 0x69dcd0; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf69dcd0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf69dcd0.h"
const void* FieldLeaf69dcd0::Read() { return baseObject; }
// Build: sse-steam-1-7-104; RVA 0x7e5160; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf7e5160, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf7e5160.h"
const void* FieldLeaf7e5160::Read() { return baseObject; }
// Build: sse-steam-1-7-104; RVA 0x38b6a0; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf38b6a0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf38b6a0.h"
const void* FieldLeaf38b6a0::Read() { return &parts; }
// Build: sse-steam-1-7-104; RVA 0xb9dd70; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeafb9dd70, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeafb9dd70.h"
const void* FieldLeafb9dd70::Read() { return &manifold; }
// Build: sse-steam-1-7-104; RVA 0xb9ddd0; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeafb9ddd0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeafb9ddd0.h"
const void* FieldLeafb9ddd0::Read() { return &velocity; }
// Build: sse-steam-1-7-104; RVA 0x17ee20; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf17ee20, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf17ee20.h"
const void* FieldLeaf17ee20::Read() { return targetObject; }
// Build: sse-steam-1-7-104; RVA 0x5d98f0; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf5d98f0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf5d98f0.h"
const void* FieldLeaf5d98f0::Read() { return &activeEffects; }
// Build: sse-steam-1-7-104; RVA 0x155350; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf155350, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf155350.h"
const void* FieldLeaf155350::Read() { return menuDispObject; }
// RVA 0x17bf28; 9 bytes

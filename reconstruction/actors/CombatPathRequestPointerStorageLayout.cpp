// Build: sse-steam-1-7-104
// Source exposure: mixed (public data declarations, authorized game-code sibling role hints and independent target RTTI/field-load evidence).
// Drafted by GPT-6.1 Sol; combat path request pointer prefix recovery.
// Labels: v2
// Code origin: public data declaration adaptation and original narrowed prefix composition; no external implementation body reused.
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/{C/CombatPath.h,C/CombatObject.h,A/AITimer.h}; GPL-3.0.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/{N/NiRefObject.h,B/BSPointerHandle.h}; MIT, retained in included public storage.
// CombatPath, CombatObject, AITimer: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// NiRefObject, ActorHandle: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetRequest, spRequest, CombatPathingRequest: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling role hints: fo4-private@1b765c70 src/Game/AI/Combat/CombatPath.cpp lines19-22,130-140,625-628. These game-code uses treat GetRequest as a CombatPathingRequest pointer and request adapters store it in spRequest. No sibling layout, offset or body is transferred.
// CombatPathRequestPointerStorageLayout, CombatPathDataStorageLayout, CombatPathTimerStorageLayout, CombatPathActorHandleStorageLayout, CombatPathRequestPointeeLayout, requestPointer: GUESS(medium) STANDIN
// The public CombatPath base is fully represented through byte56. The target independently locates its request-policy base at56 and every compared slot5 getter loads8 bytes at56. We represent ONLY the first stored pointer of that request-policy base, flattened into this initial64-byte view. Pointer role is inferred from template ancestry and sibling uses; ownership and exact original signature remain unknown.
// Later request-policy fields, destination base, total concrete owner size, original virtual method sets, instantiability and behavior are unclaimed. No deletion/allocation size supplies a field or prefix. Explicit size/offset assertions check this view only, never a function pass.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// RVA 0x8ec0c0; 5 bytes
// RVA 0x894210; 5 bytes
// RVA 0x8ec3f0; 5 bytes
// RVA 0x8ea5c0; 5 bytes
// RVA 0x8c05e0; 5 bytes
// RVA 0x8a45f0; 5 bytes
// RVA 0x8ea7b0; 5 bytes
// RVA 0x8cc900; 5 bytes
// RVA 0x890980; 5 bytes
// RVA 0x8ea990; 5 bytes
// RVA 0x85ea00; 5 bytes
// RVA 0x8eabc0; 5 bytes
// RVA 0x88acb0; 5 bytes
// RVA 0x894db0; 5 bytes
// RVA 0x8eadb0; 5 bytes
// RVA 0x8a4e50; 5 bytes
// RVA 0x8eb020; 5 bytes
// RVA 0x8cd1d0; 5 bytes
// RVA 0x8eb250; 5 bytes
// RVA 0x8eb4a0; 5 bytes
// RVA 0x8eb670; 5 bytes
// RVA 0x8eb810; 5 bytes
// RVA 0x8d5870; 5 bytes
// RVA 0x8eba60; 5 bytes
// RVA 0x8ebda0; 5 bytes
// RVA 0x8bfde0; 5 bytes
#include "CombatPathRequestPointerStorageLayout.h"
// Build: sse-steam-1-7-104; RVA 0x8ec0c0; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf8ec0c0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf8ec0c0.h"
const void* FieldLeaf8ec0c0::Read() { return requestPointer; }
// Build: sse-steam-1-7-104; RVA 0x894210; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf894210, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf894210.h"
const void* FieldLeaf894210::Read() { return requestPointer; }
// Build: sse-steam-1-7-104; RVA 0x8ec3f0; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf8ec3f0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf8ec3f0.h"
const void* FieldLeaf8ec3f0::Read() { return requestPointer; }
// Build: sse-steam-1-7-104; RVA 0x8ea5c0; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf8ea5c0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf8ea5c0.h"
const void* FieldLeaf8ea5c0::Read() { return requestPointer; }
// Build: sse-steam-1-7-104; RVA 0x8c05e0; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf8c05e0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf8c05e0.h"
const void* FieldLeaf8c05e0::Read() { return requestPointer; }
// Build: sse-steam-1-7-104; RVA 0x8a45f0; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf8a45f0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf8a45f0.h"
const void* FieldLeaf8a45f0::Read() { return requestPointer; }
// Build: sse-steam-1-7-104; RVA 0x8ea7b0; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf8ea7b0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf8ea7b0.h"
const void* FieldLeaf8ea7b0::Read() { return requestPointer; }
// Build: sse-steam-1-7-104; RVA 0x8cc900; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf8cc900, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf8cc900.h"
const void* FieldLeaf8cc900::Read() { return requestPointer; }
// Build: sse-steam-1-7-104; RVA 0x890980; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf890980, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf890980.h"
const void* FieldLeaf890980::Read() { return requestPointer; }
// Build: sse-steam-1-7-104; RVA 0x8ea990; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf8ea990, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf8ea990.h"
const void* FieldLeaf8ea990::Read() { return requestPointer; }
// Build: sse-steam-1-7-104; RVA 0x85ea00; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf85ea00, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf85ea00.h"
const void* FieldLeaf85ea00::Read() { return requestPointer; }
// Build: sse-steam-1-7-104; RVA 0x8eabc0; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf8eabc0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf8eabc0.h"
const void* FieldLeaf8eabc0::Read() { return requestPointer; }
// Build: sse-steam-1-7-104; RVA 0x88acb0; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf88acb0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf88acb0.h"
const void* FieldLeaf88acb0::Read() { return requestPointer; }
// Build: sse-steam-1-7-104; RVA 0x894db0; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf894db0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf894db0.h"
const void* FieldLeaf894db0::Read() { return requestPointer; }
// Build: sse-steam-1-7-104; RVA 0x8eadb0; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf8eadb0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf8eadb0.h"
const void* FieldLeaf8eadb0::Read() { return requestPointer; }
// Build: sse-steam-1-7-104; RVA 0x8a4e50; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf8a4e50, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf8a4e50.h"
const void* FieldLeaf8a4e50::Read() { return requestPointer; }
// Build: sse-steam-1-7-104; RVA 0x8eb020; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf8eb020, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf8eb020.h"
const void* FieldLeaf8eb020::Read() { return requestPointer; }
// Build: sse-steam-1-7-104; RVA 0x8cd1d0; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf8cd1d0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf8cd1d0.h"
const void* FieldLeaf8cd1d0::Read() { return requestPointer; }
// Build: sse-steam-1-7-104; RVA 0x8eb250; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf8eb250, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf8eb250.h"
const void* FieldLeaf8eb250::Read() { return requestPointer; }
// Build: sse-steam-1-7-104; RVA 0x8eb4a0; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf8eb4a0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf8eb4a0.h"
const void* FieldLeaf8eb4a0::Read() { return requestPointer; }
// Build: sse-steam-1-7-104; RVA 0x8eb670; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf8eb670, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf8eb670.h"
const void* FieldLeaf8eb670::Read() { return requestPointer; }
// Build: sse-steam-1-7-104; RVA 0x8eb810; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf8eb810, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf8eb810.h"
const void* FieldLeaf8eb810::Read() { return requestPointer; }
// Build: sse-steam-1-7-104; RVA 0x8d5870; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf8d5870, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf8d5870.h"
const void* FieldLeaf8d5870::Read() { return requestPointer; }
// Build: sse-steam-1-7-104; RVA 0x8eba60; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf8eba60, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf8eba60.h"
const void* FieldLeaf8eba60::Read() { return requestPointer; }
// Build: sse-steam-1-7-104; RVA 0x8ebda0; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf8ebda0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf8ebda0.h"
const void* FieldLeaf8ebda0::Read() { return requestPointer; }
// Build: sse-steam-1-7-104; RVA 0x8bfde0; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf8bfde0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf8bfde0.h"
const void* FieldLeaf8bfde0::Read() { return requestPointer; }

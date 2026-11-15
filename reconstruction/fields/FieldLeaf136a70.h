// Build: sse-steam-1-7-104; RVA 0x136a70; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf136a70, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#pragma once
#include "BoundPairCallableLayout.h"
class FieldLeaf136a70 : public ResearchLayouts::BoundPairCallableLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::BoundPairCallableLayout, callable) == 8, "represented field offset");
static_assert(sizeof(FieldLeaf136a70) == sizeof(ResearchLayouts::BoundPairCallableLayout), "source container adds no storage");

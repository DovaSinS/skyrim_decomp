// Build: sse-steam-1-7-104; RVA 0x318870; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v2.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf318870, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "d32dce69a9cb3105131d364cb4e4543fa5ee03cf23f0284e68e3d0b536b64b75", "version": "2"}
#pragma once
#include "ConcreteObjectFormFactoryLayout.h"
class FieldLeaf318870 : public ResearchLayouts::ConcreteObjectFormFactoryLayout {
public:
    const void* Read();
};
static_assert(offsetof(ResearchLayouts::ConcreteObjectFormFactoryLayout, _name) == 8, "represented field offset");
static_assert(sizeof(FieldLeaf318870) == sizeof(ResearchLayouts::ConcreteObjectFormFactoryLayout), "source container adds no storage");

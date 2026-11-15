// Build: sse-steam-1-7-104; RVA 0xa61830; 9 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v1.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeafa61830, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "18b4a63c204d6ed9e36f576489c89035882cc10c76a79dbe60ed5ea2e1fa5ecf", "version": "1"}
#pragma once
#include "NativeFunctionLayout.h"
class FieldLeafa61830 : public ResearchLayouts::NativeFunctionLayout {
public:
    bool Read();
};
static_assert(offsetof(ResearchLayouts::NativeFunctionLayout, callback) == 80, "represented field offset");
static_assert(sizeof(FieldLeafa61830) == sizeof(ResearchLayouts::NativeFunctionLayout), "source container adds no storage");

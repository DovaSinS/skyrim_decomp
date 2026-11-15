// Build: sse-steam-1-7-104
// Source exposure: binary-analysis (local access, copy, RTTI and size evidence).
// Drafted by GPT-6.1 Sol; p144 box2, owner awarebayes, 2026-11-15.
// Evidence: findings/represented-layout-preparation-2.md
// Labels: v2
// AutoPropertyFunctionLayout: GUESS(medium) STANDIN; represented physical declaration alias.
// Field names and interpretations are guesses unless explicitly labelled otherwise.
// Observed scalar slots are individually supported by accesses, never filler selected only for allocation size.
// Omitted methods, pointee semantics and original complete C++ source remain unassessed.
// A Mac accessor pass proves its own code; size assertions and other field evidence are separate claims.
// BSScript::Internal::AutoPropGetFunction, BSScript::Internal::AutoPropSetFunction: EXE_RTTI
// Existing represented string/type values are reused unchanged; string destructor calls and typed accessors support the fields.
// Code origin: original declarations from target-derived physical facts; no external body or declaration reused.
#pragma once
#include <cstdint>
#include <cstddef>
#include "NativeFunctionLayout.h"
namespace ResearchLayouts {
// objectName, functionName, propertyType, propertyIndex: GUESS(medium) STANDIN; physical fields, meanings unverified.
class AutoPropertyFunctionLayout : public ScriptFunctionLayout { public: ~AutoPropertyFunctionLayout();
    ScriptStringLayout objectName;
    ScriptStringLayout functionName;
    ScriptTypeLayout propertyType;
    std::uint32_t propertyIndex;
};
static_assert(sizeof(AutoPropertyFunctionLayout)==48,"represented size");
static_assert(offsetof(AutoPropertyFunctionLayout,objectName)==16,"observed field offset");
static_assert(offsetof(AutoPropertyFunctionLayout,functionName)==24,"observed field offset");
static_assert(offsetof(AutoPropertyFunctionLayout,propertyType)==32,"observed field offset");
static_assert(offsetof(AutoPropertyFunctionLayout,propertyIndex)==40,"observed field offset");
}

// Build: sse-steam-1-7-104
// Source exposure: binary-analysis (local access, copy, RTTI and size evidence).
// Drafted by GPT-6.1 Sol; p144 box2, owner awarebayes, 2026-11-15.
// Evidence: findings/represented-layout-preparation-2.md
// Labels: v2
// AIWorldInteriorCellLayout: GUESS(medium) STANDIN; represented physical declaration alias.
// Field names and interpretations are guesses unless explicitly labelled otherwise.
// Observed scalar slots are individually supported by accesses, never filler selected only for allocation size.
// Omitted methods, pointee semantics and original complete C++ source remain unassessed.
// A Mac accessor pass proves its own code; size assertions and other field evidence are separate claims.
// BGSAIWorldLocationInteriorCell: EXE_RTTI
// Code origin: original declarations from target-derived physical facts; no external body or declaration reused.
#pragma once
#include <cstdint>
#include <cstddef>
#include "AIWorldLocationLayout.h"
namespace ResearchLayouts {
// cell08, point: GUESS(medium) STANDIN; physical fields, meanings unverified.
class AIWorldInteriorCellLayout : public AIWorldLocationLayout { public: ~AIWorldInteriorCellLayout();
    void* cell08;
    AIWorldPointLayout point;
};
static_assert(sizeof(AIWorldInteriorCellLayout)==32,"represented size");
static_assert(offsetof(AIWorldInteriorCellLayout,cell08)==8,"observed field offset");
static_assert(offsetof(AIWorldInteriorCellLayout,point)==16,"observed field offset");
}

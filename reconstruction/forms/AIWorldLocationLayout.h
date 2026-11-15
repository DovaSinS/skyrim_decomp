// Build: sse-steam-1-7-104
// Source exposure: binary-analysis (local access, copy, RTTI and size evidence).
// Drafted by GPT-6.1 Sol; p144 box2, owner awarebayes, 2026-11-15.
// Evidence: findings/represented-layout-preparation-2.md
// Labels: v2
// AIWorldLocationLayout: GUESS(medium) STANDIN; represented physical declaration alias.
// Field names and interpretations are guesses unless explicitly labelled otherwise.
// Observed scalar slots are individually supported by accesses, never filler selected only for allocation size.
// Omitted methods, pointee semantics and original complete C++ source remain unassessed.
// A Mac accessor pass proves its own code; size assertions and other field evidence are separate claims.
// IAIWorldLocation, BGSAIWorldLocation: EXE_RTTI
// Empty intermediate primary-base identities are omitted; no additional storage is asserted.
// Code origin: original declarations from target-derived physical facts; no external body or declaration reused.
#pragma once
#include <cstdint>
#include <cstddef>
namespace ResearchLayouts {
// AIWorldPointLayout: GUESS(medium) STANDIN
// x, y, z: GUESS(medium); separate floating-point accesses and twelve-byte position transfers.
struct AIWorldPointLayout { float x; float y; float z; };
class AIWorldLocationLayout { public: virtual ~AIWorldLocationLayout(); };
static_assert(sizeof(AIWorldLocationLayout)==8,"own base sized delete");
static_assert(sizeof(AIWorldPointLayout)==12,"three separately accessed floats");
}

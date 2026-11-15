// Build: sse-steam-1-7-104
// Source exposure: binary-analysis (local access, copy, RTTI and size evidence).
// Drafted by GPT-6.1 Sol; p144 box2, owner awarebayes, 2026-11-15.
// Evidence: findings/represented-layout-preparation-2.md
// Labels: v2
// BoundArgumentCallableLayout: GUESS(medium) STANDIN; represented physical declaration alias.
// Field names and interpretations are guesses unless explicitly labelled otherwise.
// Observed scalar slots are individually supported by accesses, never filler selected only for allocation size.
// Omitted methods, pointee semantics and original complete C++ source remain unassessed.
// A Mac accessor pass proves its own code; size assertions and other field evidence are separate claims.
// _Func_impl_no_alloc: EXE_RTTI
// The aggregate models observed copy slots only. Capture meanings and bound callable types remain unknown.
// Code origin: original declarations from target-derived physical facts; no external body or declaration reused.
#pragma once
#include <cstdint>
#include <cstddef>
namespace ResearchLayouts {
// BoundArgumentCallableLayoutValue: GUESS(low) STANDIN; scalar copy-slot aggregate, not a recovered callable type.
// callable, value08, value10, value11, value12, value18: GUESS(low) STANDIN; independently copied slots.
struct BoundArgumentCallableLayoutValue {
    std::uint64_t value08;
    std::uint8_t value10;
    std::uint8_t value11;
    std::uint8_t value12;
    std::uint64_t value18;
};
class BoundArgumentCallableLayout { public: virtual ~BoundArgumentCallableLayout(); BoundArgumentCallableLayoutValue callable; };
static_assert(sizeof(BoundArgumentCallableLayout) == 32, "independent slot-four sized delete");
static_assert(offsetof(BoundArgumentCallableLayout,callable)==8,"target callable address");
static_assert(offsetof(BoundArgumentCallableLayoutValue,value08) == 0, "independent scalar copy offset");
static_assert(offsetof(BoundArgumentCallableLayoutValue,value10) == 8, "independent scalar copy offset");
static_assert(offsetof(BoundArgumentCallableLayoutValue,value11) == 9, "independent scalar copy offset");
static_assert(offsetof(BoundArgumentCallableLayoutValue,value12) == 10, "independent scalar copy offset");
static_assert(offsetof(BoundArgumentCallableLayoutValue,value18) == 16, "independent scalar copy offset");
}

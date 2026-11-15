// Build: sse-steam-1-7-104
// Source exposure: binary-analysis (target access widths, RTTI and sized-delete arguments).
// Drafted by GPT-6.1 Sol; p144 layout preparation, owner awarebayes, 2026-11-15.
// Evidence: findings/represented-layout-preparation.md
// Labels: v2
// Code origin: original minimal declarations from independently checked target field accesses and RTTI.
// TESRegionGrassObject, TESRegionObjectBase: EXE_RTTI
// TESRegionGrassObjectLayout, TESRegionObjectBaseLayout: GUESS(medium) STANDIN
// value08, value10: GUESS(low); each represents a separately observed eight-byte slot.
// Pointer interpretation, pointee types and field meanings are guesses; only widths and offsets are observed.
// No external declaration or body reused. No allocation-sized filler or unknown field array.
// RTTI places TESRegionObjectBase at offset zero; its own deleting leaf observes size 8.
// Grass-object accessors observe slots at offsets 8 and 16; its deleting leaf observes total size 24.
// Size and field assertions do not establish names, behavior or an accepted function match.
// Code origin: represented declaration from reconstruction/forms/TESRegionGrassObjectLayout.h; only include spelling changed.
#pragma once
#include <cstddef>
#include "TESRegionObjectBaseLayout.h"
namespace ResearchLayouts {
class TESRegionGrassObjectLayout : public TESRegionObjectBaseLayout {
public:
    ~TESRegionGrassObjectLayout() override;
    void* value08;
    void* value10;
};
static_assert(sizeof(TESRegionGrassObjectLayout) == 24, "target sized-delete argument");
static_assert(offsetof(TESRegionGrassObjectLayout, value08) == 8, "observed eight-byte access");
static_assert(offsetof(TESRegionGrassObjectLayout, value10) == 16, "observed eight-byte access");
}

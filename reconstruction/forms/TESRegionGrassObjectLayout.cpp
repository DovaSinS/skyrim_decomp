// Build: sse-steam-1-7-104; RVA 0x254510; 43 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented community and authorized sibling declarations and local binary analysis).
// Drafted by tools/deleting_layout_leaf_v13.py (GPT-6.1 Sol).
// Labels: v2
// TESRegionObjectBaseLayout, TESRegionGrassObjectLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Empty destructor bodies are inferred stand-ins for the compared leaf code only.
// Fields and inheritance come from the included represented layout, never an allocation-size array.
// No original field ownership or omitted methods are claimed; only scalar deleting code is compared.
// Shared structural template specializations do not recover original template arguments.
// The static objects request normal compiler emission; initialization and other methods are unassessed.
// Origin: {"family": "scalar-deleting-leaf", "template_digest": "4c61638e3d04464950ae0462af54e9ef246087c8574fb2918dd4022863f1129a", "version": "13"}
// Code origin: original minimal declarations from independently checked target field accesses and RTTI.
void operator delete(void*, unsigned __int64) noexcept;
#include "TESRegionGrassObjectLayout.h"
namespace ResearchLayouts {
inline TESRegionObjectBaseLayout::~TESRegionObjectBaseLayout() {}
inline TESRegionGrassObjectLayout::~TESRegionGrassObjectLayout() {}
}
static_assert(sizeof(ResearchLayouts::TESRegionGrassObjectLayout) == 24, "independently observed allocation size");
static ResearchLayouts::TESRegionGrassObjectLayout object;

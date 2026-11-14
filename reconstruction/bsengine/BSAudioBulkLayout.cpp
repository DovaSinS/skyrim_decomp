// Build: sse-steam-1-7-104; RVA 0xcd62b0; 43 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented community declarations and local binary analysis).
// Drafted by tools/deleting_layout_leaf_v5.py (GPT-6.1 Sol).
// Labels: v2
// BSAudioBulkLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Empty destructor bodies are inferred stand-ins for the compared leaf code only.
// Fields and inheritance come from the included represented layout, never an allocation-size array.
// No original field ownership or omitted methods are claimed; only scalar deleting code is compared.
// Shared structural template specializations do not recover original template arguments.
// The static objects request normal compiler emission; initialization and other methods are unassessed.
// Origin: {"family": "scalar-deleting-leaf", "template_digest": "9b1ff2b938a53e6982a3e22edcebfca6a56340f33700cca5306514736575ac89", "version": "5"}
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/B/BSAudio.h; GPL-3.0.
void operator delete(void*, unsigned __int64) noexcept;
#include "BSAudioBulkLayout.h"
namespace ResearchLayouts {
inline BSAudioBulkLayout::~BSAudioBulkLayout() {}
}
static_assert(sizeof(ResearchLayouts::BSAudioBulkLayout) == 24, "independently observed allocation size");
static ResearchLayouts::BSAudioBulkLayout object;

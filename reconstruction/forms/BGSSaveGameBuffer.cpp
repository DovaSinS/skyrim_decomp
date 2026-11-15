// BGSSaveGameBuffer functions for build sse-steam-1-7-104.
//
// Labels: v2
// Task: p92-s-bgssavegamebuffer
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Evidence: findings/p92-unit-supply-selection.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json (compile this file alone).
// Drafted by Claude Haiku 5.5 (claude-haiku-5-5), starting from
// a tools/skeleton.py skeleton.
// Compared functions:
//   RVA 0x63a2e0, 3 bytes: BGSSaveGameBuffer::GetActor
//   RVA 0x63a2f0, 3 bytes: BGSSaveGameBuffer::GetForm
//   RVA 0x63a300, 3 bytes: BGSSaveGameBuffer::GetReference
// Adapted bodies: none.
// A byte match shows that this source and recipe produce the checked code; it does not verify the
// community names or that the original source looked like this.
#include "BGSSaveGameBuffer.h"

// GetActor: the target returns a null pointer.
Actor* BGSSaveGameBuffer::GetActor()
{
    return nullptr;
}

// GetForm: the target returns a null pointer.
TESForm* BGSSaveGameBuffer::GetForm()
{
    return nullptr;
}

// GetReference: the target returns a null pointer.
TESObjectREFR* BGSSaveGameBuffer::GetReference()
{
    return nullptr;
}

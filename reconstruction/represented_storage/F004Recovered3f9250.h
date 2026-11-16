// Build: sse-steam-1-7-104; RVA 0x3f9250; 52 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (public typed storage and independent target RTTI/call operands).
// Drafted by GPT-6.1 Sol; complete represented storage deleting wrapper.
// Labels: v2
// Code origin: original wrapper emission unit; public data declarations carry their notices below.
// F004Recovered3f9250, object: GUESS(low) STANDIN
// bhkAction: EXE_RTTI
// Full represented storage follows pinned community fields/bases. Virtual method sets and original source identity are unclaimed.
// Destructor remains external. Only the emitted deleting wrapper is compared; allocation size is a consistency check, never layout evidence.
// Independent primary owner vftable slot 0 binds this wrapper, including nonzero destructor slots where present.
// Build: sse-steam-1-7-104
// Source exposure: community-headers
// Labels: v2
// Drafted by GPT-6.1 Sol; public fieldless bhk action ancestry over complete represented storage.
// Code origin: adapted public base declaration only; no implementation body reused.
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/B/bhkAction.h; GPL-3.0.
// SPDX-License-Identifier: GPL-3.0-only
// bhkAction: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// F004Recovered3f9250: GUESS(medium) STANDIN
// Pinned public action ancestry introduces no fields. Original virtual method sets and behavior unclaimed.
// Complete data storage is inherited from the represented base; allocation size is never layout evidence.
#pragma once
#include <cstddef>
#include "BhkSerializableLayout.h"
namespace ResearchLayouts {
class F004Recovered3f9250 : public BhkSerializableLayout {
public:
    ~F004Recovered3f9250() override;
};
static_assert(sizeof(F004Recovered3f9250)==32,"public fieldless ancestry size");
static_assert(offsetof(F004Recovered3f9250,referencedObject)==16,"public inherited hkRefPtr offset");
static_assert(offsetof(F004Recovered3f9250,serializable)==24,"public inherited serialization pointer offset");
}

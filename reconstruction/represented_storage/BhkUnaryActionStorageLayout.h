// Build: sse-steam-1-7-104
// Source exposure: community-headers
// Labels: v2
// Drafted by GPT-6.1 Sol; public fieldless bhk action ancestry over complete represented storage.
// Code origin: adapted public base declaration only; no implementation body reused.
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/B/bhkUnaryAction.h; GPL-3.0.
// SPDX-License-Identifier: GPL-3.0-only
// bhkUnaryAction: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// BhkUnaryActionStorageLayout: GUESS(medium) STANDIN
// Pinned public action ancestry introduces no fields. Original virtual method sets and behavior unclaimed.
// Complete data storage is inherited from the represented base; allocation size is never layout evidence.
#pragma once
#include <cstddef>
#include "BhkActionStorageLayout.h"
namespace ResearchLayouts {
class BhkUnaryActionStorageLayout : public BhkActionStorageLayout {
public:
    ~BhkUnaryActionStorageLayout() override;
};
static_assert(sizeof(BhkUnaryActionStorageLayout)==32,"public fieldless ancestry size");
static_assert(offsetof(BhkUnaryActionStorageLayout,referencedObject)==16,"public inherited hkRefPtr offset");
static_assert(offsetof(BhkUnaryActionStorageLayout,serializable)==24,"public inherited serialization pointer offset");
}

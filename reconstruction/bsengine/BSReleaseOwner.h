// BSReleaseOwner, build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (binary-analysis and community-headers).
// Drafted by GPT-6.1 Sol high; original reconstruction of an owning-pointer guard.
// Only the embedded host is compared; this guard supplies ordinary member cleanup.
// Reference object layout and atomic release are attributed in the included header.
// BSReleaseOwner, reference: GUESS(low) STANDIN
#pragma once
#include "BSHandleRefObject.h"
struct BSReleaseOwner {
    p145::NiRefObject* reference;
    ~BSReleaseOwner() { if (reference) reference->DecRefCount(); }
};

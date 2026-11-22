// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x2bb060 TESObjectCELL::GetEditorId
// Adapted bodies: none
#include "TESObjectCELL_2bb060.h"

// 0x2bb060 TESObjectCELL::GetEditorId
const char* TESObjectCELL::GetEditorId()
{
    if (extraList.Function1704d0()) {
        return extraList.Function1704d0();
    }
    const char* name = pFallbackName;
    if (!(cellFlags & 1)) {
        return name;
    }
    return kEmptyString;
}

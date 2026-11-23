// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: written for this reconstruction from the pinned image listings and the header beside this file.
// Adapted bodies: none
// 0x1e09f0 TESContainer::Function1e09f0
// 0x1e0a00 TESContainer::Function1e0a00
// 0x1e0b10 TESContainer::GetItemCount
// Drafted by v-macrev, assisted by claude-sonnet-5-5.
#include "TESContainer.h"

void TESContainer::Function1e09f0(bool a_allow)
{
    allowStolenItems = a_allow;
}

bool TESContainer::Function1e0a00() const
{
    return allowStolenItems;
}

std::int32_t TESContainer::GetItemCount(TESBoundObject* a_object) const
{
    std::int32_t total = 0;
    for (std::uint32_t i = 0; i < numContainerObjects; ++i) {
        if (containerObjects[i] && containerObjects[i]->obj == a_object) {
            total += containerObjects[i]->count;
        }
    }
    return total;
}

// TESContainer::InitializeDataComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
void TESContainer::InitializeDataComponent()
{
}

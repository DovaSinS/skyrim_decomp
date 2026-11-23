// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: written for this reconstruction from the listing; names from the header; Function1d7e30 name from the task spec.
// Adapted bodies: none
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/bgsidlecollection.cpp:159
// 0x1d7e30 BGSIdleCollection::Function1d7e30
// 0x1d76e0 BGSIdleCollection::InitializeDataComponent
// 0x1d75f0 BGSIdleCollection::Ctor
// Drafted by v-macrev, assisted by claude-haiku-5-5.
#include "BGSIdleCollection.h"

BGSIdleCollection::BGSIdleCollection()
{
    InitializeDataComponent();
}

void BGSIdleCollection::InitializeDataComponent()
{
    idleFlags = 0;
    idleCount = 0;
    idles = nullptr;
    timerCheckForIdle = 0.0f;
}

int BGSIdleCollection::Function1d7e30()
{
    return static_cast<std::uint8_t>(idleFlags) & 1;
}

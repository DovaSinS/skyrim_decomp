// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: written for this reconstruction from the listing; names from the header.
// Adapted bodies: none
// 0x1868e0 ExtraGuardedRefData::Function1868e0
// 0x186a90 ExtraGuardedRefData::Function186a90
// Source exposure: mixed (local binary analysis and public names).
// ExtraGuardedRefData: EXE_RTTI
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
// 0x186b70 ExtraGuardedRefData::GetType
// Drafted by v-macrev, assisted by claude-haiku-5-5.
#include "ExtraGuardedRefData.h"

bool ExtraGuardedRefData::Function1868e0() const
{
    return field20 == 0;
}

bool ExtraGuardedRefData::Function186a90(const std::uint32_t& value) const
{
    return *reinterpret_cast<const std::uint32_t*>(this) == value;
}

// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
std::uint32_t ExtraGuardedRefData::GetType() const
{
    return 0x78;
}

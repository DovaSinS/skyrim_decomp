// Source exposure: mixed (local binary analysis and public names).
// Code origin: written for this reconstruction from the listing; names from the header and the public address library.
// Adapted bodies: none
// ExtraGuardedRefData: EXE_RTTI
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
// 0x1868e0 ExtraGuardedRefData::Function1868e0
// 0x186a90 ExtraGuardedRefData::Function186a90
// 0x186b70 ExtraGuardedRefData::GetType
#pragma once
#include <cstdint>
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
class ExtraGuardedRefData
{
public:
    virtual std::uint32_t GetType() const;
    bool Function1868e0() const;
    bool Function186a90(const std::uint32_t& value) const;

private:
    std::uint8_t pad08[0x18];
    std::uint32_t field20;
};

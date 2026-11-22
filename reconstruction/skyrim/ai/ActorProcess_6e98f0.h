// Source exposure: community-headers (names, layout), binary-analysis (offsets from the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// ActorProcess: GUESS(low); the class is the placeholder owner
// IsPackageDone: SYMBOLS(fo4-pdb); FO4 names it on AIProcess, the unit keeps the placeholder class ActorProcess
// Function721f30, Function722070: GUESS(low); matched callees named by their address, the signatures are read from the listing
// PackageInfo, package, typeIndex, fallbackIndex, kPackageTable: GUESS(low); stand-ins for the records and the lookup table the body reads
#pragma once

#include <cstdint>
#include <cstddef>

struct PackageInfo
{
    std::uint8_t pad00[0xD8];
    std::int32_t typeIndex;
};

extern const std::int32_t* const kPackageTable[];

class ActorProcess
{
public:
    PackageInfo* Function721f30();
    std::int32_t Function722070();
    bool IsPackageDone() const;  // compared: 0x6e98f0

    std::uint8_t pad00[0x20];
    PackageInfo* package;
    std::uint8_t pad28[0x34 - 0x28];
    std::int32_t fallbackIndex;
};

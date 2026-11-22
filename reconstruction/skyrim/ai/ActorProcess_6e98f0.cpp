// Source exposure: community-headers (names, layout), binary-analysis (offsets from the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6e98f0 ActorProcess::IsPackageDone
// Adapted bodies: none
#include "ActorProcess_6e98f0.h"

bool ActorProcess::IsPackageDone() const
{
    ActorProcess* self = const_cast<ActorProcess*>(this);
    PackageInfo* info = self->Function721f30();
    if (!info) {
        info = package;
        if (!info) {
            return true;
        }
    }
    std::int32_t type = info->typeIndex;
    std::int32_t index = self->Function721f30() ? self->Function722070() : fallbackIndex;
    if (kPackageTable[type][index] != 0x36) {
        return false;
    }
    return true;
}

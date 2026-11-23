// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x7e1890 ConeProjectile::Function7e1890
// Adapted bodies: none
#include "ConeProjectile_7e1890.h"

void ConeProjectile::Function7e1890()
{
    HostObject* host = GetHost();
    if (!host) {
        return;
    }
    for (ClassNode* node = host->GetClassNode(); node; node = node->parent) {
        if (node == &gTargetClass) {
            host->hostFlags &= ~1u;
            return;
        }
    }
}

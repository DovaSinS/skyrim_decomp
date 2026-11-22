// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xffb320 BSMasterParticleSystem::RegisterStreamables
// Adapted bodies: none
#include "BSMasterParticleSystem_ffb320.h"

bool BSMasterParticleSystem::RegisterStreamables(NiStream& a_stream)
{
    if (!NiNode::RegisterStreamables(a_stream)) {
        return false;
    }
    for (std::uint32_t i = 0; i < emitterObjs._size; ++i) {
        NiAVObject* object = emitterObjs._data[i];
        if (object) {
            object->RegisterStreamables(a_stream);
        }
    }
    return true;
}

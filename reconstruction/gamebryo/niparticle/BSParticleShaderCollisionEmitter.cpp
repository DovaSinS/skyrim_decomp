// Source exposure: mixed (community names; the pinned image listing).
// 0x1535f90 BSParticleShaderCollisionEmitter::Function1535f90
// SPDX-License-Identifier: CC0-1.0
// Code origin: original; the pinned image listing only
// 0x1535f80 BSParticleShaderCollisionEmitter::Function1535f80
// Adapted bodies: none
#include "BSParticleShaderCollisionEmitter.h"

std::uint16_t BSParticleShaderCollisionEmitter::Function1535f80() const
{
    return flagsEF2;
}

void* BSParticleShaderCollisionEmitter::Function1535f90(std::uint32_t a_index)
{
    struct ArrayView { void** data; };
    const ArrayView* view = reinterpret_cast<const ArrayView*>(
        reinterpret_cast<const std::uint8_t*>(this) + 0xEE8);
    return view->data[a_index];
}

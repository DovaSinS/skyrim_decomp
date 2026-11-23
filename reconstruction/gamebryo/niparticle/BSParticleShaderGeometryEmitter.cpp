// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"member-return","generator_version":"2","name_source":{"confidence":"low","kind":"guess","owner":"BSParticleShaderGeometryEmitter","rationale":"vtable owner and slot; method spelling invented","slot":5},"template_digest":"1254832e5ca7cdca7f6330a2018dde32919625f6149744dd0138e59a943106d8"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// Code origin: the existing leaf as above; Function1535980 original body from the listing; declarations are stand-ins
// BSParticleShaderGeometryEmitter: EXE_RTTI
// Slot5: GUESS(low)
// member, padding: GUESS(low); storage names invented for the measured member offset
// 0x1535970 BSParticleShaderGeometryEmitter::Slot5
// 0x1535980 BSParticleShaderGeometryEmitter::Function1535980
#include "BSParticleShaderGeometryEmitter.h"
// Slot5: GUESS(low); method name inferred from vtable owner and slot
std::uint32_t BSParticleShaderGeometryEmitter::Slot5() const
{
    return member;
}

std::uint64_t BSParticleShaderGeometryEmitter::Function1535980(std::uint32_t a_index) const
{
    return slots[a_index].value;
}

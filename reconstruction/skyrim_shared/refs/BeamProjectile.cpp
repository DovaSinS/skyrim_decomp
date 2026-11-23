// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: BeamProjectile::Revert is close to the sibling body (tools/check_origin.py similarity 0.78).
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/BeamProjectile.cpp:287
// BeamProjectile::Revert: SIBLING(fo4-private@1b765c70, author-permission)
// 0x7e03e0 BeamProjectile::Revert
// 0x7e0320 BeamProjectile::SaveGame
// Code origin: original from the listing and community declarations, except BeamProjectile::Revert, which is close to the sibling body named above
// 0x7e0410 BeamProjectile::GetKillOnCollision
#include "BeamProjectile.h"

bool BeamProjectile::GetKillOnCollision()
{
    return false;
}

void BeamProjectile::Revert(BGSLoadFormBuffer* a_buf)
{
    Projectile::Revert(a_buf);
    unk240 = 0;
}

void BeamProjectile::SaveGame(BGSSaveFormBuffer* a_buf)
{
    Projectile::SaveGame(a_buf);
    a_buf->SaveDataEndian(&unk240, 1, 1, 0);
}

// Accepted leaf retained from the integrated version.
// Slot165: GUESS(low); method name inferred from vtable owner and slot
std::uint8_t BeamProjectile::Slot165() const
{
    return 0x1;
}

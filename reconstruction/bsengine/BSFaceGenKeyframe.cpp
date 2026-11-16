// BSFaceGenKeyframe::Unk_0D, build sse-steam-1-7-104, RVA 0x4324f0, 3 bytes.
//
// Labels: v2
// Evidence: findings/p92-unit-supply-selection.md.
// Source exposure: binary-analysis. Drafted by v-macrev, assisted by claude-opus-5-5.
// A byte match shows that this source and recipe produce the checked code; it does not verify the
// community name or that the original source looked like this.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json (compile this file alone).
// Unk_0C (RVA 0x432510, 3 bytes) and Unk_0D are compared.
// CI hash: 0x432510 ?Unk_0C@BSFaceGenKeyframe@@QEAA_NXZ
// CI hash: 0x4324f0 ?Unk_0D@BSFaceGenKeyframe@@QEAA_NXZ
#include "BSFaceGenKeyframe.h"

bool BSFaceGenKeyframe::Unk_0C()
{
    return false;
}

bool BSFaceGenKeyframe::Unk_0D()
{
    return false;
}

// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x150b5b0 ImageSpaceEffect::Function150b5b0
#include "ImageSpaceEffect_150b5b0.h"

void ImageSpaceEffect::Function150b5b0(void* a_arg)
{
    unk48->texture->Function1555120(1);
    Function1554640(2, unk48->texture, 1);
    Function1554640(3, unk48->texture, 1);
    Function1564e30(a_arg, unk118);
}

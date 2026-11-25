// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// ImageSpaceEffect::Function150b5b0: GUESS(low); the name comes from the inventory
// ImageSpaceEffect and its callees (Function1554640, Function1564e30), Texture::Function1555120, TextureSlot: STANDIN GUESS(low); names made up for the callees at 0x1554640, 0x1564e30 and 0x1555120
// unk48, unk118: GUESS(low); offsets from the listing
#pragma once

#include <cstdint>
#include <cstddef>

class Texture
{
public:
    void Function1555120(int a_value);  // callee at 0x1555120, not compared
};

struct TextureSlot
{
    std::uint8_t unk00[8];
    Texture* texture;  // 08
};

class ImageSpaceEffect
{
public:
    void Function150b5b0(void* a_arg);  // compared: 0x150b5b0
    void Function1554640(int a_slot, Texture* a_texture, int a_flag);  // callee at 0x1554640, not compared
    void Function1564e30(void* a_arg, void* a_data);                    // callee at 0x1564e30, not compared

    std::uint8_t unk00[0x48];
    TextureSlot* unk48;           // 48
    std::uint8_t unk50[0xc8];
    std::uint8_t unk118[0x20];    // 118
};
static_assert(offsetof(ImageSpaceEffect, unk118) == 0x118, "layout");

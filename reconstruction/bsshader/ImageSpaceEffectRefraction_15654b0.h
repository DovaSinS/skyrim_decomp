// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// ImageSpaceEffectRefraction, ImageSpaceEffectRefraction::ctor: CRASHLOGGER_PDB(59818@2026.10.24); names only
// ImageSpaceEffect: STANDIN CRASHLOGGER_PDB(59818@2026.10.24); size 0x90 and the vtable slot order, bodies not compared here
// unk90, unk98, unk9C, unkA0, unkA4, unkA8: GUESS(low); offsets from the listing; unk98 is volatile only to keep the target's store order
#pragma once

#include <cstdint>
#include <cstddef>

class ImageSpaceEffectParam;

class ImageSpaceEffect
{
public:
    ImageSpaceEffect();  // callee at 0x1553950, not compared here
    virtual ~ImageSpaceEffect();
    virtual void Render(void* a_shape, ImageSpaceEffectParam* a_param);
    virtual void Setup(void* a_manager, ImageSpaceEffectParam* a_param);
    virtual void ShutDown();
    virtual void BorrowTextures(ImageSpaceEffectParam* a_param);
    virtual void ReturnTextures();
    virtual bool IsActive();
    virtual bool UpdateParams(ImageSpaceEffectParam* a_param);
    virtual bool SetRenderStates(ImageSpaceEffectParam* a_param);
    virtual bool RestoreRenderStates(ImageSpaceEffectParam* a_param);

    std::uint8_t unk08[0x88];
};
static_assert(sizeof(ImageSpaceEffect) == 0x90, "ImageSpaceEffect size");

class ImageSpaceEffectRefraction : public ImageSpaceEffect
{
public:
    ImageSpaceEffectRefraction();  // compared: 0x15654b0
    ~ImageSpaceEffectRefraction() override;

    void* unk90;            // 90
    // volatile: keeps the constant store after the zero stores, as the target orders them
    volatile std::int32_t unk98;  // 98
    std::int32_t unk9C;     // 9C
    std::int32_t unkA0;     // A0
    std::int32_t unkA4;     // A4
    bool unkA8;             // A8
};
static_assert(offsetof(ImageSpaceEffectRefraction, unkA8) == 0xa8, "layout");

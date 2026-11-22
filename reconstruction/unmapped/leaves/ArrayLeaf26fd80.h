// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf26fd80, ArrayLeaf26fd80Storage, ArrayLeaf26fd80Size, FreeArrayLeaf26fd80, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf26fd80Storage
{
    ~ArrayLeaf26fd80Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf26fd80Size
{
    ~ArrayLeaf26fd80Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf26fd80 : public ArrayLeaf26fd80Storage, public ArrayLeaf26fd80Size
{
    ~ArrayLeaf26fd80();  // compared: 0x26fd80
};

void FreeArrayLeaf26fd80(ArrayLeaf26fd80* array);

// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1ae800, ArrayLeaf1ae800Storage, ArrayLeaf1ae800Size, FreeArrayLeaf1ae800, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1ae800Storage
{
    ~ArrayLeaf1ae800Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1ae800Size
{
    ~ArrayLeaf1ae800Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1ae800 : public ArrayLeaf1ae800Storage, public ArrayLeaf1ae800Size
{
    ~ArrayLeaf1ae800();  // compared: 0x1ae800
};

void FreeArrayLeaf1ae800(ArrayLeaf1ae800* array);

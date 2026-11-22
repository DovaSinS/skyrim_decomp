// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf29c850, ArrayLeaf29c850Storage, ArrayLeaf29c850Size, FreeArrayLeaf29c850, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf29c850Storage
{
    ~ArrayLeaf29c850Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf29c850Size
{
    ~ArrayLeaf29c850Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf29c850 : public ArrayLeaf29c850Storage, public ArrayLeaf29c850Size
{
    ~ArrayLeaf29c850();  // compared: 0x29c850
};

void FreeArrayLeaf29c850(ArrayLeaf29c850* array);

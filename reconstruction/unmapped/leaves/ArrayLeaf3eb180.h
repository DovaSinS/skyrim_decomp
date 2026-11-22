// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf3eb180, ArrayLeaf3eb180Storage, ArrayLeaf3eb180Size, FreeArrayLeaf3eb180, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf3eb180Storage
{
    ~ArrayLeaf3eb180Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf3eb180Size
{
    ~ArrayLeaf3eb180Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf3eb180 : public ArrayLeaf3eb180Storage, public ArrayLeaf3eb180Size
{
    ~ArrayLeaf3eb180();  // compared: 0x3eb180
};

void FreeArrayLeaf3eb180(ArrayLeaf3eb180* array);

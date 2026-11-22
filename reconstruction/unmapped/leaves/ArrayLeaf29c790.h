// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf29c790, ArrayLeaf29c790Storage, ArrayLeaf29c790Size, FreeArrayLeaf29c790, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf29c790Storage
{
    ~ArrayLeaf29c790Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf29c790Size
{
    ~ArrayLeaf29c790Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf29c790 : public ArrayLeaf29c790Storage, public ArrayLeaf29c790Size
{
    ~ArrayLeaf29c790();  // compared: 0x29c790
};

void FreeArrayLeaf29c790(ArrayLeaf29c790* array);

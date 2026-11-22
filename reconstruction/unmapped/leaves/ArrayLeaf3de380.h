// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf3de380, ArrayLeaf3de380Storage, ArrayLeaf3de380Size, FreeArrayLeaf3de380, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf3de380Storage
{
    ~ArrayLeaf3de380Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf3de380Size
{
    ~ArrayLeaf3de380Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf3de380 : public ArrayLeaf3de380Storage, public ArrayLeaf3de380Size
{
    ~ArrayLeaf3de380();  // compared: 0x3de380
};

void FreeArrayLeaf3de380(ArrayLeaf3de380* array);

// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf3aa380, ArrayLeaf3aa380Storage, ArrayLeaf3aa380Size, FreeArrayLeaf3aa380, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf3aa380Storage
{
    ~ArrayLeaf3aa380Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf3aa380Size
{
    ~ArrayLeaf3aa380Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf3aa380 : public ArrayLeaf3aa380Storage, public ArrayLeaf3aa380Size
{
    ~ArrayLeaf3aa380();  // compared: 0x3aa380
};

void FreeArrayLeaf3aa380(ArrayLeaf3aa380* array);

// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf3de2c0, ArrayLeaf3de2c0Storage, ArrayLeaf3de2c0Size, FreeArrayLeaf3de2c0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf3de2c0Storage
{
    ~ArrayLeaf3de2c0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf3de2c0Size
{
    ~ArrayLeaf3de2c0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf3de2c0 : public ArrayLeaf3de2c0Storage, public ArrayLeaf3de2c0Size
{
    ~ArrayLeaf3de2c0();  // compared: 0x3de2c0
};

void FreeArrayLeaf3de2c0(ArrayLeaf3de2c0* array);

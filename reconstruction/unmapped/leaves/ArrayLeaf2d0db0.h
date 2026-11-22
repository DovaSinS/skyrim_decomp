// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf2d0db0, ArrayLeaf2d0db0Storage, ArrayLeaf2d0db0Size, FreeArrayLeaf2d0db0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf2d0db0Storage
{
    ~ArrayLeaf2d0db0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf2d0db0Size
{
    ~ArrayLeaf2d0db0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf2d0db0 : public ArrayLeaf2d0db0Storage, public ArrayLeaf2d0db0Size
{
    ~ArrayLeaf2d0db0();  // compared: 0x2d0db0
};

void FreeArrayLeaf2d0db0(ArrayLeaf2d0db0* array);

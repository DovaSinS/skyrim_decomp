// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf2d0e10, ArrayLeaf2d0e10Storage, ArrayLeaf2d0e10Size, FreeArrayLeaf2d0e10, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf2d0e10Storage
{
    ~ArrayLeaf2d0e10Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf2d0e10Size
{
    ~ArrayLeaf2d0e10Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf2d0e10 : public ArrayLeaf2d0e10Storage, public ArrayLeaf2d0e10Size
{
    ~ArrayLeaf2d0e10();  // compared: 0x2d0e10
};

void FreeArrayLeaf2d0e10(ArrayLeaf2d0e10* array);

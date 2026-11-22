// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf2020e0, ArrayLeaf2020e0Storage, ArrayLeaf2020e0Size, FreeArrayLeaf2020e0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf2020e0Storage
{
    ~ArrayLeaf2020e0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf2020e0Size
{
    ~ArrayLeaf2020e0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf2020e0 : public ArrayLeaf2020e0Storage, public ArrayLeaf2020e0Size
{
    ~ArrayLeaf2020e0();  // compared: 0x2020e0
};

void FreeArrayLeaf2020e0(ArrayLeaf2020e0* array);

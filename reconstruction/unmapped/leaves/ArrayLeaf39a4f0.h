// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf39a4f0, ArrayLeaf39a4f0Storage, ArrayLeaf39a4f0Size, FreeArrayLeaf39a4f0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf39a4f0Storage
{
    ~ArrayLeaf39a4f0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf39a4f0Size
{
    ~ArrayLeaf39a4f0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf39a4f0 : public ArrayLeaf39a4f0Storage, public ArrayLeaf39a4f0Size
{
    ~ArrayLeaf39a4f0();  // compared: 0x39a4f0
};

void FreeArrayLeaf39a4f0(ArrayLeaf39a4f0* array);

// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf14c5d0, ArrayLeaf14c5d0Storage, ArrayLeaf14c5d0Size, FreeArrayLeaf14c5d0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf14c5d0Storage
{
    ~ArrayLeaf14c5d0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf14c5d0Size
{
    ~ArrayLeaf14c5d0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf14c5d0 : public ArrayLeaf14c5d0Storage, public ArrayLeaf14c5d0Size
{
    ~ArrayLeaf14c5d0();  // compared: 0x14c5d0
};

void FreeArrayLeaf14c5d0(ArrayLeaf14c5d0* array);

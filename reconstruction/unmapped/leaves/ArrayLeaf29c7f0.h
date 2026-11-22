// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf29c7f0, ArrayLeaf29c7f0Storage, ArrayLeaf29c7f0Size, FreeArrayLeaf29c7f0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf29c7f0Storage
{
    ~ArrayLeaf29c7f0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf29c7f0Size
{
    ~ArrayLeaf29c7f0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf29c7f0 : public ArrayLeaf29c7f0Storage, public ArrayLeaf29c7f0Size
{
    ~ArrayLeaf29c7f0();  // compared: 0x29c7f0
};

void FreeArrayLeaf29c7f0(ArrayLeaf29c7f0* array);

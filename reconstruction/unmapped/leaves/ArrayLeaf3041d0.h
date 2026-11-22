// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf3041d0, ArrayLeaf3041d0Storage, ArrayLeaf3041d0Size, FreeArrayLeaf3041d0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf3041d0Storage
{
    ~ArrayLeaf3041d0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf3041d0Size
{
    ~ArrayLeaf3041d0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf3041d0 : public ArrayLeaf3041d0Storage, public ArrayLeaf3041d0Size
{
    ~ArrayLeaf3041d0();  // compared: 0x3041d0
};

void FreeArrayLeaf3041d0(ArrayLeaf3041d0* array);

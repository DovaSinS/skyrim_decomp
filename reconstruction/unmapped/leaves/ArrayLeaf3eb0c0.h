// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf3eb0c0, ArrayLeaf3eb0c0Storage, ArrayLeaf3eb0c0Size, FreeArrayLeaf3eb0c0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf3eb0c0Storage
{
    ~ArrayLeaf3eb0c0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf3eb0c0Size
{
    ~ArrayLeaf3eb0c0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf3eb0c0 : public ArrayLeaf3eb0c0Storage, public ArrayLeaf3eb0c0Size
{
    ~ArrayLeaf3eb0c0();  // compared: 0x3eb0c0
};

void FreeArrayLeaf3eb0c0(ArrayLeaf3eb0c0* array);

// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf39beb0, ArrayLeaf39beb0Storage, ArrayLeaf39beb0Size, FreeArrayLeaf39beb0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf39beb0Storage
{
    ~ArrayLeaf39beb0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf39beb0Size
{
    ~ArrayLeaf39beb0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf39beb0 : public ArrayLeaf39beb0Storage, public ArrayLeaf39beb0Size
{
    ~ArrayLeaf39beb0();  // compared: 0x39beb0
};

void FreeArrayLeaf39beb0(ArrayLeaf39beb0* array);

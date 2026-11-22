// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf2805f0, ArrayLeaf2805f0Storage, ArrayLeaf2805f0Size, FreeArrayLeaf2805f0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf2805f0Storage
{
    ~ArrayLeaf2805f0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf2805f0Size
{
    ~ArrayLeaf2805f0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf2805f0 : public ArrayLeaf2805f0Storage, public ArrayLeaf2805f0Size
{
    ~ArrayLeaf2805f0();  // compared: 0x2805f0
};

void FreeArrayLeaf2805f0(ArrayLeaf2805f0* array);

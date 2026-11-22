// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf2855f0, ArrayLeaf2855f0Storage, ArrayLeaf2855f0Size, FreeArrayLeaf2855f0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf2855f0Storage
{
    ~ArrayLeaf2855f0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf2855f0Size
{
    ~ArrayLeaf2855f0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf2855f0 : public ArrayLeaf2855f0Storage, public ArrayLeaf2855f0Size
{
    ~ArrayLeaf2855f0();  // compared: 0x2855f0
};

void FreeArrayLeaf2855f0(ArrayLeaf2855f0* array);

// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf2a0a20, ArrayLeaf2a0a20Storage, ArrayLeaf2a0a20Size, FreeArrayLeaf2a0a20, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf2a0a20Storage
{
    ~ArrayLeaf2a0a20Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf2a0a20Size
{
    ~ArrayLeaf2a0a20Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf2a0a20 : public ArrayLeaf2a0a20Storage, public ArrayLeaf2a0a20Size
{
    ~ArrayLeaf2a0a20();  // compared: 0x2a0a20
};

void FreeArrayLeaf2a0a20(ArrayLeaf2a0a20* array);

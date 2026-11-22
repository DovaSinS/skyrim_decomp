// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf137220, ArrayLeaf137220Storage, ArrayLeaf137220Size, FreeArrayLeaf137220, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf137220Storage
{
    ~ArrayLeaf137220Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf137220Size
{
    ~ArrayLeaf137220Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf137220 : public ArrayLeaf137220Storage, public ArrayLeaf137220Size
{
    ~ArrayLeaf137220();  // compared: 0x137220
};

void FreeArrayLeaf137220(ArrayLeaf137220* array);

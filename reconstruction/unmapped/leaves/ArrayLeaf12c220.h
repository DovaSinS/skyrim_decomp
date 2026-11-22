// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf12c220, ArrayLeaf12c220Storage, ArrayLeaf12c220Size, FreeArrayLeaf12c220, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf12c220Storage
{
    ~ArrayLeaf12c220Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf12c220Size
{
    ~ArrayLeaf12c220Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf12c220 : public ArrayLeaf12c220Storage, public ArrayLeaf12c220Size
{
    ~ArrayLeaf12c220();  // compared: 0x12c220
};

void FreeArrayLeaf12c220(ArrayLeaf12c220* array);

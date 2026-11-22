// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf17b960, ArrayLeaf17b960Storage, ArrayLeaf17b960Size, FreeArrayLeaf17b960, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf17b960Storage
{
    ~ArrayLeaf17b960Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf17b960Size
{
    ~ArrayLeaf17b960Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf17b960 : public ArrayLeaf17b960Storage, public ArrayLeaf17b960Size
{
    ~ArrayLeaf17b960();  // compared: 0x17b960
};

void FreeArrayLeaf17b960(ArrayLeaf17b960* array);

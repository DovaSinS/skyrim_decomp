// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1aea40, ArrayLeaf1aea40Storage, ArrayLeaf1aea40Size, FreeArrayLeaf1aea40, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1aea40Storage
{
    ~ArrayLeaf1aea40Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1aea40Size
{
    ~ArrayLeaf1aea40Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1aea40 : public ArrayLeaf1aea40Storage, public ArrayLeaf1aea40Size
{
    ~ArrayLeaf1aea40();  // compared: 0x1aea40
};

void FreeArrayLeaf1aea40(ArrayLeaf1aea40* array);

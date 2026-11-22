// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf136040, ArrayLeaf136040Storage, ArrayLeaf136040Size, FreeArrayLeaf136040, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf136040Storage
{
    ~ArrayLeaf136040Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf136040Size
{
    ~ArrayLeaf136040Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf136040 : public ArrayLeaf136040Storage, public ArrayLeaf136040Size
{
    ~ArrayLeaf136040();  // compared: 0x136040
};

void FreeArrayLeaf136040(ArrayLeaf136040* array);

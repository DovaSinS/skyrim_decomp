// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1d6450, ArrayLeaf1d6450Storage, ArrayLeaf1d6450Size, FreeArrayLeaf1d6450, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1d6450Storage
{
    ~ArrayLeaf1d6450Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1d6450Size
{
    ~ArrayLeaf1d6450Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1d6450 : public ArrayLeaf1d6450Storage, public ArrayLeaf1d6450Size
{
    ~ArrayLeaf1d6450();  // compared: 0x1d6450
};

void FreeArrayLeaf1d6450(ArrayLeaf1d6450* array);

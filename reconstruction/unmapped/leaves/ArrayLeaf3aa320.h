// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf3aa320, ArrayLeaf3aa320Storage, ArrayLeaf3aa320Size, FreeArrayLeaf3aa320, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf3aa320Storage
{
    ~ArrayLeaf3aa320Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf3aa320Size
{
    ~ArrayLeaf3aa320Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf3aa320 : public ArrayLeaf3aa320Storage, public ArrayLeaf3aa320Size
{
    ~ArrayLeaf3aa320();  // compared: 0x3aa320
};

void FreeArrayLeaf3aa320(ArrayLeaf3aa320* array);

// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf240050, ArrayLeaf240050Storage, ArrayLeaf240050Size, FreeArrayLeaf240050, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf240050Storage
{
    ~ArrayLeaf240050Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf240050Size
{
    ~ArrayLeaf240050Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf240050 : public ArrayLeaf240050Storage, public ArrayLeaf240050Size
{
    ~ArrayLeaf240050();  // compared: 0x240050
};

void FreeArrayLeaf240050(ArrayLeaf240050* array);

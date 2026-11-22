// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf29c730, ArrayLeaf29c730Storage, ArrayLeaf29c730Size, FreeArrayLeaf29c730, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf29c730Storage
{
    ~ArrayLeaf29c730Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf29c730Size
{
    ~ArrayLeaf29c730Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf29c730 : public ArrayLeaf29c730Storage, public ArrayLeaf29c730Size
{
    ~ArrayLeaf29c730();  // compared: 0x29c730
};

void FreeArrayLeaf29c730(ArrayLeaf29c730* array);

// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1ae980, ArrayLeaf1ae980Storage, ArrayLeaf1ae980Size, FreeArrayLeaf1ae980, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1ae980Storage
{
    ~ArrayLeaf1ae980Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1ae980Size
{
    ~ArrayLeaf1ae980Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1ae980 : public ArrayLeaf1ae980Storage, public ArrayLeaf1ae980Size
{
    ~ArrayLeaf1ae980();  // compared: 0x1ae980
};

void FreeArrayLeaf1ae980(ArrayLeaf1ae980* array);

// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf31bc90, ArrayLeaf31bc90Storage, ArrayLeaf31bc90Size, FreeArrayLeaf31bc90, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf31bc90Storage
{
    ~ArrayLeaf31bc90Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf31bc90Size
{
    ~ArrayLeaf31bc90Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf31bc90 : public ArrayLeaf31bc90Storage, public ArrayLeaf31bc90Size
{
    ~ArrayLeaf31bc90();  // compared: 0x31bc90
};

void FreeArrayLeaf31bc90(ArrayLeaf31bc90* array);

// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf309bd0, ArrayLeaf309bd0Storage, ArrayLeaf309bd0Size, FreeArrayLeaf309bd0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf309bd0Storage
{
    ~ArrayLeaf309bd0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf309bd0Size
{
    ~ArrayLeaf309bd0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf309bd0 : public ArrayLeaf309bd0Storage, public ArrayLeaf309bd0Size
{
    ~ArrayLeaf309bd0();  // compared: 0x309bd0
};

void FreeArrayLeaf309bd0(ArrayLeaf309bd0* array);

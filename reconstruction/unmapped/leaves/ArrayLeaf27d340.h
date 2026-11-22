// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf27d340, ArrayLeaf27d340Storage, ArrayLeaf27d340Size, FreeArrayLeaf27d340, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf27d340Storage
{
    ~ArrayLeaf27d340Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf27d340Size
{
    ~ArrayLeaf27d340Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf27d340 : public ArrayLeaf27d340Storage, public ArrayLeaf27d340Size
{
    ~ArrayLeaf27d340();  // compared: 0x27d340
};

void FreeArrayLeaf27d340(ArrayLeaf27d340* array);

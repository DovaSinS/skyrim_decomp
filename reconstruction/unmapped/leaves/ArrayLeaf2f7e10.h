// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf2f7e10, ArrayLeaf2f7e10Storage, ArrayLeaf2f7e10Size, FreeArrayLeaf2f7e10, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf2f7e10Storage
{
    ~ArrayLeaf2f7e10Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf2f7e10Size
{
    ~ArrayLeaf2f7e10Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf2f7e10 : public ArrayLeaf2f7e10Storage, public ArrayLeaf2f7e10Size
{
    ~ArrayLeaf2f7e10();  // compared: 0x2f7e10
};

void FreeArrayLeaf2f7e10(ArrayLeaf2f7e10* array);

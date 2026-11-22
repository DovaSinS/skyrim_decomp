// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf293ab0, ArrayLeaf293ab0Storage, ArrayLeaf293ab0Size, FreeArrayLeaf293ab0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf293ab0Storage
{
    ~ArrayLeaf293ab0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf293ab0Size
{
    ~ArrayLeaf293ab0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf293ab0 : public ArrayLeaf293ab0Storage, public ArrayLeaf293ab0Size
{
    ~ArrayLeaf293ab0();  // compared: 0x293ab0
};

void FreeArrayLeaf293ab0(ArrayLeaf293ab0* array);

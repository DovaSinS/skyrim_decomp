// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1aefe0, ArrayLeaf1aefe0Storage, ArrayLeaf1aefe0Size, FreeArrayLeaf1aefe0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1aefe0Storage
{
    ~ArrayLeaf1aefe0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1aefe0Size
{
    ~ArrayLeaf1aefe0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1aefe0 : public ArrayLeaf1aefe0Storage, public ArrayLeaf1aefe0Size
{
    ~ArrayLeaf1aefe0();  // compared: 0x1aefe0
};

void FreeArrayLeaf1aefe0(ArrayLeaf1aefe0* array);

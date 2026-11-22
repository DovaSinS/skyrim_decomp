// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1af1c0, ArrayLeaf1af1c0Storage, ArrayLeaf1af1c0Size, FreeArrayLeaf1af1c0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1af1c0Storage
{
    ~ArrayLeaf1af1c0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1af1c0Size
{
    ~ArrayLeaf1af1c0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1af1c0 : public ArrayLeaf1af1c0Storage, public ArrayLeaf1af1c0Size
{
    ~ArrayLeaf1af1c0();  // compared: 0x1af1c0
};

void FreeArrayLeaf1af1c0(ArrayLeaf1af1c0* array);

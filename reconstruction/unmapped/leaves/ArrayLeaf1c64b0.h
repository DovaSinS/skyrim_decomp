// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1c64b0, ArrayLeaf1c64b0Storage, ArrayLeaf1c64b0Size, FreeArrayLeaf1c64b0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1c64b0Storage
{
    ~ArrayLeaf1c64b0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1c64b0Size
{
    ~ArrayLeaf1c64b0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1c64b0 : public ArrayLeaf1c64b0Storage, public ArrayLeaf1c64b0Size
{
    ~ArrayLeaf1c64b0();  // compared: 0x1c64b0
};

void FreeArrayLeaf1c64b0(ArrayLeaf1c64b0* array);

// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1aece0, ArrayLeaf1aece0Storage, ArrayLeaf1aece0Size, FreeArrayLeaf1aece0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1aece0Storage
{
    ~ArrayLeaf1aece0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1aece0Size
{
    ~ArrayLeaf1aece0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1aece0 : public ArrayLeaf1aece0Storage, public ArrayLeaf1aece0Size
{
    ~ArrayLeaf1aece0();  // compared: 0x1aece0
};

void FreeArrayLeaf1aece0(ArrayLeaf1aece0* array);

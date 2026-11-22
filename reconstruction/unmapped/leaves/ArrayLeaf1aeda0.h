// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1aeda0, ArrayLeaf1aeda0Storage, ArrayLeaf1aeda0Size, FreeArrayLeaf1aeda0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1aeda0Storage
{
    ~ArrayLeaf1aeda0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1aeda0Size
{
    ~ArrayLeaf1aeda0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1aeda0 : public ArrayLeaf1aeda0Storage, public ArrayLeaf1aeda0Size
{
    ~ArrayLeaf1aeda0();  // compared: 0x1aeda0
};

void FreeArrayLeaf1aeda0(ArrayLeaf1aeda0* array);

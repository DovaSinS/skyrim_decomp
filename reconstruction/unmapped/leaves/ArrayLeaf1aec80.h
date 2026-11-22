// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1aec80, ArrayLeaf1aec80Storage, ArrayLeaf1aec80Size, FreeArrayLeaf1aec80, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1aec80Storage
{
    ~ArrayLeaf1aec80Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1aec80Size
{
    ~ArrayLeaf1aec80Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1aec80 : public ArrayLeaf1aec80Storage, public ArrayLeaf1aec80Size
{
    ~ArrayLeaf1aec80();  // compared: 0x1aec80
};

void FreeArrayLeaf1aec80(ArrayLeaf1aec80* array);

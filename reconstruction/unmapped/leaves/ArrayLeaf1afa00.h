// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1afa00, ArrayLeaf1afa00Storage, ArrayLeaf1afa00Size, FreeArrayLeaf1afa00, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1afa00Storage
{
    ~ArrayLeaf1afa00Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1afa00Size
{
    ~ArrayLeaf1afa00Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1afa00 : public ArrayLeaf1afa00Storage, public ArrayLeaf1afa00Size
{
    ~ArrayLeaf1afa00();  // compared: 0x1afa00
};

void FreeArrayLeaf1afa00(ArrayLeaf1afa00* array);

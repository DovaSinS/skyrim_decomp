// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1af520, ArrayLeaf1af520Storage, ArrayLeaf1af520Size, FreeArrayLeaf1af520, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1af520Storage
{
    ~ArrayLeaf1af520Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1af520Size
{
    ~ArrayLeaf1af520Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1af520 : public ArrayLeaf1af520Storage, public ArrayLeaf1af520Size
{
    ~ArrayLeaf1af520();  // compared: 0x1af520
};

void FreeArrayLeaf1af520(ArrayLeaf1af520* array);

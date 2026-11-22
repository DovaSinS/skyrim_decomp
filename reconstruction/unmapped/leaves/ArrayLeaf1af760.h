// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1af760, ArrayLeaf1af760Storage, ArrayLeaf1af760Size, FreeArrayLeaf1af760, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1af760Storage
{
    ~ArrayLeaf1af760Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1af760Size
{
    ~ArrayLeaf1af760Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1af760 : public ArrayLeaf1af760Storage, public ArrayLeaf1af760Size
{
    ~ArrayLeaf1af760();  // compared: 0x1af760
};

void FreeArrayLeaf1af760(ArrayLeaf1af760* array);

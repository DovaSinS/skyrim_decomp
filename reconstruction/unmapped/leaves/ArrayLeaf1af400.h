// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1af400, ArrayLeaf1af400Storage, ArrayLeaf1af400Size, FreeArrayLeaf1af400, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1af400Storage
{
    ~ArrayLeaf1af400Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1af400Size
{
    ~ArrayLeaf1af400Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1af400 : public ArrayLeaf1af400Storage, public ArrayLeaf1af400Size
{
    ~ArrayLeaf1af400();  // compared: 0x1af400
};

void FreeArrayLeaf1af400(ArrayLeaf1af400* array);

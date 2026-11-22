// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1af220, ArrayLeaf1af220Storage, ArrayLeaf1af220Size, FreeArrayLeaf1af220, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1af220Storage
{
    ~ArrayLeaf1af220Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1af220Size
{
    ~ArrayLeaf1af220Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1af220 : public ArrayLeaf1af220Storage, public ArrayLeaf1af220Size
{
    ~ArrayLeaf1af220();  // compared: 0x1af220
};

void FreeArrayLeaf1af220(ArrayLeaf1af220* array);

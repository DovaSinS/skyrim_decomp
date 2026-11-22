// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1af340, ArrayLeaf1af340Storage, ArrayLeaf1af340Size, FreeArrayLeaf1af340, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1af340Storage
{
    ~ArrayLeaf1af340Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1af340Size
{
    ~ArrayLeaf1af340Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1af340 : public ArrayLeaf1af340Storage, public ArrayLeaf1af340Size
{
    ~ArrayLeaf1af340();  // compared: 0x1af340
};

void FreeArrayLeaf1af340(ArrayLeaf1af340* array);

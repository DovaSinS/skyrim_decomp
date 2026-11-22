// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1af460, ArrayLeaf1af460Storage, ArrayLeaf1af460Size, FreeArrayLeaf1af460, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1af460Storage
{
    ~ArrayLeaf1af460Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1af460Size
{
    ~ArrayLeaf1af460Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1af460 : public ArrayLeaf1af460Storage, public ArrayLeaf1af460Size
{
    ~ArrayLeaf1af460();  // compared: 0x1af460
};

void FreeArrayLeaf1af460(ArrayLeaf1af460* array);

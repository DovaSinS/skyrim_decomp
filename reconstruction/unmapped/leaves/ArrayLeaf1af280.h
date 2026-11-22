// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1af280, ArrayLeaf1af280Storage, ArrayLeaf1af280Size, FreeArrayLeaf1af280, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1af280Storage
{
    ~ArrayLeaf1af280Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1af280Size
{
    ~ArrayLeaf1af280Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1af280 : public ArrayLeaf1af280Storage, public ArrayLeaf1af280Size
{
    ~ArrayLeaf1af280();  // compared: 0x1af280
};

void FreeArrayLeaf1af280(ArrayLeaf1af280* array);

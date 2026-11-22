// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1af160, ArrayLeaf1af160Storage, ArrayLeaf1af160Size, FreeArrayLeaf1af160, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1af160Storage
{
    ~ArrayLeaf1af160Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1af160Size
{
    ~ArrayLeaf1af160Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1af160 : public ArrayLeaf1af160Storage, public ArrayLeaf1af160Size
{
    ~ArrayLeaf1af160();  // compared: 0x1af160
};

void FreeArrayLeaf1af160(ArrayLeaf1af160* array);

// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1aef20, ArrayLeaf1aef20Storage, ArrayLeaf1aef20Size, FreeArrayLeaf1aef20, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1aef20Storage
{
    ~ArrayLeaf1aef20Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1aef20Size
{
    ~ArrayLeaf1aef20Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1aef20 : public ArrayLeaf1aef20Storage, public ArrayLeaf1aef20Size
{
    ~ArrayLeaf1aef20();  // compared: 0x1aef20
};

void FreeArrayLeaf1aef20(ArrayLeaf1aef20* array);

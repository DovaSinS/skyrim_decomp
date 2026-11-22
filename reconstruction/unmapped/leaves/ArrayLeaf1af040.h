// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1af040, ArrayLeaf1af040Storage, ArrayLeaf1af040Size, FreeArrayLeaf1af040, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1af040Storage
{
    ~ArrayLeaf1af040Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1af040Size
{
    ~ArrayLeaf1af040Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1af040 : public ArrayLeaf1af040Storage, public ArrayLeaf1af040Size
{
    ~ArrayLeaf1af040();  // compared: 0x1af040
};

void FreeArrayLeaf1af040(ArrayLeaf1af040* array);

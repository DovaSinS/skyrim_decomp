// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1aeb00, ArrayLeaf1aeb00Storage, ArrayLeaf1aeb00Size, FreeArrayLeaf1aeb00, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1aeb00Storage
{
    ~ArrayLeaf1aeb00Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1aeb00Size
{
    ~ArrayLeaf1aeb00Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1aeb00 : public ArrayLeaf1aeb00Storage, public ArrayLeaf1aeb00Size
{
    ~ArrayLeaf1aeb00();  // compared: 0x1aeb00
};

void FreeArrayLeaf1aeb00(ArrayLeaf1aeb00* array);

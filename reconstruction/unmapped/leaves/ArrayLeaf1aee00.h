// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1aee00, ArrayLeaf1aee00Storage, ArrayLeaf1aee00Size, FreeArrayLeaf1aee00, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1aee00Storage
{
    ~ArrayLeaf1aee00Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1aee00Size
{
    ~ArrayLeaf1aee00Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1aee00 : public ArrayLeaf1aee00Storage, public ArrayLeaf1aee00Size
{
    ~ArrayLeaf1aee00();  // compared: 0x1aee00
};

void FreeArrayLeaf1aee00(ArrayLeaf1aee00* array);

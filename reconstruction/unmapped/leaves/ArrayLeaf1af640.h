// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1af640, ArrayLeaf1af640Storage, ArrayLeaf1af640Size, FreeArrayLeaf1af640, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1af640Storage
{
    ~ArrayLeaf1af640Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1af640Size
{
    ~ArrayLeaf1af640Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1af640 : public ArrayLeaf1af640Storage, public ArrayLeaf1af640Size
{
    ~ArrayLeaf1af640();  // compared: 0x1af640
};

void FreeArrayLeaf1af640(ArrayLeaf1af640* array);

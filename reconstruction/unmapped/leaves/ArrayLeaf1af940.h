// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1af940, ArrayLeaf1af940Storage, ArrayLeaf1af940Size, FreeArrayLeaf1af940, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1af940Storage
{
    ~ArrayLeaf1af940Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1af940Size
{
    ~ArrayLeaf1af940Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1af940 : public ArrayLeaf1af940Storage, public ArrayLeaf1af940Size
{
    ~ArrayLeaf1af940();  // compared: 0x1af940
};

void FreeArrayLeaf1af940(ArrayLeaf1af940* array);

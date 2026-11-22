// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1afbe0, ArrayLeaf1afbe0Storage, ArrayLeaf1afbe0Size, FreeArrayLeaf1afbe0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1afbe0Storage
{
    ~ArrayLeaf1afbe0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1afbe0Size
{
    ~ArrayLeaf1afbe0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1afbe0 : public ArrayLeaf1afbe0Storage, public ArrayLeaf1afbe0Size
{
    ~ArrayLeaf1afbe0();  // compared: 0x1afbe0
};

void FreeArrayLeaf1afbe0(ArrayLeaf1afbe0* array);

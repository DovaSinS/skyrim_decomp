// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1afca0, ArrayLeaf1afca0Storage, ArrayLeaf1afca0Size, FreeArrayLeaf1afca0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1afca0Storage
{
    ~ArrayLeaf1afca0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1afca0Size
{
    ~ArrayLeaf1afca0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1afca0 : public ArrayLeaf1afca0Storage, public ArrayLeaf1afca0Size
{
    ~ArrayLeaf1afca0();  // compared: 0x1afca0
};

void FreeArrayLeaf1afca0(ArrayLeaf1afca0* array);

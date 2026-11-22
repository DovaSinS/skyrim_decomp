// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1fd470, ArrayLeaf1fd470Storage, ArrayLeaf1fd470Size, FreeArrayLeaf1fd470, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1fd470Storage
{
    ~ArrayLeaf1fd470Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1fd470Size
{
    ~ArrayLeaf1fd470Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1fd470 : public ArrayLeaf1fd470Storage, public ArrayLeaf1fd470Size
{
    ~ArrayLeaf1fd470();  // compared: 0x1fd470
};

void FreeArrayLeaf1fd470(ArrayLeaf1fd470* array);

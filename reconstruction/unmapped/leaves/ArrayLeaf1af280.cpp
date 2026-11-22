// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1af280 ArrayLeaf1af280::~ArrayLeaf1af280
// Adapted bodies: none
// CI hash: 0x1af280 ??1ArrayLeaf1af280@@QEAA@XZ
#include "ArrayLeaf1af280.h"

ArrayLeaf1af280::~ArrayLeaf1af280()
{
    if (data) {
        FreeArrayLeaf1af280(this);
        size = 0;
    }
}

// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1af160 ArrayLeaf1af160::~ArrayLeaf1af160
// Adapted bodies: none
// CI hash: 0x1af160 ??1ArrayLeaf1af160@@QEAA@XZ
#include "ArrayLeaf1af160.h"

ArrayLeaf1af160::~ArrayLeaf1af160()
{
    if (data) {
        FreeArrayLeaf1af160(this);
        size = 0;
    }
}

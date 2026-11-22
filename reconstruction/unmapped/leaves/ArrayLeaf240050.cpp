// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x240050 ArrayLeaf240050::~ArrayLeaf240050
// Adapted bodies: none
// CI hash: 0x240050 ??1ArrayLeaf240050@@QEAA@XZ
#include "ArrayLeaf240050.h"

ArrayLeaf240050::~ArrayLeaf240050()
{
    if (data) {
        FreeArrayLeaf240050(this);
        size = 0;
    }
}

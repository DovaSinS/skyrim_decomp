// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x31bc90 ArrayLeaf31bc90::~ArrayLeaf31bc90
// Adapted bodies: none
// CI hash: 0x31bc90 ??1ArrayLeaf31bc90@@QEAA@XZ
#include "ArrayLeaf31bc90.h"

ArrayLeaf31bc90::~ArrayLeaf31bc90()
{
    if (data) {
        FreeArrayLeaf31bc90(this);
        size = 0;
    }
}

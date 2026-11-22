// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1eed80 ArrayLeaf1eed80::~ArrayLeaf1eed80
// Adapted bodies: none
// CI hash: 0x1eed80 ??1ArrayLeaf1eed80@@QEAA@XZ
#include "ArrayLeaf1eed80.h"

ArrayLeaf1eed80::~ArrayLeaf1eed80()
{
    if (data) {
        FreeArrayLeaf1eed80(this);
        size = 0;
    }
}

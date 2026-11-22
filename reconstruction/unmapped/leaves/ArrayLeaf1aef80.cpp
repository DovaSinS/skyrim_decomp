// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1aef80 ArrayLeaf1aef80::~ArrayLeaf1aef80
// Adapted bodies: none
// CI hash: 0x1aef80 ??1ArrayLeaf1aef80@@QEAA@XZ
#include "ArrayLeaf1aef80.h"

ArrayLeaf1aef80::~ArrayLeaf1aef80()
{
    if (data) {
        FreeArrayLeaf1aef80(this);
        size = 0;
    }
}

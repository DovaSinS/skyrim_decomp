// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1af040 ArrayLeaf1af040::~ArrayLeaf1af040
// Adapted bodies: none
// CI hash: 0x1af040 ??1ArrayLeaf1af040@@QEAA@XZ
#include "ArrayLeaf1af040.h"

ArrayLeaf1af040::~ArrayLeaf1af040()
{
    if (data) {
        FreeArrayLeaf1af040(this);
        size = 0;
    }
}

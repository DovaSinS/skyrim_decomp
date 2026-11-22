// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1aee00 ArrayLeaf1aee00::~ArrayLeaf1aee00
// Adapted bodies: none
// CI hash: 0x1aee00 ??1ArrayLeaf1aee00@@QEAA@XZ
#include "ArrayLeaf1aee00.h"

ArrayLeaf1aee00::~ArrayLeaf1aee00()
{
    if (data) {
        FreeArrayLeaf1aee00(this);
        size = 0;
    }
}

// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1af580 ArrayLeaf1af580::~ArrayLeaf1af580
// Adapted bodies: none
// CI hash: 0x1af580 ??1ArrayLeaf1af580@@QEAA@XZ
#include "ArrayLeaf1af580.h"

ArrayLeaf1af580::~ArrayLeaf1af580()
{
    if (data) {
        FreeArrayLeaf1af580(this);
        size = 0;
    }
}

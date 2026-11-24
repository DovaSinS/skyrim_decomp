// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: BSFile::ReadBytes.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bssystem/bsfile.cpp:91
// 0xebea00 BSFile::ReadBytes
#include "Archive_ebea00.h"

unsigned int BSFile::ReadBytes(void* buffer, unsigned int bytes)
{
    if (!static_cast<bool>(static_cast<int>(m_pFile != 0)))
        Open(false, false);
    unsigned int result = NiFile::FileRead(buffer, bytes);
    m_uiBufferSize += result;
    return result;
}

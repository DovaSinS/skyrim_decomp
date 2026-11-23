// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xee6ec0 NiStream::SaveObjectSizeTable
// Adapted bodies: none
#include "NiStream_ee6ec0.h"

// WriteUInt32: GUESS(low); the stream's integer write helper
static void WriteUInt32(NiBinaryStream* a_stream, std::uint32_t a_value)
{
    std::uint32_t width = sizeof(a_value);
    const std::uint32_t transferred = a_stream->_writeFn(a_stream, &a_value, sizeof(a_value), &width, 1);
    a_stream->_absoluteCurrentPos += transferred;
}

bool NiStream::SaveObjectSizeTable(std::uint32_t a_size)
{
    const std::uint32_t position = oStr->tell();
    const std::int32_t delta = static_cast<std::int32_t>(position - a_size);
    oStr->seek(-delta);
    for (std::uint32_t i = 0; i < sizesCount; ++i) {
        WriteUInt32(oStr, sizesData[i]);
    }
    return true;
}

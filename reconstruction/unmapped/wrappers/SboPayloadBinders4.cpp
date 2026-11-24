// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// SboPayloadBinders4, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
// CI hash: 0x13b6220 ?Wrap13b6220@SboPayloadBinders4@@SA?AUSboPayloadBinders4SboBinding@@PEAPEAXPEAUSboPayloadBinders4PayloadBox@@_K@Z
// CI hash: 0x13b70d0 ?Wrap13b70d0@SboPayloadBinders4@@SA?AUSboPayloadBinders4SboBinding@@PEAPEAXPEAUSboPayloadBinders4PayloadBox@@_K@Z
// CI hash: 0x13c5f60 ?Wrap13c5f60@SboPayloadBinders4@@SA?AUSboPayloadBinders4SboBinding@@PEAPEAXPEAUSboPayloadBinders4PayloadBox@@_K@Z
// CI hash: 0x13c6ad0 ?Wrap13c6ad0@SboPayloadBinders4@@SA?AUSboPayloadBinders4SboBinding@@PEAPEAXPEAUSboPayloadBinders4PayloadBox@@_K@Z
// CI hash: 0x13c76d0 ?Wrap13c76d0@SboPayloadBinders4@@SA?AUSboPayloadBinders4SboBinding@@PEAPEAXPEAUSboPayloadBinders4PayloadBox@@_K@Z
// CI hash: 0x13c8280 ?Wrap13c8280@SboPayloadBinders4@@SA?AUSboPayloadBinders4SboBinding@@PEAPEAXPEAUSboPayloadBinders4PayloadBox@@_K@Z
// CI hash: 0x13c8d20 ?Wrap13c8d20@SboPayloadBinders4@@SA?AUSboPayloadBinders4SboBinding@@PEAPEAXPEAUSboPayloadBinders4PayloadBox@@_K@Z
// CI hash: 0x13c9810 ?Wrap13c9810@SboPayloadBinders4@@SA?AUSboPayloadBinders4SboBinding@@PEAPEAXPEAUSboPayloadBinders4PayloadBox@@_K@Z
// CI hash: 0x13ca340 ?Wrap13ca340@SboPayloadBinders4@@SA?AUSboPayloadBinders4SboBinding@@PEAPEAXPEAUSboPayloadBinders4PayloadBox@@_K@Z
// CI hash: 0x13cac90 ?Wrap13cac90@SboPayloadBinders4@@SA?AUSboPayloadBinders4SboBinding@@PEAPEAXPEAUSboPayloadBinders4PayloadBox@@_K@Z
// CI hash: 0x1421bf0 ?Wrap1421bf0@SboPayloadBinders4@@SA?AUSboPayloadBinders4SboBinding@@PEAPEAXPEAUSboPayloadBinders4PayloadBox@@_K@Z
// CI hash: 0x1423450 ?Wrap1423450@SboPayloadBinders4@@SA?AUSboPayloadBinders4SboBinding@@PEAPEAXPEAUSboPayloadBinders4PayloadBox@@_K@Z
// CI hash: 0x1431500 ?Wrap1431500@SboPayloadBinders4@@SA?AUSboPayloadBinders4SboBinding@@PEAPEAXPEAUSboPayloadBinders4PayloadBox@@_K@Z
// CI hash: 0x1431600 ?Wrap1431600@SboPayloadBinders4@@SA?AUSboPayloadBinders4SboBinding@@PEAPEAXPEAUSboPayloadBinders4PayloadBox@@_K@Z
// CI hash: 0x1431700 ?Wrap1431700@SboPayloadBinders4@@SA?AUSboPayloadBinders4SboBinding@@PEAPEAXPEAUSboPayloadBinders4PayloadBox@@_K@Z
// CI hash: 0x1431800 ?Wrap1431800@SboPayloadBinders4@@SA?AUSboPayloadBinders4SboBinding@@PEAPEAXPEAUSboPayloadBinders4PayloadBox@@_K@Z
// CI hash: 0x1431900 ?Wrap1431900@SboPayloadBinders4@@SA?AUSboPayloadBinders4SboBinding@@PEAPEAXPEAUSboPayloadBinders4PayloadBox@@_K@Z
// CI hash: 0x145d200 ?Wrap145d200@SboPayloadBinders4@@SA?AUSboPayloadBinders4SboBinding@@PEAPEAXPEAUSboPayloadBinders4PayloadBox@@_K@Z
// CI hash: 0x145d300 ?Wrap145d300@SboPayloadBinders4@@SA?AUSboPayloadBinders4SboBinding@@PEAPEAXPEAUSboPayloadBinders4PayloadBox@@_K@Z
// CI hash: 0x145d400 ?Wrap145d400@SboPayloadBinders4@@SA?AUSboPayloadBinders4SboBinding@@PEAPEAXPEAUSboPayloadBinders4PayloadBox@@_K@Z
// 0x13b6220 SboPayloadBinders4::Wrap13b6220
// 0x13b70d0 SboPayloadBinders4::Wrap13b70d0
// 0x13c5f60 SboPayloadBinders4::Wrap13c5f60
// 0x13c6ad0 SboPayloadBinders4::Wrap13c6ad0
// 0x13c76d0 SboPayloadBinders4::Wrap13c76d0
// 0x13c8280 SboPayloadBinders4::Wrap13c8280
// 0x13c8d20 SboPayloadBinders4::Wrap13c8d20
// 0x13c9810 SboPayloadBinders4::Wrap13c9810
// 0x13ca340 SboPayloadBinders4::Wrap13ca340
// 0x13cac90 SboPayloadBinders4::Wrap13cac90
// 0x1421bf0 SboPayloadBinders4::Wrap1421bf0
// 0x1423450 SboPayloadBinders4::Wrap1423450
// 0x1431500 SboPayloadBinders4::Wrap1431500
// 0x1431600 SboPayloadBinders4::Wrap1431600
// 0x1431700 SboPayloadBinders4::Wrap1431700
// 0x1431800 SboPayloadBinders4::Wrap1431800
// 0x1431900 SboPayloadBinders4::Wrap1431900
// 0x145d200 SboPayloadBinders4::Wrap145d200
// 0x145d300 SboPayloadBinders4::Wrap145d300
// 0x145d400 SboPayloadBinders4::Wrap145d400
#include "SboPayloadBinders4.h"

SboPayloadBinders4SboBinding SboPayloadBinders4::Wrap13b6220(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders4SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b058d0;
        buf->payload = *src;
        buf->table = Table_1b058f0;
        result.instance = buf;
        result.cleanup = Cleanup_13b6db0;
        return result;
    }
    if (!LogFilter_128c360(gLogChannel_20d5024, 0))
    {
        if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 0)
        {
            LogConsole_12586a0(0, Text_1acd8d0, 16ull);
        }
        if (LogSinkEn_128c1a0(0, gLogChannel_20d5024))
        {
            LogSink_12586e0(0, Text_1acd8d0, 16ull);
        }
    }
    SboPayloadBinders4PayloadBox* heap = static_cast<SboPayloadBinders4PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b058d0;
    heap->payload = *src;
    heap->table = Table_1b058f0;
    result.cleanup = Cleanup_13b61a0;
    return result;
}

SboPayloadBinders4SboBinding SboPayloadBinders4::Wrap13b70d0(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders4SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b05ad8;
        buf->payload = *src;
        buf->table = Table_1b05af8;
        result.instance = buf;
        result.cleanup = Cleanup_13b7860;
        return result;
    }
    if (!LogFilter_128c360(gLogChannel_20d5024, 0))
    {
        if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 0)
        {
            LogConsole_12586a0(0, Text_1acd8d0, 16ull);
        }
        if (LogSinkEn_128c1a0(0, gLogChannel_20d5024))
        {
            LogSink_12586e0(0, Text_1acd8d0, 16ull);
        }
    }
    SboPayloadBinders4PayloadBox* heap = static_cast<SboPayloadBinders4PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b05ad8;
    heap->payload = *src;
    heap->table = Table_1b05af8;
    result.cleanup = Cleanup_13b7010;
    return result;
}

SboPayloadBinders4SboBinding SboPayloadBinders4::Wrap13c5f60(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders4SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b08c78;
        buf->payload = *src;
        buf->table = Table_1b08c98;
        result.instance = buf;
        result.cleanup = Cleanup_13c6760;
        return result;
    }
    if (!LogFilter_128c360(gLogChannel_20d5024, 0))
    {
        if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 0)
        {
            LogConsole_12586a0(0, Text_1acd8d0, 16ull);
        }
        if (LogSinkEn_128c1a0(0, gLogChannel_20d5024))
        {
            LogSink_12586e0(0, Text_1acd8d0, 16ull);
        }
    }
    SboPayloadBinders4PayloadBox* heap = static_cast<SboPayloadBinders4PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b08c78;
    heap->payload = *src;
    heap->table = Table_1b08c98;
    result.cleanup = Cleanup_13c5ea0;
    return result;
}

SboPayloadBinders4SboBinding SboPayloadBinders4::Wrap13c6ad0(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders4SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b08e80;
        buf->payload = *src;
        buf->table = Table_1b08ea0;
        result.instance = buf;
        result.cleanup = Cleanup_13c7360;
        return result;
    }
    if (!LogFilter_128c360(gLogChannel_20d5024, 0))
    {
        if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 0)
        {
            LogConsole_12586a0(0, Text_1acd8d0, 16ull);
        }
        if (LogSinkEn_128c1a0(0, gLogChannel_20d5024))
        {
            LogSink_12586e0(0, Text_1acd8d0, 16ull);
        }
    }
    SboPayloadBinders4PayloadBox* heap = static_cast<SboPayloadBinders4PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b08e80;
    heap->payload = *src;
    heap->table = Table_1b08ea0;
    result.cleanup = Cleanup_13c6a10;
    return result;
}

SboPayloadBinders4SboBinding SboPayloadBinders4::Wrap13c76d0(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders4SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b09088;
        buf->payload = *src;
        buf->table = Table_1b090a8;
        result.instance = buf;
        result.cleanup = Cleanup_13c7f60;
        return result;
    }
    if (!LogFilter_128c360(gLogChannel_20d5024, 0))
    {
        if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 0)
        {
            LogConsole_12586a0(0, Text_1acd8d0, 16ull);
        }
        if (LogSinkEn_128c1a0(0, gLogChannel_20d5024))
        {
            LogSink_12586e0(0, Text_1acd8d0, 16ull);
        }
    }
    SboPayloadBinders4PayloadBox* heap = static_cast<SboPayloadBinders4PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b09088;
    heap->payload = *src;
    heap->table = Table_1b090a8;
    result.cleanup = Cleanup_13c7610;
    return result;
}

SboPayloadBinders4SboBinding SboPayloadBinders4::Wrap13c8280(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders4SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b09290;
        buf->payload = *src;
        buf->table = Table_1b092b0;
        result.instance = buf;
        result.cleanup = Cleanup_13c8a10;
        return result;
    }
    if (!LogFilter_128c360(gLogChannel_20d5024, 0))
    {
        if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 0)
        {
            LogConsole_12586a0(0, Text_1acd8d0, 16ull);
        }
        if (LogSinkEn_128c1a0(0, gLogChannel_20d5024))
        {
            LogSink_12586e0(0, Text_1acd8d0, 16ull);
        }
    }
    SboPayloadBinders4PayloadBox* heap = static_cast<SboPayloadBinders4PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b09290;
    heap->payload = *src;
    heap->table = Table_1b092b0;
    result.cleanup = Cleanup_13c81c0;
    return result;
}

SboPayloadBinders4SboBinding SboPayloadBinders4::Wrap13c8d20(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders4SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b09498;
        buf->payload = *src;
        buf->table = Table_1b094b8;
        result.instance = buf;
        result.cleanup = Cleanup_13c94a0;
        return result;
    }
    if (!LogFilter_128c360(gLogChannel_20d5024, 0))
    {
        if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 0)
        {
            LogConsole_12586a0(0, Text_1acd8d0, 16ull);
        }
        if (LogSinkEn_128c1a0(0, gLogChannel_20d5024))
        {
            LogSink_12586e0(0, Text_1acd8d0, 16ull);
        }
    }
    SboPayloadBinders4PayloadBox* heap = static_cast<SboPayloadBinders4PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b09498;
    heap->payload = *src;
    heap->table = Table_1b094b8;
    result.cleanup = Cleanup_13c8c60;
    return result;
}

SboPayloadBinders4SboBinding SboPayloadBinders4::Wrap13c9810(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders4SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b096a0;
        buf->payload = *src;
        buf->table = Table_1b096c0;
        result.instance = buf;
        result.cleanup = Cleanup_13ca060;
        return result;
    }
    if (!LogFilter_128c360(gLogChannel_20d5024, 0))
    {
        if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 0)
        {
            LogConsole_12586a0(0, Text_1acd8d0, 16ull);
        }
        if (LogSinkEn_128c1a0(0, gLogChannel_20d5024))
        {
            LogSink_12586e0(0, Text_1acd8d0, 16ull);
        }
    }
    SboPayloadBinders4PayloadBox* heap = static_cast<SboPayloadBinders4PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b096a0;
    heap->payload = *src;
    heap->table = Table_1b096c0;
    result.cleanup = Cleanup_13c9750;
    return result;
}

SboPayloadBinders4SboBinding SboPayloadBinders4::Wrap13ca340(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders4SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b098a8;
        buf->payload = *src;
        buf->table = Table_1b098c8;
        result.instance = buf;
        result.cleanup = Cleanup_13caa40;
        return result;
    }
    if (!LogFilter_128c360(gLogChannel_20d5024, 0))
    {
        if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 0)
        {
            LogConsole_12586a0(0, Text_1acd8d0, 16ull);
        }
        if (LogSinkEn_128c1a0(0, gLogChannel_20d5024))
        {
            LogSink_12586e0(0, Text_1acd8d0, 16ull);
        }
    }
    SboPayloadBinders4PayloadBox* heap = static_cast<SboPayloadBinders4PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b098a8;
    heap->payload = *src;
    heap->table = Table_1b098c8;
    result.cleanup = Cleanup_13ca280;
    return result;
}

SboPayloadBinders4SboBinding SboPayloadBinders4::Wrap13cac90(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders4SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b09a38;
        buf->payload = *src;
        buf->table = Table_1b09a58;
        result.instance = buf;
        result.cleanup = Cleanup_13cb310;
        return result;
    }
    if (!LogFilter_128c360(gLogChannel_20d5024, 0))
    {
        if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 0)
        {
            LogConsole_12586a0(0, Text_1acd8d0, 16ull);
        }
        if (LogSinkEn_128c1a0(0, gLogChannel_20d5024))
        {
            LogSink_12586e0(0, Text_1acd8d0, 16ull);
        }
    }
    SboPayloadBinders4PayloadBox* heap = static_cast<SboPayloadBinders4PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b09a38;
    heap->payload = *src;
    heap->table = Table_1b09a58;
    result.cleanup = Cleanup_13cac10;
    return result;
}

SboPayloadBinders4SboBinding SboPayloadBinders4::Wrap1421bf0(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders4SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b13460;
        buf->payload = *src;
        buf->table = Table_1b13480;
        result.instance = buf;
        result.cleanup = Cleanup_14224a0;
        return result;
    }
    if (!LogFilter_128c360(gLogChannel_20d5024, 0))
    {
        if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 0)
        {
            LogConsole_12586a0(0, Text_1acd8d0, 16ull);
        }
        if (LogSinkEn_128c1a0(0, gLogChannel_20d5024))
        {
            LogSink_12586e0(0, Text_1acd8d0, 16ull);
        }
    }
    SboPayloadBinders4PayloadBox* heap = static_cast<SboPayloadBinders4PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b13460;
    heap->payload = *src;
    heap->table = Table_1b13480;
    result.cleanup = Cleanup_1421bb0;
    return result;
}

SboPayloadBinders4SboBinding SboPayloadBinders4::Wrap1423450(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders4SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b136e0;
        buf->payload = *src;
        buf->table = Table_1b13700;
        result.instance = buf;
        result.cleanup = Cleanup_1423ea0;
        return result;
    }
    if (!LogFilter_128c360(gLogChannel_20d5024, 0))
    {
        if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 0)
        {
            LogConsole_12586a0(0, Text_1acd8d0, 16ull);
        }
        if (LogSinkEn_128c1a0(0, gLogChannel_20d5024))
        {
            LogSink_12586e0(0, Text_1acd8d0, 16ull);
        }
    }
    SboPayloadBinders4PayloadBox* heap = static_cast<SboPayloadBinders4PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b136e0;
    heap->payload = *src;
    heap->table = Table_1b13700;
    result.cleanup = Cleanup_14233d0;
    return result;
}

SboPayloadBinders4SboBinding SboPayloadBinders4::Wrap1431500(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders4SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b15e20;
        buf->payload = *src;
        buf->table = Table_1b15e40;
        result.instance = buf;
        result.cleanup = Cleanup_14348f0;
        return result;
    }
    if (!LogFilter_128c360(gLogChannel_20d5024, 0))
    {
        if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 0)
        {
            LogConsole_12586a0(0, Text_1acd8d0, 16ull);
        }
        if (LogSinkEn_128c1a0(0, gLogChannel_20d5024))
        {
            LogSink_12586e0(0, Text_1acd8d0, 16ull);
        }
    }
    SboPayloadBinders4PayloadBox* heap = static_cast<SboPayloadBinders4PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b15e20;
    heap->payload = *src;
    heap->table = Table_1b15e40;
    result.cleanup = Cleanup_14311d0;
    return result;
}

SboPayloadBinders4SboBinding SboPayloadBinders4::Wrap1431600(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders4SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b15de0;
        buf->payload = *src;
        buf->table = Table_1b15e00;
        result.instance = buf;
        result.cleanup = Cleanup_1434900;
        return result;
    }
    if (!LogFilter_128c360(gLogChannel_20d5024, 0))
    {
        if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 0)
        {
            LogConsole_12586a0(0, Text_1acd8d0, 16ull);
        }
        if (LogSinkEn_128c1a0(0, gLogChannel_20d5024))
        {
            LogSink_12586e0(0, Text_1acd8d0, 16ull);
        }
    }
    SboPayloadBinders4PayloadBox* heap = static_cast<SboPayloadBinders4PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b15de0;
    heap->payload = *src;
    heap->table = Table_1b15e00;
    result.cleanup = Cleanup_1431210;
    return result;
}

SboPayloadBinders4SboBinding SboPayloadBinders4::Wrap1431700(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders4SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b15d60;
        buf->payload = *src;
        buf->table = Table_1b15d80;
        result.instance = buf;
        result.cleanup = Cleanup_1434910;
        return result;
    }
    if (!LogFilter_128c360(gLogChannel_20d5024, 0))
    {
        if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 0)
        {
            LogConsole_12586a0(0, Text_1acd8d0, 16ull);
        }
        if (LogSinkEn_128c1a0(0, gLogChannel_20d5024))
        {
            LogSink_12586e0(0, Text_1acd8d0, 16ull);
        }
    }
    SboPayloadBinders4PayloadBox* heap = static_cast<SboPayloadBinders4PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b15d60;
    heap->payload = *src;
    heap->table = Table_1b15d80;
    result.cleanup = Cleanup_1431250;
    return result;
}

SboPayloadBinders4SboBinding SboPayloadBinders4::Wrap1431800(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders4SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b15ce0;
        buf->payload = *src;
        buf->table = Table_1b15d00;
        result.instance = buf;
        result.cleanup = Cleanup_1434920;
        return result;
    }
    if (!LogFilter_128c360(gLogChannel_20d5024, 0))
    {
        if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 0)
        {
            LogConsole_12586a0(0, Text_1acd8d0, 16ull);
        }
        if (LogSinkEn_128c1a0(0, gLogChannel_20d5024))
        {
            LogSink_12586e0(0, Text_1acd8d0, 16ull);
        }
    }
    SboPayloadBinders4PayloadBox* heap = static_cast<SboPayloadBinders4PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b15ce0;
    heap->payload = *src;
    heap->table = Table_1b15d00;
    result.cleanup = Cleanup_1431290;
    return result;
}

SboPayloadBinders4SboBinding SboPayloadBinders4::Wrap1431900(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders4SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b15da0;
        buf->payload = *src;
        buf->table = Table_1b15dc0;
        result.instance = buf;
        result.cleanup = Cleanup_1434930;
        return result;
    }
    if (!LogFilter_128c360(gLogChannel_20d5024, 0))
    {
        if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 0)
        {
            LogConsole_12586a0(0, Text_1acd8d0, 16ull);
        }
        if (LogSinkEn_128c1a0(0, gLogChannel_20d5024))
        {
            LogSink_12586e0(0, Text_1acd8d0, 16ull);
        }
    }
    SboPayloadBinders4PayloadBox* heap = static_cast<SboPayloadBinders4PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b15da0;
    heap->payload = *src;
    heap->table = Table_1b15dc0;
    result.cleanup = Cleanup_14312d0;
    return result;
}

SboPayloadBinders4SboBinding SboPayloadBinders4::Wrap145d200(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders4SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b1d940;
        buf->payload = *src;
        buf->table = Table_1b1d960;
        result.instance = buf;
        result.cleanup = Cleanup_146b6b0;
        return result;
    }
    if (!LogFilter_128c360(gLogChannel_20d5024, 0))
    {
        if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 0)
        {
            LogConsole_12586a0(0, Text_1acd8d0, 16ull);
        }
        if (LogSinkEn_128c1a0(0, gLogChannel_20d5024))
        {
            LogSink_12586e0(0, Text_1acd8d0, 16ull);
        }
    }
    SboPayloadBinders4PayloadBox* heap = static_cast<SboPayloadBinders4PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b1d940;
    heap->payload = *src;
    heap->table = Table_1b1d960;
    result.cleanup = Cleanup_145cc30;
    return result;
}

SboPayloadBinders4SboBinding SboPayloadBinders4::Wrap145d300(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders4SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b1d9c0;
        buf->payload = *src;
        buf->table = Table_1b1d9e0;
        result.instance = buf;
        result.cleanup = Cleanup_146b6c0;
        return result;
    }
    if (!LogFilter_128c360(gLogChannel_20d5024, 0))
    {
        if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 0)
        {
            LogConsole_12586a0(0, Text_1acd8d0, 16ull);
        }
        if (LogSinkEn_128c1a0(0, gLogChannel_20d5024))
        {
            LogSink_12586e0(0, Text_1acd8d0, 16ull);
        }
    }
    SboPayloadBinders4PayloadBox* heap = static_cast<SboPayloadBinders4PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b1d9c0;
    heap->payload = *src;
    heap->table = Table_1b1d9e0;
    result.cleanup = Cleanup_145cc70;
    return result;
}

SboPayloadBinders4SboBinding SboPayloadBinders4::Wrap145d400(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders4SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b1dac8;
        buf->payload = *src;
        buf->table = Table_1b1dae8;
        result.instance = buf;
        result.cleanup = Cleanup_146b6d0;
        return result;
    }
    if (!LogFilter_128c360(gLogChannel_20d5024, 0))
    {
        if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 0)
        {
            LogConsole_12586a0(0, Text_1acd8d0, 16ull);
        }
        if (LogSinkEn_128c1a0(0, gLogChannel_20d5024))
        {
            LogSink_12586e0(0, Text_1acd8d0, 16ull);
        }
    }
    SboPayloadBinders4PayloadBox* heap = static_cast<SboPayloadBinders4PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b1dac8;
    heap->payload = *src;
    heap->table = Table_1b1dae8;
    result.cleanup = Cleanup_145ccb0;
    return result;
}

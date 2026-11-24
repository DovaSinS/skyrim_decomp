// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// SboPayloadBinders2, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
// CI hash: 0x12cd410 ?Wrap12cd410@SboPayloadBinders2@@SA?AUSboPayloadBinders2SboBinding@@PEAPEAXPEAUSboPayloadBinders2PayloadBox@@_K@Z
// CI hash: 0x12d0780 ?Wrap12d0780@SboPayloadBinders2@@SA?AUSboPayloadBinders2SboBinding@@PEAPEAXPEAUSboPayloadBinders2PayloadBox@@_K@Z
// CI hash: 0x12d0880 ?Wrap12d0880@SboPayloadBinders2@@SA?AUSboPayloadBinders2SboBinding@@PEAPEAXPEAUSboPayloadBinders2PayloadBox@@_K@Z
// CI hash: 0x12d0980 ?Wrap12d0980@SboPayloadBinders2@@SA?AUSboPayloadBinders2SboBinding@@PEAPEAXPEAUSboPayloadBinders2PayloadBox@@_K@Z
// CI hash: 0x12d0b40 ?Wrap12d0b40@SboPayloadBinders2@@SA?AUSboPayloadBinders2SboBinding@@PEAPEAXPEAUSboPayloadBinders2PayloadBox@@_K@Z
// CI hash: 0x12eb400 ?Wrap12eb400@SboPayloadBinders2@@SA?AUSboPayloadBinders2SboBinding@@PEAPEAXPEAUSboPayloadBinders2PayloadBox@@_K@Z
// CI hash: 0x12eb500 ?Wrap12eb500@SboPayloadBinders2@@SA?AUSboPayloadBinders2SboBinding@@PEAPEAXPEAUSboPayloadBinders2PayloadBox@@_K@Z
// CI hash: 0x12edf10 ?Wrap12edf10@SboPayloadBinders2@@SA?AUSboPayloadBinders2SboBinding@@PEAPEAXPEAUSboPayloadBinders2PayloadBox@@_K@Z
// CI hash: 0x12ee010 ?Wrap12ee010@SboPayloadBinders2@@SA?AUSboPayloadBinders2SboBinding@@PEAPEAXPEAUSboPayloadBinders2PayloadBox@@_K@Z
// CI hash: 0x12f82d0 ?Wrap12f82d0@SboPayloadBinders2@@SA?AUSboPayloadBinders2SboBinding@@PEAPEAXPEAUSboPayloadBinders2PayloadBox@@_K@Z
// CI hash: 0x12f8490 ?Wrap12f8490@SboPayloadBinders2@@SA?AUSboPayloadBinders2SboBinding@@PEAPEAXPEAUSboPayloadBinders2PayloadBox@@_K@Z
// CI hash: 0x12f8590 ?Wrap12f8590@SboPayloadBinders2@@SA?AUSboPayloadBinders2SboBinding@@PEAPEAXPEAUSboPayloadBinders2PayloadBox@@_K@Z
// CI hash: 0x130bbb0 ?Wrap130bbb0@SboPayloadBinders2@@SA?AUSboPayloadBinders2SboBinding@@PEAPEAXPEAUSboPayloadBinders2PayloadBox@@_K@Z
// CI hash: 0x130bcb0 ?Wrap130bcb0@SboPayloadBinders2@@SA?AUSboPayloadBinders2SboBinding@@PEAPEAXPEAUSboPayloadBinders2PayloadBox@@_K@Z
// CI hash: 0x1332470 ?Wrap1332470@SboPayloadBinders2@@SA?AUSboPayloadBinders2SboBinding@@PEAPEAXPEAUSboPayloadBinders2PayloadBox@@_K@Z
// CI hash: 0x1332690 ?Wrap1332690@SboPayloadBinders2@@SA?AUSboPayloadBinders2SboBinding@@PEAPEAXPEAUSboPayloadBinders2PayloadBox@@_K@Z
// CI hash: 0x1333070 ?Wrap1333070@SboPayloadBinders2@@SA?AUSboPayloadBinders2SboBinding@@PEAPEAXPEAUSboPayloadBinders2PayloadBox@@_K@Z
// CI hash: 0x13333b0 ?Wrap13333b0@SboPayloadBinders2@@SA?AUSboPayloadBinders2SboBinding@@PEAPEAXPEAUSboPayloadBinders2PayloadBox@@_K@Z
// CI hash: 0x1386340 ?Wrap1386340@SboPayloadBinders2@@SA?AUSboPayloadBinders2SboBinding@@PEAPEAXPEAUSboPayloadBinders2PayloadBox@@_K@Z
// CI hash: 0x138c560 ?Wrap138c560@SboPayloadBinders2@@SA?AUSboPayloadBinders2SboBinding@@PEAPEAXPEAUSboPayloadBinders2PayloadBox@@_K@Z
// 0x12cd410 SboPayloadBinders2::Wrap12cd410
// 0x12d0780 SboPayloadBinders2::Wrap12d0780
// 0x12d0880 SboPayloadBinders2::Wrap12d0880
// 0x12d0980 SboPayloadBinders2::Wrap12d0980
// 0x12d0b40 SboPayloadBinders2::Wrap12d0b40
// 0x12eb400 SboPayloadBinders2::Wrap12eb400
// 0x12eb500 SboPayloadBinders2::Wrap12eb500
// 0x12edf10 SboPayloadBinders2::Wrap12edf10
// 0x12ee010 SboPayloadBinders2::Wrap12ee010
// 0x12f82d0 SboPayloadBinders2::Wrap12f82d0
// 0x12f8490 SboPayloadBinders2::Wrap12f8490
// 0x12f8590 SboPayloadBinders2::Wrap12f8590
// 0x130bbb0 SboPayloadBinders2::Wrap130bbb0
// 0x130bcb0 SboPayloadBinders2::Wrap130bcb0
// 0x1332470 SboPayloadBinders2::Wrap1332470
// 0x1332690 SboPayloadBinders2::Wrap1332690
// 0x1333070 SboPayloadBinders2::Wrap1333070
// 0x13333b0 SboPayloadBinders2::Wrap13333b0
// 0x1386340 SboPayloadBinders2::Wrap1386340
// 0x138c560 SboPayloadBinders2::Wrap138c560
#include "SboPayloadBinders2.h"

SboPayloadBinders2SboBinding SboPayloadBinders2::Wrap12cd410(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ae0d90;
        buf->payload = *src;
        buf->table = Table_1ae0db8;
        result.instance = buf;
        result.cleanup = Cleanup_12ceb90;
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
    SboPayloadBinders2PayloadBox* heap = static_cast<SboPayloadBinders2PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ae0d90;
    heap->payload = *src;
    heap->table = Table_1ae0db8;
    result.cleanup = Cleanup_12cd3d0;
    return result;
}

SboPayloadBinders2SboBinding SboPayloadBinders2::Wrap12d0780(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ae19a8;
        buf->payload = *src;
        buf->table = Table_1ae19d0;
        result.instance = buf;
        result.cleanup = Cleanup_12d3a70;
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
    SboPayloadBinders2PayloadBox* heap = static_cast<SboPayloadBinders2PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ae19a8;
    heap->payload = *src;
    heap->table = Table_1ae19d0;
    result.cleanup = Cleanup_12d0640;
    return result;
}

SboPayloadBinders2SboBinding SboPayloadBinders2::Wrap12d0880(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ae1958;
        buf->payload = *src;
        buf->table = Table_1ae1980;
        result.instance = buf;
        result.cleanup = Cleanup_12d3a80;
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
    SboPayloadBinders2PayloadBox* heap = static_cast<SboPayloadBinders2PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ae1958;
    heap->payload = *src;
    heap->table = Table_1ae1980;
    result.cleanup = Cleanup_12d0680;
    return result;
}

SboPayloadBinders2SboBinding SboPayloadBinders2::Wrap12d0980(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ae18b8;
        buf->payload = *src;
        buf->table = Table_1ae18e0;
        result.instance = buf;
        result.cleanup = Cleanup_12d3a90;
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
    SboPayloadBinders2PayloadBox* heap = static_cast<SboPayloadBinders2PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ae18b8;
    heap->payload = *src;
    heap->table = Table_1ae18e0;
    result.cleanup = Cleanup_12d06c0;
    return result;
}

SboPayloadBinders2SboBinding SboPayloadBinders2::Wrap12d0b40(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ae1908;
        buf->payload = *src;
        buf->table = Table_1ae1930;
        result.instance = buf;
        result.cleanup = Cleanup_12d3ab0;
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
    SboPayloadBinders2PayloadBox* heap = static_cast<SboPayloadBinders2PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ae1908;
    heap->payload = *src;
    heap->table = Table_1ae1930;
    result.cleanup = Cleanup_12d0740;
    return result;
}

SboPayloadBinders2SboBinding SboPayloadBinders2::Wrap12eb400(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ae4048;
        buf->payload = *src;
        buf->table = Table_1ae4070;
        result.instance = buf;
        result.cleanup = Cleanup_12ec6f0;
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
    SboPayloadBinders2PayloadBox* heap = static_cast<SboPayloadBinders2PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ae4048;
    heap->payload = *src;
    heap->table = Table_1ae4070;
    result.cleanup = Cleanup_12eb380;
    return result;
}

SboPayloadBinders2SboBinding SboPayloadBinders2::Wrap12eb500(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ae3ff8;
        buf->payload = *src;
        buf->table = Table_1ae4020;
        result.instance = buf;
        result.cleanup = Cleanup_12ec700;
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
    SboPayloadBinders2PayloadBox* heap = static_cast<SboPayloadBinders2PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ae3ff8;
    heap->payload = *src;
    heap->table = Table_1ae4020;
    result.cleanup = Cleanup_12eb3c0;
    return result;
}

SboPayloadBinders2SboBinding SboPayloadBinders2::Wrap12edf10(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ae4a80;
        buf->payload = *src;
        buf->table = Table_1ae4aa0;
        result.instance = buf;
        result.cleanup = Cleanup_12f07e0;
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
    SboPayloadBinders2PayloadBox* heap = static_cast<SboPayloadBinders2PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ae4a80;
    heap->payload = *src;
    heap->table = Table_1ae4aa0;
    result.cleanup = Cleanup_12ede10;
    return result;
}

SboPayloadBinders2SboBinding SboPayloadBinders2::Wrap12ee010(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ae4ac0;
        buf->payload = *src;
        buf->table = Table_1ae4ae0;
        result.instance = buf;
        result.cleanup = Cleanup_12f07f0;
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
    SboPayloadBinders2PayloadBox* heap = static_cast<SboPayloadBinders2PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ae4ac0;
    heap->payload = *src;
    heap->table = Table_1ae4ae0;
    result.cleanup = Cleanup_12ede50;
    return result;
}

SboPayloadBinders2SboBinding SboPayloadBinders2::Wrap12f82d0(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ae6cc8;
        buf->payload = *src;
        buf->table = Table_1ae6ce8;
        result.instance = buf;
        result.cleanup = Cleanup_12fd0b0;
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
    SboPayloadBinders2PayloadBox* heap = static_cast<SboPayloadBinders2PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ae6cc8;
    heap->payload = *src;
    heap->table = Table_1ae6ce8;
    result.cleanup = Cleanup_12f7da0;
    return result;
}

SboPayloadBinders2SboBinding SboPayloadBinders2::Wrap12f8490(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ae6d08;
        buf->payload = *src;
        buf->table = Table_1ae6d28;
        result.instance = buf;
        result.cleanup = Cleanup_12fd0d0;
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
    SboPayloadBinders2PayloadBox* heap = static_cast<SboPayloadBinders2PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ae6d08;
    heap->payload = *src;
    heap->table = Table_1ae6d28;
    result.cleanup = Cleanup_12f7e20;
    return result;
}

SboPayloadBinders2SboBinding SboPayloadBinders2::Wrap12f8590(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ae6d48;
        buf->payload = *src;
        buf->table = Table_1ae6d68;
        result.instance = buf;
        result.cleanup = Cleanup_12fd0e0;
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
    SboPayloadBinders2PayloadBox* heap = static_cast<SboPayloadBinders2PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ae6d48;
    heap->payload = *src;
    heap->table = Table_1ae6d68;
    result.cleanup = Cleanup_12f7e60;
    return result;
}

SboPayloadBinders2SboBinding SboPayloadBinders2::Wrap130bbb0(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ae9398;
        buf->payload = *src;
        buf->table = Table_1ae93b8;
        result.instance = buf;
        result.cleanup = Cleanup_130f110;
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
    SboPayloadBinders2PayloadBox* heap = static_cast<SboPayloadBinders2PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ae9398;
    heap->payload = *src;
    heap->table = Table_1ae93b8;
    result.cleanup = Cleanup_130b7e0;
    return result;
}

SboPayloadBinders2SboBinding SboPayloadBinders2::Wrap130bcb0(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ae9358;
        buf->payload = *src;
        buf->table = Table_1ae9378;
        result.instance = buf;
        result.cleanup = Cleanup_130f120;
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
    SboPayloadBinders2PayloadBox* heap = static_cast<SboPayloadBinders2PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ae9358;
    heap->payload = *src;
    heap->table = Table_1ae9378;
    result.cleanup = Cleanup_130b820;
    return result;
}

SboPayloadBinders2SboBinding SboPayloadBinders2::Wrap1332470(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1aefd08;
        buf->payload = *src;
        buf->table = Table_1aefd30;
        result.instance = buf;
        result.cleanup = Cleanup_133b750;
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
    SboPayloadBinders2PayloadBox* heap = static_cast<SboPayloadBinders2PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1aefd08;
    heap->payload = *src;
    heap->table = Table_1aefd30;
    result.cleanup = Cleanup_1331e70;
    return result;
}

SboPayloadBinders2SboBinding SboPayloadBinders2::Wrap1332690(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1aefc68;
        buf->payload = *src;
        buf->table = Table_1aefc90;
        result.instance = buf;
        result.cleanup = Cleanup_133b770;
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
    SboPayloadBinders2PayloadBox* heap = static_cast<SboPayloadBinders2PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1aefc68;
    heap->payload = *src;
    heap->table = Table_1aefc90;
    result.cleanup = Cleanup_1331ef0;
    return result;
}

SboPayloadBinders2SboBinding SboPayloadBinders2::Wrap1333070(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1af01b8;
        buf->payload = *src;
        buf->table = Table_1af01e0;
        result.instance = buf;
        result.cleanup = Cleanup_133b810;
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
    SboPayloadBinders2PayloadBox* heap = static_cast<SboPayloadBinders2PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1af01b8;
    heap->payload = *src;
    heap->table = Table_1af01e0;
    result.cleanup = Cleanup_1332170;
    return result;
}

SboPayloadBinders2SboBinding SboPayloadBinders2::Wrap13333b0(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1aefd58;
        buf->payload = *src;
        buf->table = Table_1aefd80;
        result.instance = buf;
        result.cleanup = Cleanup_133b850;
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
    SboPayloadBinders2PayloadBox* heap = static_cast<SboPayloadBinders2PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1aefd58;
    heap->payload = *src;
    heap->table = Table_1aefd80;
    result.cleanup = Cleanup_1332270;
    return result;
}

SboPayloadBinders2SboBinding SboPayloadBinders2::Wrap1386340(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1afe2b0;
        buf->payload = *src;
        buf->table = Table_1afe2d0;
        result.instance = buf;
        result.cleanup = Cleanup_1388500;
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
    SboPayloadBinders2PayloadBox* heap = static_cast<SboPayloadBinders2PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1afe2b0;
    heap->payload = *src;
    heap->table = Table_1afe2d0;
    result.cleanup = Cleanup_1386080;
    return result;
}

SboPayloadBinders2SboBinding SboPayloadBinders2::Wrap138c560(void** src, SboPayloadBinders2PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b00bd8;
        buf->payload = *src;
        buf->table = Table_1b00bf8;
        result.instance = buf;
        result.cleanup = Cleanup_1398740;
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
    SboPayloadBinders2PayloadBox* heap = static_cast<SboPayloadBinders2PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b00bd8;
    heap->payload = *src;
    heap->table = Table_1b00bf8;
    result.cleanup = Cleanup_138bc50;
    return result;
}

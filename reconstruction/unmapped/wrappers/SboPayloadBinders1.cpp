// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// SboPayloadBinders1, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
// CI hash: 0x1258710 ?Wrap1258710@SboPayloadBinders1@@SA?AUSboPayloadBinders1SboBinding@@PEAPEAXPEAUSboPayloadBinders1PayloadBox@@_K@Z
// CI hash: 0x127f5b0 ?Wrap127f5b0@SboPayloadBinders1@@SA?AUSboPayloadBinders1SboBinding@@PEAPEAXPEAUSboPayloadBinders1PayloadBox@@_K@Z
// CI hash: 0x12937e0 ?Wrap12937e0@SboPayloadBinders1@@SA?AUSboPayloadBinders1SboBinding@@PEAPEAXPEAUSboPayloadBinders1PayloadBox@@_K@Z
// CI hash: 0x12938e0 ?Wrap12938e0@SboPayloadBinders1@@SA?AUSboPayloadBinders1SboBinding@@PEAPEAXPEAUSboPayloadBinders1PayloadBox@@_K@Z
// CI hash: 0x1299290 ?Wrap1299290@SboPayloadBinders1@@SA?AUSboPayloadBinders1SboBinding@@PEAPEAXPEAUSboPayloadBinders1PayloadBox@@_K@Z
// CI hash: 0x129d6d0 ?Wrap129d6d0@SboPayloadBinders1@@SA?AUSboPayloadBinders1SboBinding@@PEAPEAXPEAUSboPayloadBinders1PayloadBox@@_K@Z
// CI hash: 0x129d890 ?Wrap129d890@SboPayloadBinders1@@SA?AUSboPayloadBinders1SboBinding@@PEAPEAXPEAUSboPayloadBinders1PayloadBox@@_K@Z
// CI hash: 0x12a9420 ?Wrap12a9420@SboPayloadBinders1@@SA?AUSboPayloadBinders1SboBinding@@PEAPEAXPEAUSboPayloadBinders1PayloadBox@@_K@Z
// CI hash: 0x12a96a0 ?Wrap12a96a0@SboPayloadBinders1@@SA?AUSboPayloadBinders1SboBinding@@PEAPEAXPEAUSboPayloadBinders1PayloadBox@@_K@Z
// CI hash: 0x12a97a0 ?Wrap12a97a0@SboPayloadBinders1@@SA?AUSboPayloadBinders1SboBinding@@PEAPEAXPEAUSboPayloadBinders1PayloadBox@@_K@Z
// CI hash: 0x12a9960 ?Wrap12a9960@SboPayloadBinders1@@SA?AUSboPayloadBinders1SboBinding@@PEAPEAXPEAUSboPayloadBinders1PayloadBox@@_K@Z
// CI hash: 0x12a9a60 ?Wrap12a9a60@SboPayloadBinders1@@SA?AUSboPayloadBinders1SboBinding@@PEAPEAXPEAUSboPayloadBinders1PayloadBox@@_K@Z
// CI hash: 0x12a9d10 ?Wrap12a9d10@SboPayloadBinders1@@SA?AUSboPayloadBinders1SboBinding@@PEAPEAXPEAUSboPayloadBinders1PayloadBox@@_K@Z
// CI hash: 0x12a9e10 ?Wrap12a9e10@SboPayloadBinders1@@SA?AUSboPayloadBinders1SboBinding@@PEAPEAXPEAUSboPayloadBinders1PayloadBox@@_K@Z
// CI hash: 0x12a9f10 ?Wrap12a9f10@SboPayloadBinders1@@SA?AUSboPayloadBinders1SboBinding@@PEAPEAXPEAUSboPayloadBinders1PayloadBox@@_K@Z
// CI hash: 0x12aa010 ?Wrap12aa010@SboPayloadBinders1@@SA?AUSboPayloadBinders1SboBinding@@PEAPEAXPEAUSboPayloadBinders1PayloadBox@@_K@Z
// CI hash: 0x12b8be0 ?Wrap12b8be0@SboPayloadBinders1@@SA?AUSboPayloadBinders1SboBinding@@PEAPEAXPEAUSboPayloadBinders1PayloadBox@@_K@Z
// CI hash: 0x12c1cc0 ?Wrap12c1cc0@SboPayloadBinders1@@SA?AUSboPayloadBinders1SboBinding@@PEAPEAXPEAUSboPayloadBinders1PayloadBox@@_K@Z
// CI hash: 0x12c71e0 ?Wrap12c71e0@SboPayloadBinders1@@SA?AUSboPayloadBinders1SboBinding@@PEAPEAXPEAUSboPayloadBinders1PayloadBox@@_K@Z
// CI hash: 0x12c7a60 ?Wrap12c7a60@SboPayloadBinders1@@SA?AUSboPayloadBinders1SboBinding@@PEAPEAXPEAUSboPayloadBinders1PayloadBox@@_K@Z
// 0x1258710 SboPayloadBinders1::Wrap1258710
// 0x127f5b0 SboPayloadBinders1::Wrap127f5b0
// 0x12937e0 SboPayloadBinders1::Wrap12937e0
// 0x12938e0 SboPayloadBinders1::Wrap12938e0
// 0x1299290 SboPayloadBinders1::Wrap1299290
// 0x129d6d0 SboPayloadBinders1::Wrap129d6d0
// 0x129d890 SboPayloadBinders1::Wrap129d890
// 0x12a9420 SboPayloadBinders1::Wrap12a9420
// 0x12a96a0 SboPayloadBinders1::Wrap12a96a0
// 0x12a97a0 SboPayloadBinders1::Wrap12a97a0
// 0x12a9960 SboPayloadBinders1::Wrap12a9960
// 0x12a9a60 SboPayloadBinders1::Wrap12a9a60
// 0x12a9d10 SboPayloadBinders1::Wrap12a9d10
// 0x12a9e10 SboPayloadBinders1::Wrap12a9e10
// 0x12a9f10 SboPayloadBinders1::Wrap12a9f10
// 0x12aa010 SboPayloadBinders1::Wrap12aa010
// 0x12b8be0 SboPayloadBinders1::Wrap12b8be0
// 0x12c1cc0 SboPayloadBinders1::Wrap12c1cc0
// 0x12c71e0 SboPayloadBinders1::Wrap12c71e0
// 0x12c7a60 SboPayloadBinders1::Wrap12c7a60
#include "SboPayloadBinders1.h"

SboPayloadBinders1SboBinding SboPayloadBinders1::Wrap1258710(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1acd660;
        buf->payload = *src;
        buf->table = Table_1acd688;
        result.instance = buf;
        result.cleanup = Cleanup_125a820;
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
    SboPayloadBinders1PayloadBox* heap = static_cast<SboPayloadBinders1PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1acd660;
    heap->payload = *src;
    heap->table = Table_1acd688;
    result.cleanup = Cleanup_12585b0;
    return result;
}

SboPayloadBinders1SboBinding SboPayloadBinders1::Wrap127f5b0(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ad1b20;
        buf->payload = *src;
        buf->table = Table_1ad1b48;
        result.instance = buf;
        result.cleanup = Cleanup_1284e40;
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
    SboPayloadBinders1PayloadBox* heap = static_cast<SboPayloadBinders1PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ad1b20;
    heap->payload = *src;
    heap->table = Table_1ad1b48;
    result.cleanup = Cleanup_127f2c0;
    return result;
}

SboPayloadBinders1SboBinding SboPayloadBinders1::Wrap12937e0(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ad3f40;
        buf->payload = *src;
        buf->table = Table_1ad3f68;
        result.instance = buf;
        result.cleanup = Cleanup_1295f60;
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
    SboPayloadBinders1PayloadBox* heap = static_cast<SboPayloadBinders1PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ad3f40;
    heap->payload = *src;
    heap->table = Table_1ad3f68;
    result.cleanup = Cleanup_1293760;
    return result;
}

SboPayloadBinders1SboBinding SboPayloadBinders1::Wrap12938e0(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ad3f90;
        buf->payload = *src;
        buf->table = Table_1ad3fb8;
        result.instance = buf;
        result.cleanup = Cleanup_1295f70;
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
    SboPayloadBinders1PayloadBox* heap = static_cast<SboPayloadBinders1PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ad3f90;
    heap->payload = *src;
    heap->table = Table_1ad3fb8;
    result.cleanup = Cleanup_12937a0;
    return result;
}

SboPayloadBinders1SboBinding SboPayloadBinders1::Wrap1299290(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ad4a10;
        buf->payload = *src;
        buf->table = Table_1ad4a38;
        result.instance = buf;
        result.cleanup = Cleanup_129b300;
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
    SboPayloadBinders1PayloadBox* heap = static_cast<SboPayloadBinders1PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ad4a10;
    heap->payload = *src;
    heap->table = Table_1ad4a38;
    result.cleanup = Cleanup_1299150;
    return result;
}

SboPayloadBinders1SboBinding SboPayloadBinders1::Wrap129d6d0(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ad57c0;
        buf->payload = *src;
        buf->table = Table_1ad57e8;
        result.instance = buf;
        result.cleanup = Cleanup_129f250;
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
    SboPayloadBinders1PayloadBox* heap = static_cast<SboPayloadBinders1PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ad57c0;
    heap->payload = *src;
    heap->table = Table_1ad57e8;
    result.cleanup = Cleanup_129d610;
    return result;
}

SboPayloadBinders1SboBinding SboPayloadBinders1::Wrap129d890(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ad5810;
        buf->payload = *src;
        buf->table = Table_1ad5838;
        result.instance = buf;
        result.cleanup = Cleanup_129f270;
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
    SboPayloadBinders1PayloadBox* heap = static_cast<SboPayloadBinders1PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ad5810;
    heap->payload = *src;
    heap->table = Table_1ad5838;
    result.cleanup = Cleanup_129d690;
    return result;
}

SboPayloadBinders1SboBinding SboPayloadBinders1::Wrap12a9420(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ad8a68;
        buf->payload = *src;
        buf->table = Table_1ad8a90;
        result.instance = buf;
        result.cleanup = Cleanup_12b1110;
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
    SboPayloadBinders1PayloadBox* heap = static_cast<SboPayloadBinders1PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ad8a68;
    heap->payload = *src;
    heap->table = Table_1ad8a90;
    result.cleanup = Cleanup_12a90a0;
    return result;
}

SboPayloadBinders1SboBinding SboPayloadBinders1::Wrap12a96a0(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ad8888;
        buf->payload = *src;
        buf->table = Table_1ad88b0;
        result.instance = buf;
        result.cleanup = Cleanup_12b1140;
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
    SboPayloadBinders1PayloadBox* heap = static_cast<SboPayloadBinders1PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ad8888;
    heap->payload = *src;
    heap->table = Table_1ad88b0;
    result.cleanup = Cleanup_12a9160;
    return result;
}

SboPayloadBinders1SboBinding SboPayloadBinders1::Wrap12a97a0(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ad8ba8;
        buf->payload = *src;
        buf->table = Table_1ad8bd0;
        result.instance = buf;
        result.cleanup = Cleanup_12b1150;
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
    SboPayloadBinders1PayloadBox* heap = static_cast<SboPayloadBinders1PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ad8ba8;
    heap->payload = *src;
    heap->table = Table_1ad8bd0;
    result.cleanup = Cleanup_12a91a0;
    return result;
}

SboPayloadBinders1SboBinding SboPayloadBinders1::Wrap12a9960(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ad87e8;
        buf->payload = *src;
        buf->table = Table_1ad8810;
        result.instance = buf;
        result.cleanup = Cleanup_12b1170;
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
    SboPayloadBinders1PayloadBox* heap = static_cast<SboPayloadBinders1PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ad87e8;
    heap->payload = *src;
    heap->table = Table_1ad8810;
    result.cleanup = Cleanup_12a9220;
    return result;
}

SboPayloadBinders1SboBinding SboPayloadBinders1::Wrap12a9a60(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ad8838;
        buf->payload = *src;
        buf->table = Table_1ad8860;
        result.instance = buf;
        result.cleanup = Cleanup_12b1180;
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
    SboPayloadBinders1PayloadBox* heap = static_cast<SboPayloadBinders1PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ad8838;
    heap->payload = *src;
    heap->table = Table_1ad8860;
    result.cleanup = Cleanup_12a9260;
    return result;
}

SboPayloadBinders1SboBinding SboPayloadBinders1::Wrap12a9d10(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ad88d8;
        buf->payload = *src;
        buf->table = Table_1ad8900;
        result.instance = buf;
        result.cleanup = Cleanup_12b11b0;
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
    SboPayloadBinders1PayloadBox* heap = static_cast<SboPayloadBinders1PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ad88d8;
    heap->payload = *src;
    heap->table = Table_1ad8900;
    result.cleanup = Cleanup_12a9320;
    return result;
}

SboPayloadBinders1SboBinding SboPayloadBinders1::Wrap12a9e10(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ad8928;
        buf->payload = *src;
        buf->table = Table_1ad8950;
        result.instance = buf;
        result.cleanup = Cleanup_12b11c0;
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
    SboPayloadBinders1PayloadBox* heap = static_cast<SboPayloadBinders1PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ad8928;
    heap->payload = *src;
    heap->table = Table_1ad8950;
    result.cleanup = Cleanup_12a9360;
    return result;
}

SboPayloadBinders1SboBinding SboPayloadBinders1::Wrap12a9f10(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ad8ab8;
        buf->payload = *src;
        buf->table = Table_1ad8ae0;
        result.instance = buf;
        result.cleanup = Cleanup_12b11d0;
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
    SboPayloadBinders1PayloadBox* heap = static_cast<SboPayloadBinders1PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ad8ab8;
    heap->payload = *src;
    heap->table = Table_1ad8ae0;
    result.cleanup = Cleanup_12a93a0;
    return result;
}

SboPayloadBinders1SboBinding SboPayloadBinders1::Wrap12aa010(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ad89c8;
        buf->payload = *src;
        buf->table = Table_1ad89f0;
        result.instance = buf;
        result.cleanup = Cleanup_12b11e0;
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
    SboPayloadBinders1PayloadBox* heap = static_cast<SboPayloadBinders1PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ad89c8;
    heap->payload = *src;
    heap->table = Table_1ad89f0;
    result.cleanup = Cleanup_12a93e0;
    return result;
}

SboPayloadBinders1SboBinding SboPayloadBinders1::Wrap12b8be0(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1add198;
        buf->payload = *src;
        buf->table = Table_1add1c0;
        result.instance = buf;
        result.cleanup = Cleanup_12b9100;
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
    SboPayloadBinders1PayloadBox* heap = static_cast<SboPayloadBinders1PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1add198;
    heap->payload = *src;
    heap->table = Table_1add1c0;
    result.cleanup = Cleanup_12b8ba0;
    return result;
}

SboPayloadBinders1SboBinding SboPayloadBinders1::Wrap12c1cc0(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1adec88;
        buf->payload = *src;
        buf->table = Table_1adecb0;
        result.instance = buf;
        result.cleanup = Cleanup_12c2570;
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
    SboPayloadBinders1PayloadBox* heap = static_cast<SboPayloadBinders1PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1adec88;
    heap->payload = *src;
    heap->table = Table_1adecb0;
    result.cleanup = Cleanup_12c1c80;
    return result;
}

SboPayloadBinders1SboBinding SboPayloadBinders1::Wrap12c71e0(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ae04a8;
        buf->payload = *src;
        buf->table = Table_1ae04d0;
        result.instance = buf;
        result.cleanup = Cleanup_12cbaf0;
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
    SboPayloadBinders1PayloadBox* heap = static_cast<SboPayloadBinders1PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ae04a8;
    heap->payload = *src;
    heap->table = Table_1ae04d0;
    result.cleanup = Cleanup_12c6d60;
    return result;
}

SboPayloadBinders1SboBinding SboPayloadBinders1::Wrap12c7a60(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ae04f8;
        buf->payload = *src;
        buf->table = Table_1ae0520;
        result.instance = buf;
        result.cleanup = Cleanup_12cbba0;
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
    SboPayloadBinders1PayloadBox* heap = static_cast<SboPayloadBinders1PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ae04f8;
    heap->payload = *src;
    heap->table = Table_1ae0520;
    result.cleanup = Cleanup_12c7020;
    return result;
}

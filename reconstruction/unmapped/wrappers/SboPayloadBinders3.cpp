// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// SboPayloadBinders3, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
// CI hash: 0x138c660 ?Wrap138c660@SboPayloadBinders3@@SA?AUSboPayloadBinders3SboBinding@@PEAPEAXPEAUSboPayloadBinders3PayloadBox@@_K@Z
// CI hash: 0x138c760 ?Wrap138c760@SboPayloadBinders3@@SA?AUSboPayloadBinders3SboBinding@@PEAPEAXPEAUSboPayloadBinders3PayloadBox@@_K@Z
// CI hash: 0x138c990 ?Wrap138c990@SboPayloadBinders3@@SA?AUSboPayloadBinders3SboBinding@@PEAPEAXPEAUSboPayloadBinders3PayloadBox@@_K@Z
// CI hash: 0x13a4230 ?Wrap13a4230@SboPayloadBinders3@@SA?AUSboPayloadBinders3SboBinding@@PEAPEAXPEAUSboPayloadBinders3PayloadBox@@_K@Z
// CI hash: 0x13a4330 ?Wrap13a4330@SboPayloadBinders3@@SA?AUSboPayloadBinders3SboBinding@@PEAPEAXPEAUSboPayloadBinders3PayloadBox@@_K@Z
// CI hash: 0x13a4430 ?Wrap13a4430@SboPayloadBinders3@@SA?AUSboPayloadBinders3SboBinding@@PEAPEAXPEAUSboPayloadBinders3PayloadBox@@_K@Z
// CI hash: 0x13a6ed0 ?Wrap13a6ed0@SboPayloadBinders3@@SA?AUSboPayloadBinders3SboBinding@@PEAPEAXPEAUSboPayloadBinders3PayloadBox@@_K@Z
// CI hash: 0x13a7190 ?Wrap13a7190@SboPayloadBinders3@@SA?AUSboPayloadBinders3SboBinding@@PEAPEAXPEAUSboPayloadBinders3PayloadBox@@_K@Z
// CI hash: 0x13a7290 ?Wrap13a7290@SboPayloadBinders3@@SA?AUSboPayloadBinders3SboBinding@@PEAPEAXPEAUSboPayloadBinders3PayloadBox@@_K@Z
// CI hash: 0x13a7390 ?Wrap13a7390@SboPayloadBinders3@@SA?AUSboPayloadBinders3SboBinding@@PEAPEAXPEAUSboPayloadBinders3PayloadBox@@_K@Z
// CI hash: 0x13a7490 ?Wrap13a7490@SboPayloadBinders3@@SA?AUSboPayloadBinders3SboBinding@@PEAPEAXPEAUSboPayloadBinders3PayloadBox@@_K@Z
// CI hash: 0x13aee40 ?Wrap13aee40@SboPayloadBinders3@@SA?AUSboPayloadBinders3SboBinding@@PEAPEAXPEAUSboPayloadBinders3PayloadBox@@_K@Z
// CI hash: 0x13af930 ?Wrap13af930@SboPayloadBinders3@@SA?AUSboPayloadBinders3SboBinding@@PEAPEAXPEAUSboPayloadBinders3PayloadBox@@_K@Z
// CI hash: 0x13b0320 ?Wrap13b0320@SboPayloadBinders3@@SA?AUSboPayloadBinders3SboBinding@@PEAPEAXPEAUSboPayloadBinders3PayloadBox@@_K@Z
// CI hash: 0x13b0fe0 ?Wrap13b0fe0@SboPayloadBinders3@@SA?AUSboPayloadBinders3SboBinding@@PEAPEAXPEAUSboPayloadBinders3PayloadBox@@_K@Z
// CI hash: 0x13b19e0 ?Wrap13b19e0@SboPayloadBinders3@@SA?AUSboPayloadBinders3SboBinding@@PEAPEAXPEAUSboPayloadBinders3PayloadBox@@_K@Z
// CI hash: 0x13b23f0 ?Wrap13b23f0@SboPayloadBinders3@@SA?AUSboPayloadBinders3SboBinding@@PEAPEAXPEAUSboPayloadBinders3PayloadBox@@_K@Z
// CI hash: 0x13b31a0 ?Wrap13b31a0@SboPayloadBinders3@@SA?AUSboPayloadBinders3SboBinding@@PEAPEAXPEAUSboPayloadBinders3PayloadBox@@_K@Z
// CI hash: 0x13b4f00 ?Wrap13b4f00@SboPayloadBinders3@@SA?AUSboPayloadBinders3SboBinding@@PEAPEAXPEAUSboPayloadBinders3PayloadBox@@_K@Z
// CI hash: 0x13b5000 ?Wrap13b5000@SboPayloadBinders3@@SA?AUSboPayloadBinders3SboBinding@@PEAPEAXPEAUSboPayloadBinders3PayloadBox@@_K@Z
// 0x138c660 SboPayloadBinders3::Wrap138c660
// 0x138c760 SboPayloadBinders3::Wrap138c760
// 0x138c990 SboPayloadBinders3::Wrap138c990
// 0x13a4230 SboPayloadBinders3::Wrap13a4230
// 0x13a4330 SboPayloadBinders3::Wrap13a4330
// 0x13a4430 SboPayloadBinders3::Wrap13a4430
// 0x13a6ed0 SboPayloadBinders3::Wrap13a6ed0
// 0x13a7190 SboPayloadBinders3::Wrap13a7190
// 0x13a7290 SboPayloadBinders3::Wrap13a7290
// 0x13a7390 SboPayloadBinders3::Wrap13a7390
// 0x13a7490 SboPayloadBinders3::Wrap13a7490
// 0x13aee40 SboPayloadBinders3::Wrap13aee40
// 0x13af930 SboPayloadBinders3::Wrap13af930
// 0x13b0320 SboPayloadBinders3::Wrap13b0320
// 0x13b0fe0 SboPayloadBinders3::Wrap13b0fe0
// 0x13b19e0 SboPayloadBinders3::Wrap13b19e0
// 0x13b23f0 SboPayloadBinders3::Wrap13b23f0
// 0x13b31a0 SboPayloadBinders3::Wrap13b31a0
// 0x13b4f00 SboPayloadBinders3::Wrap13b4f00
// 0x13b5000 SboPayloadBinders3::Wrap13b5000
#include "SboPayloadBinders3.h"

SboPayloadBinders3SboBinding SboPayloadBinders3::Wrap138c660(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders3SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b00b18;
        buf->payload = *src;
        buf->table = Table_1b00b38;
        result.instance = buf;
        result.cleanup = Cleanup_1398750;
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
    SboPayloadBinders3PayloadBox* heap = static_cast<SboPayloadBinders3PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b00b18;
    heap->payload = *src;
    heap->table = Table_1b00b38;
    result.cleanup = Cleanup_138bc90;
    return result;
}

SboPayloadBinders3SboBinding SboPayloadBinders3::Wrap138c760(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders3SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b00b58;
        buf->payload = *src;
        buf->table = Table_1b00b78;
        result.instance = buf;
        result.cleanup = Cleanup_1398760;
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
    SboPayloadBinders3PayloadBox* heap = static_cast<SboPayloadBinders3PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b00b58;
    heap->payload = *src;
    heap->table = Table_1b00b78;
    result.cleanup = Cleanup_138bcd0;
    return result;
}

SboPayloadBinders3SboBinding SboPayloadBinders3::Wrap138c990(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders3SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b00b98;
        buf->payload = *src;
        buf->table = Table_1b00bb8;
        result.instance = buf;
        result.cleanup = Cleanup_1398780;
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
    SboPayloadBinders3PayloadBox* heap = static_cast<SboPayloadBinders3PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b00b98;
    heap->payload = *src;
    heap->table = Table_1b00bb8;
    result.cleanup = Cleanup_138bd50;
    return result;
}

SboPayloadBinders3SboBinding SboPayloadBinders3::Wrap13a4230(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders3SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b02638;
        buf->payload = *src;
        buf->table = Table_1b02658;
        result.instance = buf;
        result.cleanup = Cleanup_13a5bf0;
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
    SboPayloadBinders3PayloadBox* heap = static_cast<SboPayloadBinders3PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b02638;
    heap->payload = *src;
    heap->table = Table_1b02658;
    result.cleanup = Cleanup_13a4130;
    return result;
}

SboPayloadBinders3SboBinding SboPayloadBinders3::Wrap13a4330(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders3SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b026b8;
        buf->payload = *src;
        buf->table = Table_1b026d8;
        result.instance = buf;
        result.cleanup = Cleanup_13a5c00;
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
    SboPayloadBinders3PayloadBox* heap = static_cast<SboPayloadBinders3PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b026b8;
    heap->payload = *src;
    heap->table = Table_1b026d8;
    result.cleanup = Cleanup_13a4170;
    return result;
}

SboPayloadBinders3SboBinding SboPayloadBinders3::Wrap13a4430(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders3SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b02678;
        buf->payload = *src;
        buf->table = Table_1b02698;
        result.instance = buf;
        result.cleanup = Cleanup_13a5c10;
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
    SboPayloadBinders3PayloadBox* heap = static_cast<SboPayloadBinders3PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b02678;
    heap->payload = *src;
    heap->table = Table_1b02698;
    result.cleanup = Cleanup_13a41b0;
    return result;
}

SboPayloadBinders3SboBinding SboPayloadBinders3::Wrap13a6ed0(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders3SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b03650;
        buf->payload = *src;
        buf->table = Table_1b03670;
        result.instance = buf;
        result.cleanup = Cleanup_13abe80;
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
    SboPayloadBinders3PayloadBox* heap = static_cast<SboPayloadBinders3PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b03650;
    heap->payload = *src;
    heap->table = Table_1b03670;
    result.cleanup = Cleanup_13a6b90;
    return result;
}

SboPayloadBinders3SboBinding SboPayloadBinders3::Wrap13a7190(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders3SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b03690;
        buf->payload = *src;
        buf->table = Table_1b036b0;
        result.instance = buf;
        result.cleanup = Cleanup_13abeb0;
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
    SboPayloadBinders3PayloadBox* heap = static_cast<SboPayloadBinders3PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b03690;
    heap->payload = *src;
    heap->table = Table_1b036b0;
    result.cleanup = Cleanup_13a6c50;
    return result;
}

SboPayloadBinders3SboBinding SboPayloadBinders3::Wrap13a7290(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders3SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b036d0;
        buf->payload = *src;
        buf->table = Table_1b036f0;
        result.instance = buf;
        result.cleanup = Cleanup_13abec0;
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
    SboPayloadBinders3PayloadBox* heap = static_cast<SboPayloadBinders3PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b036d0;
    heap->payload = *src;
    heap->table = Table_1b036f0;
    result.cleanup = Cleanup_13a6c90;
    return result;
}

SboPayloadBinders3SboBinding SboPayloadBinders3::Wrap13a7390(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders3SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b03528;
        buf->payload = *src;
        buf->table = Table_1b03548;
        result.instance = buf;
        result.cleanup = Cleanup_13abed0;
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
    SboPayloadBinders3PayloadBox* heap = static_cast<SboPayloadBinders3PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b03528;
    heap->payload = *src;
    heap->table = Table_1b03548;
    result.cleanup = Cleanup_13a6cd0;
    return result;
}

SboPayloadBinders3SboBinding SboPayloadBinders3::Wrap13a7490(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders3SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b035d0;
        buf->payload = *src;
        buf->table = Table_1b035f0;
        result.instance = buf;
        result.cleanup = Cleanup_13abee0;
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
    SboPayloadBinders3PayloadBox* heap = static_cast<SboPayloadBinders3PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b035d0;
    heap->payload = *src;
    heap->table = Table_1b035f0;
    result.cleanup = Cleanup_13a6d10;
    return result;
}

SboPayloadBinders3SboBinding SboPayloadBinders3::Wrap13aee40(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders3SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b04310;
        buf->payload = *src;
        buf->table = Table_1b04330;
        result.instance = buf;
        result.cleanup = Cleanup_13af5c0;
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
    SboPayloadBinders3PayloadBox* heap = static_cast<SboPayloadBinders3PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b04310;
    heap->payload = *src;
    heap->table = Table_1b04330;
    result.cleanup = Cleanup_13aedc0;
    return result;
}

SboPayloadBinders3SboBinding SboPayloadBinders3::Wrap13af930(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders3SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b044a0;
        buf->payload = *src;
        buf->table = Table_1b044c0;
        result.instance = buf;
        result.cleanup = Cleanup_13b0010;
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
    SboPayloadBinders3PayloadBox* heap = static_cast<SboPayloadBinders3PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b044a0;
    heap->payload = *src;
    heap->table = Table_1b044c0;
    result.cleanup = Cleanup_13af8b0;
    return result;
}

SboPayloadBinders3SboBinding SboPayloadBinders3::Wrap13b0320(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders3SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b047f8;
        buf->payload = *src;
        buf->table = Table_1b04818;
        result.instance = buf;
        result.cleanup = Cleanup_13b0c60;
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
    SboPayloadBinders3PayloadBox* heap = static_cast<SboPayloadBinders3PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b047f8;
    heap->payload = *src;
    heap->table = Table_1b04818;
    result.cleanup = Cleanup_13b0260;
    return result;
}

SboPayloadBinders3SboBinding SboPayloadBinders3::Wrap13b0fe0(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders3SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b04a00;
        buf->payload = *src;
        buf->table = Table_1b04a20;
        result.instance = buf;
        result.cleanup = Cleanup_13b16e0;
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
    SboPayloadBinders3PayloadBox* heap = static_cast<SboPayloadBinders3PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b04a00;
    heap->payload = *src;
    heap->table = Table_1b04a20;
    result.cleanup = Cleanup_13b0f20;
    return result;
}

SboPayloadBinders3SboBinding SboPayloadBinders3::Wrap13b19e0(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders3SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b04c08;
        buf->payload = *src;
        buf->table = Table_1b04c28;
        result.instance = buf;
        result.cleanup = Cleanup_13b2110;
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
    SboPayloadBinders3PayloadBox* heap = static_cast<SboPayloadBinders3PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b04c08;
    heap->payload = *src;
    heap->table = Table_1b04c28;
    result.cleanup = Cleanup_13b1920;
    return result;
}

SboPayloadBinders3SboBinding SboPayloadBinders3::Wrap13b23f0(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders3SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b04e10;
        buf->payload = *src;
        buf->table = Table_1b04e30;
        result.instance = buf;
        result.cleanup = Cleanup_13b2af0;
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
    SboPayloadBinders3PayloadBox* heap = static_cast<SboPayloadBinders3PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b04e10;
    heap->payload = *src;
    heap->table = Table_1b04e30;
    result.cleanup = Cleanup_13b2330;
    return result;
}

SboPayloadBinders3SboBinding SboPayloadBinders3::Wrap13b31a0(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders3SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b053e0;
        buf->payload = *src;
        buf->table = Table_1b05400;
        result.instance = buf;
        result.cleanup = Cleanup_13b46a0;
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
    SboPayloadBinders3PayloadBox* heap = static_cast<SboPayloadBinders3PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b053e0;
    heap->payload = *src;
    heap->table = Table_1b05400;
    result.cleanup = Cleanup_13b2f20;
    return result;
}

SboPayloadBinders3SboBinding SboPayloadBinders3::Wrap13b4f00(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders3SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b05678;
        buf->payload = *src;
        buf->table = Table_1b05698;
        result.instance = buf;
        result.cleanup = Cleanup_13b5dd0;
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
    SboPayloadBinders3PayloadBox* heap = static_cast<SboPayloadBinders3PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b05678;
    heap->payload = *src;
    heap->table = Table_1b05698;
    result.cleanup = Cleanup_13b4e80;
    return result;
}

SboPayloadBinders3SboBinding SboPayloadBinders3::Wrap13b5000(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders3SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b05638;
        buf->payload = *src;
        buf->table = Table_1b05658;
        result.instance = buf;
        result.cleanup = Cleanup_13b5de0;
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
    SboPayloadBinders3PayloadBox* heap = static_cast<SboPayloadBinders3PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b05638;
    heap->payload = *src;
    heap->table = Table_1b05658;
    result.cleanup = Cleanup_13b4ec0;
    return result;
}

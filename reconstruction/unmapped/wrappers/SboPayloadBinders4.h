// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// SboPayloadBinders4, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

// Only the callback address is stored here. Its call signature is unknown.
using SboPayloadBinders4CleanupFunction = void();

struct SboPayloadBinders4SboBinding
{
    void* instance;
    SboPayloadBinders4CleanupFunction* cleanup;
};

struct SboPayloadBinders4PayloadBox
{
    void* table;
    void* payload;
};

extern "C" void* (*gAllocFn_3356368)(unsigned long long size);
extern "C" unsigned int gLogChannel_20d5024;
extern "C" bool LogFilter_128c360(unsigned int channel, int level);
extern "C" bool LogConsoleEn_128c380();
extern "C" int LogVerbosity_128c340(unsigned int channel);
extern "C" bool LogSinkEn_128c1a0(int level, unsigned int channel);
extern "C" void LogConsole_12586a0(int level, const char* fmt, ...);
extern "C" void LogSink_12586e0(int level, const char* fmt, ...);
extern "C" unsigned char Table_1b058d0[];
extern "C" unsigned char Table_1b058f0[];
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13b6db0;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13b61a0;
extern "C" const char Text_1acd8d0[];
extern "C" unsigned char Table_1b05ad8[];
extern "C" unsigned char Table_1b05af8[];
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13b7860;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13b7010;
extern "C" unsigned char Table_1b08c78[];
extern "C" unsigned char Table_1b08c98[];
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13c6760;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13c5ea0;
extern "C" unsigned char Table_1b08e80[];
extern "C" unsigned char Table_1b08ea0[];
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13c7360;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13c6a10;
extern "C" unsigned char Table_1b09088[];
extern "C" unsigned char Table_1b090a8[];
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13c7f60;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13c7610;
extern "C" unsigned char Table_1b09290[];
extern "C" unsigned char Table_1b092b0[];
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13c8a10;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13c81c0;
extern "C" unsigned char Table_1b09498[];
extern "C" unsigned char Table_1b094b8[];
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13c94a0;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13c8c60;
extern "C" unsigned char Table_1b096a0[];
extern "C" unsigned char Table_1b096c0[];
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13ca060;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13c9750;
extern "C" unsigned char Table_1b098a8[];
extern "C" unsigned char Table_1b098c8[];
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13caa40;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13ca280;
extern "C" unsigned char Table_1b09a38[];
extern "C" unsigned char Table_1b09a58[];
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13cb310;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13cac10;
extern "C" unsigned char Table_1b13460[];
extern "C" unsigned char Table_1b13480[];
extern "C" SboPayloadBinders4CleanupFunction Cleanup_14224a0;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_1421bb0;
extern "C" unsigned char Table_1b136e0[];
extern "C" unsigned char Table_1b13700[];
extern "C" SboPayloadBinders4CleanupFunction Cleanup_1423ea0;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_14233d0;
extern "C" unsigned char Table_1b15e20[];
extern "C" unsigned char Table_1b15e40[];
extern "C" SboPayloadBinders4CleanupFunction Cleanup_14348f0;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_14311d0;
extern "C" unsigned char Table_1b15de0[];
extern "C" unsigned char Table_1b15e00[];
extern "C" SboPayloadBinders4CleanupFunction Cleanup_1434900;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_1431210;
extern "C" unsigned char Table_1b15d60[];
extern "C" unsigned char Table_1b15d80[];
extern "C" SboPayloadBinders4CleanupFunction Cleanup_1434910;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_1431250;
extern "C" unsigned char Table_1b15ce0[];
extern "C" unsigned char Table_1b15d00[];
extern "C" SboPayloadBinders4CleanupFunction Cleanup_1434920;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_1431290;
extern "C" unsigned char Table_1b15da0[];
extern "C" unsigned char Table_1b15dc0[];
extern "C" SboPayloadBinders4CleanupFunction Cleanup_1434930;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_14312d0;
extern "C" unsigned char Table_1b1d940[];
extern "C" unsigned char Table_1b1d960[];
extern "C" SboPayloadBinders4CleanupFunction Cleanup_146b6b0;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_145cc30;
extern "C" unsigned char Table_1b1d9c0[];
extern "C" unsigned char Table_1b1d9e0[];
extern "C" SboPayloadBinders4CleanupFunction Cleanup_146b6c0;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_145cc70;
extern "C" unsigned char Table_1b1dac8[];
extern "C" unsigned char Table_1b1dae8[];
extern "C" SboPayloadBinders4CleanupFunction Cleanup_146b6d0;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_145ccb0;

struct SboPayloadBinders4
{
    static SboPayloadBinders4SboBinding Wrap13b6220(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders4SboBinding Wrap13b70d0(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders4SboBinding Wrap13c5f60(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders4SboBinding Wrap13c6ad0(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders4SboBinding Wrap13c76d0(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders4SboBinding Wrap13c8280(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders4SboBinding Wrap13c8d20(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders4SboBinding Wrap13c9810(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders4SboBinding Wrap13ca340(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders4SboBinding Wrap13cac90(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders4SboBinding Wrap1421bf0(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders4SboBinding Wrap1423450(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders4SboBinding Wrap1431500(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders4SboBinding Wrap1431600(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders4SboBinding Wrap1431700(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders4SboBinding Wrap1431800(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders4SboBinding Wrap1431900(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders4SboBinding Wrap145d200(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders4SboBinding Wrap145d300(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders4SboBinding Wrap145d400(void** src, SboPayloadBinders4PayloadBox* buf, unsigned long long cap);
};

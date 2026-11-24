// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// SboPayloadBinders1, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

// Only the callback address is stored here. Its call signature is unknown.
using SboPayloadBinders1CleanupFunction = void();

struct SboPayloadBinders1SboBinding
{
    void* instance;
    SboPayloadBinders1CleanupFunction* cleanup;
};

struct SboPayloadBinders1PayloadBox
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
extern "C" unsigned char Table_1acd660[];
extern "C" unsigned char Table_1acd688[];
extern "C" SboPayloadBinders1CleanupFunction Cleanup_125a820;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12585b0;
extern "C" const char Text_1acd8d0[];
extern "C" unsigned char Table_1ad1b20[];
extern "C" unsigned char Table_1ad1b48[];
extern "C" SboPayloadBinders1CleanupFunction Cleanup_1284e40;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_127f2c0;
extern "C" unsigned char Table_1ad3f40[];
extern "C" unsigned char Table_1ad3f68[];
extern "C" SboPayloadBinders1CleanupFunction Cleanup_1295f60;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_1293760;
extern "C" unsigned char Table_1ad3f90[];
extern "C" unsigned char Table_1ad3fb8[];
extern "C" SboPayloadBinders1CleanupFunction Cleanup_1295f70;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12937a0;
extern "C" unsigned char Table_1ad4a10[];
extern "C" unsigned char Table_1ad4a38[];
extern "C" SboPayloadBinders1CleanupFunction Cleanup_129b300;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_1299150;
extern "C" unsigned char Table_1ad57c0[];
extern "C" unsigned char Table_1ad57e8[];
extern "C" SboPayloadBinders1CleanupFunction Cleanup_129f250;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_129d610;
extern "C" unsigned char Table_1ad5810[];
extern "C" unsigned char Table_1ad5838[];
extern "C" SboPayloadBinders1CleanupFunction Cleanup_129f270;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_129d690;
extern "C" unsigned char Table_1ad8a68[];
extern "C" unsigned char Table_1ad8a90[];
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12b1110;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12a90a0;
extern "C" unsigned char Table_1ad8888[];
extern "C" unsigned char Table_1ad88b0[];
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12b1140;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12a9160;
extern "C" unsigned char Table_1ad8ba8[];
extern "C" unsigned char Table_1ad8bd0[];
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12b1150;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12a91a0;
extern "C" unsigned char Table_1ad87e8[];
extern "C" unsigned char Table_1ad8810[];
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12b1170;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12a9220;
extern "C" unsigned char Table_1ad8838[];
extern "C" unsigned char Table_1ad8860[];
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12b1180;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12a9260;
extern "C" unsigned char Table_1ad88d8[];
extern "C" unsigned char Table_1ad8900[];
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12b11b0;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12a9320;
extern "C" unsigned char Table_1ad8928[];
extern "C" unsigned char Table_1ad8950[];
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12b11c0;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12a9360;
extern "C" unsigned char Table_1ad8ab8[];
extern "C" unsigned char Table_1ad8ae0[];
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12b11d0;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12a93a0;
extern "C" unsigned char Table_1ad89c8[];
extern "C" unsigned char Table_1ad89f0[];
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12b11e0;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12a93e0;
extern "C" unsigned char Table_1add198[];
extern "C" unsigned char Table_1add1c0[];
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12b9100;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12b8ba0;
extern "C" unsigned char Table_1adec88[];
extern "C" unsigned char Table_1adecb0[];
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12c2570;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12c1c80;
extern "C" unsigned char Table_1ae04a8[];
extern "C" unsigned char Table_1ae04d0[];
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12cbaf0;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12c6d60;
extern "C" unsigned char Table_1ae04f8[];
extern "C" unsigned char Table_1ae0520[];
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12cbba0;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12c7020;

struct SboPayloadBinders1
{
    static SboPayloadBinders1SboBinding Wrap1258710(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders1SboBinding Wrap127f5b0(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders1SboBinding Wrap12937e0(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders1SboBinding Wrap12938e0(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders1SboBinding Wrap1299290(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders1SboBinding Wrap129d6d0(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders1SboBinding Wrap129d890(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders1SboBinding Wrap12a9420(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders1SboBinding Wrap12a96a0(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders1SboBinding Wrap12a97a0(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders1SboBinding Wrap12a9960(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders1SboBinding Wrap12a9a60(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders1SboBinding Wrap12a9d10(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders1SboBinding Wrap12a9e10(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders1SboBinding Wrap12a9f10(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders1SboBinding Wrap12aa010(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders1SboBinding Wrap12b8be0(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders1SboBinding Wrap12c1cc0(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders1SboBinding Wrap12c71e0(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders1SboBinding Wrap12c7a60(void** src, SboPayloadBinders1PayloadBox* buf, unsigned long long cap);
};

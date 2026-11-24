// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// SboPayloadBinders3, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

// Only the callback address is stored here. Its call signature is unknown.
using SboPayloadBinders3CleanupFunction = void();

struct SboPayloadBinders3SboBinding
{
    void* instance;
    SboPayloadBinders3CleanupFunction* cleanup;
};

struct SboPayloadBinders3PayloadBox
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
extern "C" unsigned char Table_1b00b18[];
extern "C" unsigned char Table_1b00b38[];
extern "C" SboPayloadBinders3CleanupFunction Cleanup_1398750;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_138bc90;
extern "C" const char Text_1acd8d0[];
extern "C" unsigned char Table_1b00b58[];
extern "C" unsigned char Table_1b00b78[];
extern "C" SboPayloadBinders3CleanupFunction Cleanup_1398760;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_138bcd0;
extern "C" unsigned char Table_1b00b98[];
extern "C" unsigned char Table_1b00bb8[];
extern "C" SboPayloadBinders3CleanupFunction Cleanup_1398780;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_138bd50;
extern "C" unsigned char Table_1b02638[];
extern "C" unsigned char Table_1b02658[];
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13a5bf0;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13a4130;
extern "C" unsigned char Table_1b026b8[];
extern "C" unsigned char Table_1b026d8[];
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13a5c00;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13a4170;
extern "C" unsigned char Table_1b02678[];
extern "C" unsigned char Table_1b02698[];
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13a5c10;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13a41b0;
extern "C" unsigned char Table_1b03650[];
extern "C" unsigned char Table_1b03670[];
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13abe80;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13a6b90;
extern "C" unsigned char Table_1b03690[];
extern "C" unsigned char Table_1b036b0[];
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13abeb0;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13a6c50;
extern "C" unsigned char Table_1b036d0[];
extern "C" unsigned char Table_1b036f0[];
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13abec0;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13a6c90;
extern "C" unsigned char Table_1b03528[];
extern "C" unsigned char Table_1b03548[];
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13abed0;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13a6cd0;
extern "C" unsigned char Table_1b035d0[];
extern "C" unsigned char Table_1b035f0[];
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13abee0;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13a6d10;
extern "C" unsigned char Table_1b04310[];
extern "C" unsigned char Table_1b04330[];
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13af5c0;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13aedc0;
extern "C" unsigned char Table_1b044a0[];
extern "C" unsigned char Table_1b044c0[];
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13b0010;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13af8b0;
extern "C" unsigned char Table_1b047f8[];
extern "C" unsigned char Table_1b04818[];
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13b0c60;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13b0260;
extern "C" unsigned char Table_1b04a00[];
extern "C" unsigned char Table_1b04a20[];
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13b16e0;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13b0f20;
extern "C" unsigned char Table_1b04c08[];
extern "C" unsigned char Table_1b04c28[];
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13b2110;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13b1920;
extern "C" unsigned char Table_1b04e10[];
extern "C" unsigned char Table_1b04e30[];
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13b2af0;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13b2330;
extern "C" unsigned char Table_1b053e0[];
extern "C" unsigned char Table_1b05400[];
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13b46a0;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13b2f20;
extern "C" unsigned char Table_1b05678[];
extern "C" unsigned char Table_1b05698[];
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13b5dd0;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13b4e80;
extern "C" unsigned char Table_1b05638[];
extern "C" unsigned char Table_1b05658[];
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13b5de0;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13b4ec0;

struct SboPayloadBinders3
{
    static SboPayloadBinders3SboBinding Wrap138c660(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders3SboBinding Wrap138c760(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders3SboBinding Wrap138c990(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders3SboBinding Wrap13a4230(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders3SboBinding Wrap13a4330(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders3SboBinding Wrap13a4430(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders3SboBinding Wrap13a6ed0(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders3SboBinding Wrap13a7190(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders3SboBinding Wrap13a7290(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders3SboBinding Wrap13a7390(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders3SboBinding Wrap13a7490(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders3SboBinding Wrap13aee40(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders3SboBinding Wrap13af930(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders3SboBinding Wrap13b0320(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders3SboBinding Wrap13b0fe0(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders3SboBinding Wrap13b19e0(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders3SboBinding Wrap13b23f0(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders3SboBinding Wrap13b31a0(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders3SboBinding Wrap13b4f00(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders3SboBinding Wrap13b5000(void** src, SboPayloadBinders3PayloadBox* buf, unsigned long long cap);
};

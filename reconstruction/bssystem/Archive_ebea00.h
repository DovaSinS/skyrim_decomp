// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// BSFile: CRASHLOGGER_PDB(59818@2026.10.24)
// BSFile::ReadBytes: CRASHLOGGER_PDB(59818@2026.10.24)
// Archive: GUESS(low); placeholder name
// NiBinaryStream, BSStringT: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0); declaration taken from the sibling decompilation, identity with this function unproven
// FILE: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); declaration taken from the sibling decompilation, identity with this function unproven
// _iobuf, va_list: GUESS(low) STANDIN; forward declaration, no sibling header declares it
#pragma once

struct va_list;

struct _iobuf;

struct Archive;
struct BSFile;
struct NiFile;

struct Archive;

struct BSFile;

struct NiFile;

struct Archive;

struct BSFile;

struct NiFile;

struct NiFile;

class NiBinaryStream
{
  public:
    typedef unsigned int (* NIBINARYSTREAM_READFN)(NiBinaryStream*, void*, unsigned int,
                                                         unsigned int*, unsigned int);
    typedef unsigned int (* NIBINARYSTREAM_WRITEFN)(NiBinaryStream*, const void*, unsigned int,
                                                          unsigned int*, unsigned int);
    typedef NIBINARYSTREAM_READFN ReadFunction;
    typedef NIBINARYSTREAM_READFN ReadFunc;
    typedef NIBINARYSTREAM_READFN ReadFn;
    typedef NIBINARYSTREAM_READFN READFUNC;
    typedef NIBINARYSTREAM_WRITEFN WriteFunction;
    typedef NIBINARYSTREAM_WRITEFN WriteFn;
    typedef NIBINARYSTREAM_WRITEFN WRITEFUNC;
    typedef NIBINARYSTREAM_READFN Transfer;

    NiBinaryStream();
    virtual ~NiBinaryStream();
    virtual operator bool();
    virtual void Seek(int iNumBytes);
    virtual unsigned int GetPosition();
    virtual void SetEndianSwap(bool bDoSwap);

    operator bool() const;
    bool FileIsGood();
    void Seek(int iOffset, int iWhence);
    unsigned int GetPosition() const;
    unsigned int GetFileSize() const;
    unsigned int ReadIntoBuffer(void* pvBuffer, unsigned int uiBytes);
    unsigned int WriteFromBuffer(const void* pvBuffer, unsigned int uiBytes);
    void* Destroy(unsigned int fFree);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes);
    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents = 1);
    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, int* puiComponentSizes,
                            unsigned int uiNumComponents);
    template <class T> unsigned int BinaryRead(T* pvBuffer, unsigned int auiCount = 1);
    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents);
    void BinaryWrite(const void* pvBuffer, unsigned int uiBytes, unsigned int uiComponentSize);

    template <class T> void Read(T& value);
    void Read(void* data);
    void Read(float* values);
    unsigned int Read(void* buffer, unsigned int bytes);
    unsigned int Read(void* buffer, unsigned int bytes, unsigned int* componentSizes, unsigned int componentCount);
    template <class T> void ReadScalar(T& value);
    void ReadScalar(void* value, unsigned int size);
    void ReadFloat(float& value);
    void ReadUInt(unsigned int& value);
    void ReadComp(void* value, unsigned int size, unsigned int componentSize);
    void ReadGroupId(unsigned int* id);
    unsigned int ReadRaw(void* out, unsigned int n, unsigned int* size);

    void Write(void* buffer);
    void Write(const void* data);
    void Write(float* value);
    void Write(void* buffer, unsigned int bytes);
    unsigned int Write(const void* buffer, unsigned int bytes);
    void Write(const void* pv, unsigned int uiBytes, unsigned int uiComponentSize);
    unsigned int Write(const void* buffer, unsigned int bytes, unsigned int* componentSizes,
                       unsigned int componentCount);
    void WriteSpawnFlag(const bool& onDeath);
    unsigned int GetLine(char* buffer, unsigned int maxChars);

    // Gamebryo 2.2 NiBinaryStream members (ctor 0x00aa1d10 clears +4/+8/+C; GetPosition 0x00aa1d50 returns +4;
    // NiFile::SetEndianSwap 0x00aa1b30 and NiMemStream::SetEndianSwap 0x00aa2f80 install the reader at +8 and the
    // writer at +C; the inline BinaryRead/BinaryWrite call through them and add the byte count to +4).
    unsigned int m_uiAbsoluteCurrentPos; // +0x04
    NIBINARYSTREAM_READFN m_pfnRead;     // +0x08
    NIBINARYSTREAM_WRITEFN m_pfnWrite;   // +0x0C
};

typedef _iobuf FILE;

class NiFile : public NiBinaryStream
{
  public:
    enum OpenMode  // values: Xbox PDB NiFile::OpenMode
    {
        READ_ONLY = 0,
        WRITE_ONLY = 1,
        APPEND_ONLY = 2
    };

    virtual ~NiFile();
    virtual operator bool();
    using NiBinaryStream::Seek;
    virtual void Seek(int iOffset, int iWhence);
    virtual char* FileName();
    virtual unsigned int GetFileSize();

    bool IsGood();
    bool Open(bool, bool);
    bool Flush();
    unsigned int FileRead(void*, unsigned int);

    static NiFile* GetFile(const char* pcName, OpenMode eMode, unsigned int uiSize);
    static NiFile* GetFile(const char* pcName, int eMode, unsigned int uiSize);
    static unsigned int RequestFileAccess(const char*, unsigned int, unsigned int);
    static unsigned int WriteBytesToFile(const void*, unsigned int, unsigned int, FILE*);

    // Members after the NiBinaryStream base (ctor 0x00aa14d0; FileRead 0x00aa1750 advances +0x1C).
    unsigned int m_uiBufferAllocSize; // +0x10
    unsigned int m_uiBufferReadSize;  // +0x14
    unsigned int m_uiPos;             // +0x18
    unsigned int m_uiFilePos;         // +0x1C
    char* m_pBuffer;                  // +0x20
    FILE* m_pFile;                    // +0x24
    OpenMode m_eMode;                 // +0x28
    bool m_bGood;                     // +0x2C
};

template <class T> class BSStringT
{
  public:
    T* pString;              // +0
    unsigned short sLen;     // +4
    unsigned short sMaxLen;  // +6

    BSStringT();                                       // 0x004037b0 { Init(); }
    BSStringT(const T* text);                          // 0x0040c0e0 { Init(); Set(text, 0); }
    BSStringT(const BSStringT<T>& text);               // 0x004047f0 { Init(); Set(text.String(), 0); }
    ~BSStringT();                                      // 0x004037d0 { Set(0, 0); }

    bool Set(const T* text, unsigned int length = 0);  // 0x004037f0
    bool Set(const BSStringT<T>& text);                // 0x00438470
    void Init();                                       // 0x00403970 { pString = 0; SetLength(0); SetMaxLength(0); }
    const T* String() const;                           // 0x00559450 { return pString; }
    operator const T*() const;                         // 0x00559450 (folded with String)
    unsigned int Length() const;                       // 0x004048e0 { sLen == 0xFFFF ? BSStringLength(pString) : sLen }
    unsigned int MaxLength();                          // 0x004039a0 { return sMaxLen; }
    void SetLength(unsigned int length);               // 0x004039c0 sLen = min(length, 0xFFFF)
    void SetMaxLength(unsigned int length);            // 0x00403a00 sMaxLen = min(length, 0xFFFF)
    int PrintfString(const char* format, ...); // 0x00406f60 -> Func00406f90
    int VSPrintF(const char* format, va_list args);// 0x00406f90 vsprintf into char[1024], Set(buf, 0)
    int Func00501c90(BSStringT<T>* text, bool ignoreCase); // exe 0x00501c90
    int Equals(const char* text);                     // 0x007002a0 { return !StrCmp(text, true); }
    BSStringT<T>* Func007a86b0(unsigned int flags);    // 0x007a86b0 deleting destructor wrapper
    int StrCmp(const char* text, bool ignoreCase) const; // 0x00408a80 (_stricmp 0x00404dc0 / 0x00408b20)
    void BSStringT_ToLower();                               // 0x004afad0 { if (pString) Func004afb00(pString, sLen + 1); }

    BSStringT<T>& operator=(const T* text);            // 0x00438390 { Set(text, 0); return *this; }
    BSStringT<T>& operator=(const BSStringT<T>& text); // 0x00501c10 { Set(text); return *this; }
    BSStringT<T>& operator+=(const T* text);           // 0x00404820
};

class BSFile : public NiFile
{
public:
    BSFile(const char*, int, unsigned int, bool);
    BSFile(const char*, bool, unsigned int, bool);
    BSFile(const char*, NiFile::OpenMode, unsigned int, bool);
    virtual ~BSFile();

    virtual void SetEndianSwap(bool bDoSwap);
    using NiFile::Seek;
    virtual void Seek(int aiOffset, int aiWhence); // 0x14
    virtual char* FileName();
    virtual unsigned int GetFileSize();

    virtual bool Open(bool, bool); // 0x20
    virtual bool AttachFileStream(_iobuf*);
    virtual unsigned int GetSize();
    virtual unsigned int ReadBytes(BSStringT<wchar_t>&, unsigned int);
    virtual unsigned int ReadBytes(BSStringT<char>&, unsigned int);
    virtual unsigned int GetLine(char*, unsigned int, wchar_t);
    virtual unsigned int Write(const BSStringT<wchar_t>&, bool);
    virtual unsigned int Write(const BSStringT<char>&, bool);
    virtual bool Exist();
    virtual unsigned int ReadRawData(void*, unsigned int);
    virtual unsigned int WriteRawData(const void*, unsigned int);

    void Close();
    void CheckIsGood();
    bool SetBufferSize(unsigned int auiSize);
    bool NeedCache();
    bool Good() const;
    bool IsGood();
    bool IsOpen();
    bool Write();
    unsigned int ReadBytes(void*, unsigned int);
    unsigned int BinaryRead(void*, unsigned int, unsigned int*, unsigned int = 1);
    bool AttachFileStream(bool, bool);
    unsigned int GetFilePosition();
    unsigned int GetBufferValue();
    char* FileName() const;
    void SetEndian(int, unsigned int);
    void SeekFrom(int iOffset, int iWhence);
    void Write(const char*, int);

    int NiBinaryStream_Write(const char*, unsigned int);
    void NiBinaryStream_Write(const void*, unsigned int);
    bool TESAnimGroup_GetDecal();
    void Func00aff300(int, int);
    bool Func00aff300(bool, bool);
    void Func00aff7c0(BSStringT<char>*, int);
    void BSFile_WriteF(char*, unsigned int);
    unsigned int BSFile_WriteF(const char*, unsigned int);
    unsigned int BSFile_WriteF(const void*, unsigned int);
    void BSFile_Write_00affbb0(void*, int);
    void Func00affd10();

    static void* operator new(size_t size);
    static void operator delete(void*);

    bool m_bIsOpen;
    bool m_bEndianSwap;
    unsigned char unk32[2];
    char* m_pFileBuffer;
    int m_iBufferSize;
    unsigned int m_uiFileSize;
    unsigned int m_uiFilePosition;
    char pFileName[260];
    int iResult;
    unsigned int m_uiBufferPosition;
    unsigned int m_uiBufferSize;
    unsigned int m_uiValueId;
};

struct Archive
{
};

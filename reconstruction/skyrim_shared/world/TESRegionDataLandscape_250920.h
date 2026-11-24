// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// TESRegionDataLandscape: CRASHLOGGER_PDB(59818@2026.10.24)
// TESRegionDataLandscape::LoadRegionDataLandscape: CRASHLOGGER_PDB(59818@2026.10.24)
// FILE, RecursiveSpinLock: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); declaration taken from the sibling decompilation, identity with this function unproven
// TES_RETURN_CODE, NiTPointerMap, NiTPointerAllocator, NiTAbstractPoolAllocator, NiTMapBase, NiTMapItem, CHUNK_ID, BSSimpleList, _WIN32_FIND_DATAA, _FILETIME, BSStringT: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0); declaration taken from the sibling decompilation, identity with this function unproven
// _iobuf, REGION_DATA_ID, BSS: GUESS(low) STANDIN; forward declaration, no sibling header declares it
#pragma once

struct BSS;

struct REGION_DATA_ID;
#include <windows.h>

struct _iobuf;

struct BSFile;
struct BaseFormComponent;
struct BaseRegionData;
struct Flt;
struct FormRecordHeader;
struct NiBinaryStream;
struct NiFile;
struct RegionDataEntry;
struct RegionSound;
struct String;
struct StringType;
struct TESBitArrayFile;
struct TESFile;
struct TESFileGroup;
struct TESForm;
struct TESObjectCELL;
struct TESObjectREFR;
struct TESRecordHeader;
struct TESRegion;
struct TESRegionData;
struct TESTexture;

struct Flt
{
    operator unsigned int() const;
};

class FormRecordHeader
{
public:
    unsigned int form;
    unsigned int length;
    unsigned int flags;
    unsigned int iFormID;
    unsigned int m_uiVersionControlInfo;
    unsigned short m_usFormVersion;
    unsigned short m_usHeaderUnknown;
};

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

class TESFileHeader
{
public:
    float m_fRecordValue;
    unsigned int m_uiFileRecordTotal;
    unsigned int m_uiThirdUnsignedValue;
};

enum TES_RETURN_CODE
{
    TES_RETURN_CODE_TES_ERROR_NONE = 0,
    TES_RETURN_CODE_TES_ERROR_NOT_FOUND = 1,
    TES_RETURN_CODE_TES_ERROR_NO_FILE = 2,
    TES_RETURN_CODE_TES_ERROR_NO_FORM = 3,
    TES_RETURN_CODE_TES_ERROR_NO_CHUNK = 4,
    TES_RETURN_CODE_TES_ERROR_NO_ID = 5,
    TES_RETURN_CODE_TES_ERROR_BAD_FILE = 6,
    TES_RETURN_CODE_TES_ERROR_BAD_ID = 7,
    TES_RETURN_CODE_TES_ERROR_FORM_OPEN = 8,
    TES_RETURN_CODE_TES_ERROR_FILE_OPEN = 9,
    TES_RETURN_CODE_TES_ERROR_WRITE_FAILURE = 10,
    TES_RETURN_CODE_TES_ERROR_INVALID_FILE = 11,
    TES_RETURN_CODE_TES_ERROR_FILE_IN_USE = 12,
    TES_RETURN_CODE_TES_ERROR_CREATE_FAILURE = 13,
};

class RecursiveSpinLock
{
  public:
    volatile unsigned int m_uiOwningThreadID;
    unsigned int m_uiRecursionCount;
    void Lock(const char*);
};

template <class T> class NiTAbstractPoolAllocator
{
  public:
    class AllocNode
    {
      public:
        AllocNode* m_pkNext;
        void* m_pkData;
        T m_element;
    };

    static AllocNode* ms_pkBlockHeader;
    static AllocNode* ms_pkFreeMem;
    static unsigned int ms_uiBlockSize;
    // the pool's lock (Gamebryo's critical section, a RecursiveSpinLock in FNV): NiTPointerAllocator<unsigned
    // int>::Deallocate 0x0045cee0 locks 0x011c5f80 (Lock 0x0040fbf0, Unlock 0x0040fba0) around the free list
    // ms_pkFreeMem 0x011c5f58
    static RecursiveSpinLock ms_kCriticalSection;

    static void _SDMInit();
    static void _SDMShutdown();

  protected:
    static void CreateFreeMem();
};

template <class T> class NiTPointerAllocator : public NiTAbstractPoolAllocator<T>
{
  public:
    void* Allocate();
    void Deallocate(void* p);
};

template <class TKEY, class TVAL> class NiTMapItem
{
  public:
    NiTMapItem* m_pkNext;
    TKEY m_key;
    TVAL m_val;
};

template <class TAlloc, class TKEY, class TVAL> class NiTMapBase
{
  public:
    typedef NiTMapItem<TKEY, TVAL> EntryType;
    struct AntiBloatAllocator : public TAlloc
    {
        unsigned int m_uiCount;
    };
    typedef AntiBloatAllocator MapEntryCount;

    NiTMapBase(unsigned int uiHashSize = 37);
    virtual ~NiTMapBase();

    unsigned int GetCount() const;
    bool IsEmpty() const;
    void SetAt(TKEY kKey, TVAL kVal);
    bool RemoveAt(TKEY kKey);
    void RemoveAll();
    bool GetAt(TKEY kKey, TVAL& kVal) const;
    void* GetFirstPos() const;
    void GetNext(void*& pPos, TKEY& kKey, TVAL& kVal) const;
    void Resize(unsigned int uNewHashSize);

  public:  // hashing and item policy, overridden per map type
    virtual unsigned int KeyToHashIndex(TKEY kKey) const;
    virtual bool IsKeysEqual(TKEY kKey1, TKEY kKey2) const;
    virtual void SetValue(NiTMapItem<TKEY, TVAL>* pItem, TKEY kKey, TVAL kVal);
    virtual void ClearValue(NiTMapItem<TKEY, TVAL>* pItem);
  public:  // item allocation (pure: the concrete map supplies it)
    virtual NiTMapItem<TKEY, TVAL>* NewItem() = 0;
    virtual void DeleteItem(NiTMapItem<TKEY, TVAL>* pItem) = 0;

    unsigned int m_uiHashSize;
    NiTMapItem<TKEY, TVAL>** m_ppkHashTable;
    AntiBloatAllocator m_kItemCount;
};

template <class TKEY, class TVAL>
class NiTPointerMap : public NiTMapBase<NiTPointerAllocator<unsigned int>, TKEY, TVAL>
{
  public:
    NiTPointerMap(unsigned int uiHashSize = 37);
    virtual ~NiTPointerMap();

    virtual NiTMapItem<TKEY, TVAL>* NewItem();
    virtual void DeleteItem(NiTMapItem<TKEY, TVAL>* pkItem);
};

enum CHUNK_ID
{
    CHUNK_ID_NO_CHUNK = 0,
    CHUNK_ID_HEDR_ID = 1380205896,
    CHUNK_ID_MAST_ID = 1414742349,
    CHUNK_ID_DELE_ID = 1162626372,
    CHUNK_ID_SCRD_ID = 1146241875,
    CHUNK_ID_SCRS_ID = 1397900115,
    CHUNK_ID_NAME_ID = 1162690894,
    CHUNK_ID_OBND_ID = 1145979471,
    CHUNK_ID_MODL_ID = 1279545165,
    CHUNK_ID_MODD_ID = 1145327437,
    CHUNK_ID_MOSD_ID = 1146310477,
    CHUNK_ID_MOD2_ID = 843337549,
    CHUNK_ID_MOD3_ID = 860114765,
    CHUNK_ID_MOD4_ID = 876891981,
    CHUNK_ID_MODT_ID = 1413762893,
    CHUNK_ID_MO2T_ID = 1412583245,
    CHUNK_ID_MO3T_ID = 1412648781,
    CHUNK_ID_MO4T_ID = 1412714317,
    CHUNK_ID_MODS_ID = 1396985677,
    CHUNK_ID_MO2S_ID = 1395806029,
    CHUNK_ID_MO3S_ID = 1395871565,
    CHUNK_ID_MO4S_ID = 1395937101,
    CHUNK_ID_MWD1_ID = 826562381,
    CHUNK_ID_MWD2_ID = 843339597,
    CHUNK_ID_MWD3_ID = 860116813,
    CHUNK_ID_MWD4_ID = 876894029,
    CHUNK_ID_MWD5_ID = 893671245,
    CHUNK_ID_MWD6_ID = 910448461,
    CHUNK_ID_MWD7_ID = 927225677,
    CHUNK_ID_MWT1_ID = 827610957,
    CHUNK_ID_MWT2_ID = 844388173,
    CHUNK_ID_MWT3_ID = 861165389,
    CHUNK_ID_MWT4_ID = 877942605,
    CHUNK_ID_MWT5_ID = 894719821,
    CHUNK_ID_MWT6_ID = 911497037,
    CHUNK_ID_MWT7_ID = 928274253,
    CHUNK_ID_KFFZ_ID = 1514554955,
    CHUNK_ID_NIFZ_ID = 1514555726,
    CHUNK_ID_NIFT_ID = 1413892430,
    CHUNK_ID_ANAM_ID = 1296125505,
    CHUNK_ID_BNAM_ID = 1296125506,
    CHUNK_ID_CNAM_ID = 1296125507,
    CHUNK_ID_DNAM_ID = 1296125508,
    CHUNK_ID_ENAM_ID = 1296125509,
    CHUNK_ID_FNAM_ID = 1296125510,
    CHUNK_ID_GNAM_ID = 1296125511,
    CHUNK_ID_HNAM_ID = 1296125512,
    CHUNK_ID_INAM_ID = 1296125513,
    CHUNK_ID_JNAM_ID = 1296125514,
    CHUNK_ID_KNAM_ID = 1296125515,
    CHUNK_ID_LNAM_ID = 1296125516,
    CHUNK_ID_MNAM_ID = 1296125517,
    CHUNK_ID_NNAM_ID = 1296125518,
    CHUNK_ID_ONAM_ID = 1296125519,
    CHUNK_ID_PNAM_ID = 1296125520,
    CHUNK_ID_CLNM_ID = 1296125521,
    CHUNK_ID_RNAM_ID = 1296125522,
    CHUNK_ID_SNAM_ID = 1296125523,
    CHUNK_ID_TNAM_ID = 1296125524,
    CHUNK_ID_UNAM_ID = 1296125525,
    CHUNK_ID_VNAM_ID = 1296125526,
    CHUNK_ID_WNAM_ID = 1296125527,
    CHUNK_ID_WNM1_ID = 827149911,
    CHUNK_ID_WNM2_ID = 843927127,
    CHUNK_ID_WNM3_ID = 860704343,
    CHUNK_ID_WNM4_ID = 877481559,
    CHUNK_ID_WNM5_ID = 894258775,
    CHUNK_ID_WNM6_ID = 911035991,
    CHUNK_ID_WNM7_ID = 927813207,
    CHUNK_ID_WMI1_ID = 826887511,
    CHUNK_ID_WMI2_ID = 843664727,
    CHUNK_ID_WMI3_ID = 860441943,
    CHUNK_ID_XNAM_ID = 1296125528,
    CHUNK_ID_YNAM_ID = 1296125529,
    CHUNK_ID_ZNAM_ID = 1296125530,
    CHUNK_ID_NAM1_ID = 827146574,
    CHUNK_ID_NAM2_ID = 843923790,
    CHUNK_ID_NAM3_ID = 860701006,
    CHUNK_ID_NAM4_ID = 877478222,
    CHUNK_ID_NAM5_ID = 894255438,
    CHUNK_ID_NAM6_ID = 911032654,
    CHUNK_ID_NAM7_ID = 927809870,
    CHUNK_ID_NAM8_ID = 944587086,
    CHUNK_ID_NAM9_ID = 961364302,
    CHUNK_ID_NAM0_ID = 810369358,
    CHUNK_ID_WMS1_ID = 827542871,
    CHUNK_ID_WMS2_ID = 844320087,
    CHUNK_ID_RCLR_ID = 1380729682,
    CHUNK_ID_RPLD_ID = 1145851986,
    CHUNK_ID_RPLI_ID = 1229738066,
    CHUNK_ID_RDAT_ID = 1413563474,
    CHUNK_ID_RDOB_ID = 1112491090,
    CHUNK_ID_RDOJ_ID = 1246708818,
    CHUNK_ID_RDOT_ID = 1414480978,
    CHUNK_ID_RDWT_ID = 1415005266,
    CHUNK_ID_RDMP_ID = 1347241042,
    CHUNK_ID_RDLN_ID = 1313621074,
    CHUNK_ID_RDGS_ID = 1397179474,
    CHUNK_ID_RDMD_ID = 1145914450,
    CHUNK_ID_RDMO_ID = 1330463826,
    CHUNK_ID_RDSD_ID = 1146307666,
    CHUNK_ID_RDSI_ID = 1230193746,
    CHUNK_ID_RDSB_ID = 1112753234,
    CHUNK_ID_RDID_ID = 1145652306,
    CHUNK_ID_XIDX_ID = 1480870232,
    CHUNK_ID_XACT_ID = 1413693784,
    CHUNK_ID_XOWN_ID = 1314344792,
    CHUNK_ID_XGLB_ID = 1112295256,
    CHUNK_ID_XRNK_ID = 1263424088,
    CHUNK_ID_XHLT_ID = 1414285400,
    CHUNK_ID_XHLP_ID = 1347176536,
    CHUNK_ID_XUSE_ID = 1163089240,
    CHUNK_ID_XTIM_ID = 1296651352,
    CHUNK_ID_XCNT_ID = 1414415192,
    CHUNK_ID_XCHG_ID = 1195918168,
    CHUNK_ID_XSOL_ID = 1280267096,
    CHUNK_ID_XSCL_ID = 1279480664,
    CHUNK_ID_XLOC_ID = 1129270360,
    CHUNK_ID_XTEL_ID = 1279611992,
    CHUNK_ID_XMRK_ID = 1263684952,
    CHUNK_ID_MMRK_ID = 1263684941,
    CHUNK_ID_AMRK_ID = 1263684929,
    CHUNK_ID_XEDL_ID = 1279542616,
    CHUNK_ID_XPSL_ID = 1280528472,
    CHUNK_ID_XSED_ID = 1145394008,
    CHUNK_ID_XPCI_ID = 1229148248,
    CHUNK_ID_XRGD_ID = 1145524824,
    CHUNK_ID_XRGB_ID = 1111970392,
    CHUNK_ID_XLOD_ID = 1146047576,
    CHUNK_ID_XESP_ID = 1347634520,
    CHUNK_ID_XRTM_ID = 1297371736,
    CHUNK_ID_XLKR_ID = 1380666456,
    CHUNK_ID_XACR_ID = 1380139352,
    CHUNK_ID_XAPD_ID = 1146110296,
    CHUNK_ID_XAPR_ID = 1380991320,
    CHUNK_ID_XATO_ID = 1330921816,
    CHUNK_ID_XMRC_ID = 1129467224,
    CHUNK_ID_XHRS_ID = 1397901400,
    CHUNK_ID_XPSN_ID = 1314082904,
    CHUNK_ID_XTRG_ID = 1196577880,
    CHUNK_ID_XLCM_ID = 1296256088,
    CHUNK_ID_XDCR_ID = 1380140120,
    CHUNK_ID_XRDS_ID = 1396986456,
    CHUNK_ID_XRAD_ID = 1145131608,
    CHUNK_ID_XLMB_ID = 1112362072,
    CHUNK_ID_XMBR_ID = 1380076888,
    CHUNK_ID_XMBO_ID = 1329745240,
    CHUNK_ID_XEMI_ID = 1229800792,
    CHUNK_ID_XRDO_ID = 1329877592,
    CHUNK_ID_XCLC_ID = 1129071448,
    CHUNK_ID_XCLL_ID = 1280066392,
    CHUNK_ID_XCLW_ID = 1464615768,
    CHUNK_ID_XCWT_ID = 1415005016,
    CHUNK_ID_XCLR_ID = 1380729688,
    CHUNK_ID_XCLM_ID = 1296843608,
    CHUNK_ID_XCMT_ID = 1414349656,
    CHUNK_ID_XCMO_ID = 1330463576,
    CHUNK_ID_XCET_ID = 1413825368,
    CHUNK_ID_XCCM_ID = 1296253784,
    CHUNK_ID_XCIM_ID = 1296647000,
    CHUNK_ID_XCAS_ID = 1396786008,
    CHUNK_ID_XPWR_ID = 1381453912,
    CHUNK_ID_XRFB_ID = 1111904856,
    CHUNK_ID_XWLT_ID = 1414289240,
    CHUNK_ID_XLTW_ID = 1465142360,
    CHUNK_ID_XNVP_ID = 1347833432,
    CHUNK_ID_XNDP_ID = 1346653784,
    CHUNK_ID_XLCR_ID = 1347175256,
    CHUNK_ID_XPRM_ID = 1297240152,
    CHUNK_ID_XPRD_ID = 1146245208,
    CHUNK_ID_XPPA_ID = 1095782488,
    CHUNK_ID_XOCP_ID = 1346588504,
    CHUNK_ID_XORD_ID = 1146244952,
    CHUNK_ID_XPOD_ID = 1146048600,
    CHUNK_ID_XPTL_ID = 1280594008,
    CHUNK_ID_XROO_ID = 1330598488,
    CHUNK_ID_XRMR_ID = 1380799064,
    CHUNK_ID_XLRM_ID = 1297239128,
    CHUNK_ID_XMBP_ID = 1346522456,
    CHUNK_ID_XTRI_ID = 1230132312,
    CHUNK_ID_XAMC_ID = 1129136472,
    CHUNK_ID_XAMT_ID = 1414349144,
    CHUNK_ID_XEZN_ID = 1314538840,
    CHUNK_ID_XIBS_ID = 1396853080,
    CHUNK_ID_XWMS_ID = 1397577560,
    CHUNK_ID_XSRF_ID = 1179800408,
    CHUNK_ID_XSRD_ID = 1146245976,
    CHUNK_ID_ACTN_ID = 1314145089,
    CHUNK_ID_STPR_ID = 1380996179,
    CHUNK_ID_SOUL_ID = 1280659283,
    CHUNK_ID_SLCP_ID = 1346587731,
    CHUNK_ID_CIDA_ID = 1094997059,
    CHUNK_ID_TRDT_ID = 1413763668,
    CHUNK_ID_TCLT_ID = 1414284116,
    CHUNK_ID_TCLF_ID = 1179403092,
    CHUNK_ID_TCFU_ID = 1430668116,
    CHUNK_ID_TDUM_ID = 1297433684,
    CHUNK_ID_ESCE_ID = 1162040133,
    CHUNK_ID_ESCS_ID = 1396921157,
    CHUNK_ID_ESBS_ID = 1396855621,
    CHUNK_ID_ESHS_ID = 1397248837,
    CHUNK_ID_ESAS_ID = 1396790085,
    CHUNK_ID_WIDX_ID = 1480870231,
    CHUNK_ID_MODQ_ID = 1363431245,
    CHUNK_ID_DATA_ID = 1096040772,
    CHUNK_ID_ATDM_ID = 1296323649,
    CHUNK_ID_ACBS_ID = 1396851521,
    CHUNK_ID_ATTR_ID = 1381258305,
    CHUNK_ID_DESC_ID = 1129530692,
    CHUNK_ID_INDX_ID = 1480871497,
    CHUNK_ID_STRV_ID = 1448236115,
    CHUNK_ID_INTV_ID = 1448365641,
    CHUNK_ID_FLTV_ID = 1448365126,
    CHUNK_ID_DODT_ID = 1413762884,
    CHUNK_ID_NPAC_ID = 1128353870,
    CHUNK_ID_ND3D_ID = 1144210510,
    CHUNK_ID_ANIS_ID = 1397313089,
    CHUNK_ID_CNTO_ID = 1330925123,
    CHUNK_ID_SPLO_ID = 1330401363,
    CHUNK_ID_REPL_ID = 1280329042,
    CHUNK_ID_BIPL_ID = 1280330050,
    CHUNK_ID_LVLO_ID = 1330402892,
    CHUNK_ID_LVLD_ID = 1145853516,
    CHUNK_ID_LVLF_ID = 1179407948,
    CHUNK_ID_LVLG_ID = 1196185164,
    CHUNK_ID_EFID_ID = 1145652805,
    CHUNK_ID_EFIT_ID = 1414088261,
    CHUNK_ID_AVIT_ID = 1414092353,
    CHUNK_ID_SCIT_ID = 1414087507,
    CHUNK_ID_SPIT_ID = 1414090835,
    CHUNK_ID_ENIT_ID = 1414090309,
    CHUNK_ID_EITM_ID = 1297369413,
    CHUNK_ID_EAMT_ID = 1414349125,
    CHUNK_ID_PKID_ID = 1145654096,
    CHUNK_ID_PKDT_ID = 1413761872,
    CHUNK_ID_PLDT_ID = 1413762128,
    CHUNK_ID_PLD2_ID = 843336784,
    CHUNK_ID_PSDT_ID = 1413763920,
    CHUNK_ID_PTDT_ID = 1413764176,
    CHUNK_ID_PTD2_ID = 843338832,
    CHUNK_ID_PKDD_ID = 1145326416,
    CHUNK_ID_PKED_ID = 1145391952,
    CHUNK_ID_PKND_ID = 1145981776,
    CHUNK_ID_PKFD_ID = 1145457488,
    CHUNK_ID_PKW3_ID = 861358928,
    CHUNK_ID_PKW2_ID = 844581712,
    CHUNK_ID_PUID_ID = 1145656656,
    CHUNK_ID_PKPT_ID = 1414548304,
    CHUNK_ID_PKES_ID = 843402064,
    CHUNK_ID_PKAM_ID = 1296124752,
    CHUNK_ID_POBA_ID = 1094864720,
    CHUNK_ID_POEA_ID = 1095061328,
    CHUNK_ID_POCA_ID = 1094930256,
    CHUNK_ID_BIDX_ID = 1480870210,
    CHUNK_ID_BPTM_ID = 1297371202,
    CHUNK_ID_BPTF_ID = 1179930690,
    CHUNK_ID_BMDT_ID = 1413762370,
    CHUNK_ID_BMCT_ID = 1413696834,
    CHUNK_ID_PFIG_ID = 1195984464,
    CHUNK_ID_PFPC_ID = 1129334352,
    CHUNK_ID_MVRF_ID = 1179801165,
    CHUNK_ID_AGTY_ID = 1498695489,
    CHUNK_ID_AGFD_ID = 1145456449,
    CHUNK_ID_AGSC_ID = 1129531201,
    CHUNK_ID_AGSX_ID = 1481852737,
    CHUNK_ID_ICON_ID = 1313817417,
    CHUNK_ID_ICO2_ID = 844055369,
    CHUNK_ID_SCRI_ID = 1230127955,
    CHUNK_ID_SCHR_ID = 1380467539,
    CHUNK_ID_SCVR_ID = 1381385043,
    CHUNK_ID_SCTX_ID = 1481917267,
    CHUNK_ID_SCDA_ID = 1094992723,
    CHUNK_ID_SCRO_ID = 1330791251,
    CHUNK_ID_SCRV_ID = 1448231763,
    CHUNK_ID_SLCS_ID = 1396919379,
    CHUNK_ID_SLSD_ID = 1146309715,
    CHUNK_ID_SLLD_ID = 1145850963,
    CHUNK_ID_SLFD_ID = 1145457747,
    CHUNK_ID_SLUD_ID = 1146440787,
    CHUNK_ID_VHGT_ID = 1413957718,
    CHUNK_ID_VNML_ID = 1280134742,
    CHUNK_ID_VCLR_ID = 1380729686,
    CHUNK_ID_BTXT_ID = 1415074882,
    CHUNK_ID_ATXT_ID = 1415074881,
    CHUNK_ID_VTXT_ID = 1415074902,
    CHUNK_ID_MPCD_ID = 1145262157,
    CHUNK_ID_AIDT_ID = 1413761345,
    CHUNK_ID_PGRP_ID = 1347569488,
    CHUNK_ID_PGRC_ID = 1381123920,
    CHUNK_ID_PGRI_ID = 1230128976,
    CHUNK_ID_PGRL_ID = 1280460624,
    CHUNK_ID_PGAG_ID = 1195460432,
    CHUNK_ID_LVCR_ID = 1380144716,
    CHUNK_ID_GMDT_ID = 1413762375,
    CHUNK_ID_QSTI_ID = 1230263121,
    CHUNK_ID_INFC_ID = 1128681033,
    CHUNK_ID_INFX_ID = 1481002569,
    CHUNK_ID_QSDT_ID = 1413763921,
    CHUNK_ID_QSTA_ID = 1096045393,
    CHUNK_ID_QOBJ_ID = 1245859665,
    CHUNK_ID_TPIC_ID = 1128878164,
    CHUNK_ID_QSTR_ID = 1381258065,
    CHUNK_ID_WHGT_ID = 1413957719,
    CHUNK_ID_EDID_ID = 1145652293,
    CHUNK_ID_FULL_ID = 1280070982,
    CHUNK_ID_LODH_ID = 1212436300,
    CHUNK_ID_LODV_ID = 1447317324,
    CHUNK_ID_LODS_ID = 1396985676,
    CHUNK_ID_LODT_ID = 1413762892,
    CHUNK_ID_LODC_ID = 1128550220,
    CHUNK_ID_LODN_ID = 1313099596,
    CHUNK_ID_FGGS_ID = 1397180230,
    CHUNK_ID_FGGA_ID = 1095190342,
    CHUNK_ID_FGTS_ID = 1398032198,
    CHUNK_ID_HCLR_ID = 1380729672,
    CHUNK_ID_OFST_ID = 1414743631,
    CHUNK_ID_SNDD_ID = 1145327187,
    CHUNK_ID_SNDX_ID = 1480871507,
    CHUNK_ID_CSCR_ID = 1380143939,
    CHUNK_ID_CSDT_ID = 1413763907,
    CHUNK_ID_CSDF_ID = 1178882883,
    CHUNK_ID_CSDI_ID = 1229214531,
    CHUNK_ID_CSDC_ID = 1128551235,
    CHUNK_ID_CSTD_ID = 1146377027,
    CHUNK_ID_CSAD_ID = 1145131843,
    CHUNK_ID_CSSD_ID = 1146311491,
    CHUNK_ID_WLST_ID = 1414745175,
    CHUNK_ID_LVSR_ID = 1347638860,
    CHUNK_ID_EFSD_ID = 1146308165,
    CHUNK_ID_IDLC_ID = 1129071689,
    CHUNK_ID_IDLA_ID = 1095517257,
    CHUNK_ID_IDLF_ID = 1179403337,
    CHUNK_ID_IDLT_ID = 1414284361,
    CHUNK_ID_IDLB_ID = 1112294473,
    CHUNK_ID_IDLN_ID = 1313621065,
    CHUNK_ID_PROD_ID = 1146049104,
    CHUNK_ID_NVER_ID = 1380275790,
    CHUNK_ID_NVVX_ID = 1482053198,
    CHUNK_ID_NVTR_ID = 1381258830,
    CHUNK_ID_NVEX_ID = 1480939086,
    CHUNK_ID_NVTX_ID = 1481922126,
    CHUNK_ID_NVLX_ID = 1481397838,
    CHUNK_ID_NVGD_ID = 1145525838,
    CHUNK_ID_NVCA_ID = 1094932046,
    CHUNK_ID_NVDP_ID = 1346655822,
    CHUNK_ID_DEST_ID = 1414743364,
    CHUNK_ID_DSTD_ID = 1146377028,
    CHUNK_ID_DSTF_ID = 1179931460,
    CHUNK_ID_DMDL_ID = 1279544644,
    CHUNK_ID_DMDT_ID = 1413762372,
    CHUNK_ID_DMDS_ID = 1396985156,
    CHUNK_ID_TX00_ID = 808474708,
    CHUNK_ID_TX01_ID = 825251924,
    CHUNK_ID_TX02_ID = 842029140,
    CHUNK_ID_TX03_ID = 858806356,
    CHUNK_ID_TX04_ID = 875583572,
    CHUNK_ID_TX05_ID = 892360788,
    CHUNK_ID_TX06_ID = 909138004,
    CHUNK_ID_TX07_ID = 925915220,
    CHUNK_ID_TX08_ID = 942692436,
    CHUNK_ID_TX09_ID = 959469652,
    CHUNK_ID_DMTL_ID = 1280593220,
    CHUNK_ID_NVMI_ID = 1229805134,
    CHUNK_ID_NVCI_ID = 1229149774,
    CHUNK_ID_BPTN_ID = 1314148418,
    CHUNK_ID_BPNN_ID = 1313755202,
    CHUNK_ID_BPNT_ID = 1414418498,
    CHUNK_ID_BPNI_ID = 1229869122,
    CHUNK_ID_BPND_ID = 1145983042,
    CHUNK_ID_ETYP_ID = 1348031557,
    CHUNK_ID_PRKE_ID = 1162564176,
    CHUNK_ID_PRKF_ID = 1179341392,
    CHUNK_ID_PRKC_ID = 1129009744,
    CHUNK_ID_EPFT_ID = 1413894213,
    CHUNK_ID_EPFD_ID = 1145458757,
    CHUNK_ID_EPF2_ID = 843468869,
    CHUNK_ID_EPF3_ID = 860246085,
    CHUNK_ID_ITXT_ID = 1415074889,
    CHUNK_ID_ISCR_ID = 1380143945,
    CHUNK_ID_CRDT_ID = 1413763651,
    CHUNK_ID_COED_ID = 1145392963,
    CHUNK_ID_SIAD_ID = 1145129216,
    CHUNK_ID_EIAD_ID = 1145129471,
    CHUNK_ID_VTCK_ID = 1262703702,
    CHUNK_ID_TPLT_ID = 1414287444,
    CHUNK_ID_MICO_ID = 1329809741,
    CHUNK_ID_MIC2_ID = 843270477,
    CHUNK_ID_NEXT_ID = 1415071054,
    CHUNK_ID_IMPS_ID = 1397771593,
    CHUNK_ID_IMPF_ID = 1179667785,
    CHUNK_ID_LTMP_ID = 1347245132,
    CHUNK_ID_RAFD_ID = 1145454930,
    CHUNK_ID_RAFB_ID = 1111900498,
    CHUNK_ID_RAFS_ID = 1397113170,
    CHUNK_ID_RAFL_ID = 1279672658,
    CHUNK_ID_RAFN_ID = 1313227090,
    CHUNK_ID_RALH_ID = 1212957010,
    CHUNK_ID_RALN_ID = 1313620306,
    CHUNK_ID_RAGA_ID = 1095188818,
    CHUNK_ID_RAGN_ID = 1313292626,
    CHUNK_ID_RAPS_ID = 1397768530,
    CHUNK_ID_VATS_ID = 1398030678,
    CHUNK_ID_VANM_ID = 1296974166,
    CHUNK_ID_RCID_ID = 1279869778,
    CHUNK_ID_RCQY_ID = 1498497874,
    CHUNK_ID_RCCF_ID = 1178813266,
    CHUNK_ID_RCOD_ID = 1146045266,
    CHUNK_ID_CQES_ID = 1397051715,
    CHUNK_ID_CARD_ID = 1146241347,
    CHUNK_ID_BRUS_ID = 1398100546,
    CHUNK_ID_DAT2_ID = 844382532,
    CHUNK_ID_XXXX_ID = 1482184792,
};

template <class T> class BSSimpleList
{
public:
    T m_item;
    BSSimpleList<T>* m_pkNext;
    BSSimpleList();
    BSSimpleList(T& item);
    BSSimpleList(T item, BSSimpleList<T>* next); // exe 0x004b0680
    void Func004019f0(); // exe 0x004019f0, BGSListForm initialization
    ~BSSimpleList();
    T& GetItem();
    BSSimpleList<T>* GetNext();
    bool IsEmpty();
    void AddTail(T& item);
    void AddTail(const T& item);
    void Remove(const T& item);
    bool IsInList(T& item);
    void AddHead(T& item);
    // the const forms the process-list code calls (as AddTail above has both)
    void AddHead(const T& item);
    bool IsInList(const T& item) const;
    bool IsEmpty() const;
    bool Contains(const T& item); // exe 0x006c6400, obstacle list
    void RemoveHead();
    void RemoveAll();
    void Sort(int (* compare)(T, T));
    void SetItem(const T& item);
    void Insert(T item, int (* compare)(T, T));
    // 0x005ae380 (/Od, one folded body for pointer items): counts the nodes whose item is non-null, walking with
    // GetItem (0x006815c0) and GetNext (0x00726070); units' GetSize stand-ins bind the same address
    unsigned int ItemsInList();
    // Per-unit allocation hooks: menu/filefinder inline these calls in the exe. No data layout change.
    static void* operator new(size_t size);
    static void operator delete(void* pointer);
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

class TESFile
{
public:
    struct FormRecord
    {
        unsigned int form;
        unsigned int length;
        unsigned int flags;
        unsigned int id;
        unsigned int version;
        unsigned int control;
    };

    TES_RETURN_CODE m_lastError; // src: XBOX_RETAIL_PDB +0x0 (old: m_eReturnCode)
    TESFile* pThreadSafeParent; // src: XBOX_RETAIL_PDB +0x4 (old: m_pThreadSafeParent)
    NiTPointerMap<unsigned int, TESFile*>* pThreadSafeFileMap; // src: XBOX_RETAIL_PDB +0x8 (old: m_pThreadSafeFileMap)
    BSFile* m_pLockedFile; // src: XBOX_RETAIL_PDB +0xc (old: m_pSecondaryFile)
    BSFile* m_pFile;
    TESBitArrayFile* pFormUserDataBitArray; // src: XBOX_RETAIL_PDB +0x14 (old: m_pBitArrayFile1)
    TESBitArrayFile* pFormVersionBitArray; // src: XBOX_RETAIL_PDB +0x18 (old: m_pBitArrayFile2)
    TESBitArrayFile* pFormIDBitArray; // src: XBOX_RETAIL_PDB +0x1c (old: m_pBitArrayFile3)
    char m_Filename[260]; // src: XBOX_RETAIL_PDB +0x20 (old: m_acFilename)
    char m_Path[260]; // src: XBOX_RETAIL_PDB +0x124 (old: m_acPath)
    char* m_pBuffer;
    unsigned int m_uiBufferAllocSize;
    unsigned int m_firstCellOffset; // src: XBOX_RETAIL_PDB +0x230 (old: m_uiReadPosition)
    unsigned int m_currCellOffset; // src: XBOX_RETAIL_PDB +0x234 (old: m_uiBufferSize)
    TESObjectCELL* m_pCurrCell; // src: XBOX_RETAIL_PDB +0x238 (old: m_pCurrentCell)
    unsigned int m_currRefOffset; // src: XBOX_RETAIL_PDB +0x23c (old: m_uiFormCount)
    FormRecordHeader m_currentform; // src: XBOX_RETAIL_PDB +0x240 (old: m_kRecordInfo)
    CHUNK_ID m_currentchunkID; // src: XBOX_RETAIL_PDB +0x258 (old: m_eChunkID)
    unsigned int m_actualChunkSize; // src: XBOX_RETAIL_PDB +0x25c (old: m_uiChunkSize)
    unsigned int m_filesize; // src: XBOX_RETAIL_PDB +0x260 (old: m_uiChunkOffset)
    unsigned int m_fileoffset; // src: XBOX_RETAIL_PDB +0x264 (old: m_uiRecordSize)
    unsigned int m_formoffset; // src: XBOX_RETAIL_PDB +0x268 (old: m_uiRecordOffset)
    unsigned int m_chunkoffset; // src: XBOX_RETAIL_PDB +0x26c (old: m_uiCurrentOffset)
    FormRecordHeader m_saveform; // src: XBOX_RETAIL_PDB +0x270 (old: m_kChunkInfo)
    unsigned int m_saveformoffset; // src: XBOX_RETAIL_PDB +0x288 (old: m_uiChunkValue1)
    unsigned int m_savechunkoffset; // src: XBOX_RETAIL_PDB +0x28c (old: m_uiChunkValue2)
    BSSimpleList<TESFileGroup*> m_grouplist; // src: XBOX_RETAIL_PDB +0x290 (old: m_kRecordList)
    bool bHasGroups; // src: XBOX_RETAIL_PDB +0x298 (old: m_bIsLoading)
    bool bMustEndianConvert; // src: XBOX_RETAIL_PDB +0x299 (old: m_bIsSaving)
    bool bCloseFileOverride; // src: XBOX_RETAIL_PDB +0x29a (old: m_bHasCurrentGroup)
    unsigned char layoutPadding29B;
    _WIN32_FIND_DATAA m_FileInfo; // src: XBOX_RETAIL_PDB +0x29c (old: m_kFindData)
    TESFileHeader fileHeaderInfo; // src: XBOX_RETAIL_PDB +0x3dc (old: m_kFileMetadata)
    unsigned int m_Flags; // src: XBOX_RETAIL_PDB +0x3e8 (old: m_uiFileCount)
    BSSimpleList<char*> listMasters; // src: XBOX_RETAIL_PDB +0x3ec (old: m_kFilenameList)
    BSSimpleList<_ULARGE_INTEGER*> listMastersData; // src: XBOX_RETAIL_PDB +0x3f4 (old: m_kFileSizeList)
    unsigned int iMasterCount; // src: XBOX_RETAIL_PDB +0x3fc (old: m_uiTESFileCount)
    TESFile** m_pMasterPtrs; // src: XBOX_RETAIL_PDB +0x400 (old: m_ppTESFiles)
    _FILETIME DeletedFormTime; // src: XBOX_RETAIL_PDB +0x404 (old: m_kLastWriteTime)
    unsigned char cCompileIndex; // src: XBOX_RETAIL_PDB +0x40c (old: m_ucCompileIndex)
    unsigned char layoutPadding40D;
    unsigned short layoutPadding40E;
    BSStringT<char> cCreatedBy; // src: XBOX_RETAIL_PDB +0x410 (old: m_kCreator)
    BSStringT<char> cSummary; // src: XBOX_RETAIL_PDB +0x418 (old: m_kSummary)
    char* pDecompressedFormBuffer; // src: XBOX_RETAIL_PDB +0x420 (old: m_pDecompressedFormBuffer)
    unsigned int iDecompressedFormBufferSize; // src: XBOX_RETAIL_PDB +0x424 (old: m_uiAuxBufferSize)
    bool bCached; // src: XBOX_RETAIL_PDB +0x428 (old: m_bIsMaster)
    bool bCaching; // src: XBOX_RETAIL_PDB +0x429 (old: m_bOptimizedFile)
    bool bDLC; // src: XBOX_RETAIL_PDB +0x42a (old: m_bIsDLC)
    unsigned char layoutPadding42B;

    bool CreateTES(char*, char*, int);
    bool CreateTES(int);
    bool OpenTES(char*, char*, int, bool);
    bool OpenTESFile(int, bool);
    bool CloseTESFile();
    bool DeleteTES();
    bool IsOpen();
    bool QDLC();
    void SetDLC(bool);
    int ReadTESInfo();
    int SaveTESInfo();
    int RewriteFormHeader();
    TESForm* BuildTESInfoForm();
    int GetFormCount();
    void ModFormCount(int);
    void SetFormCount(int);
    int GetFileLanguage();
    void SetFileLanguage(int);
    float GetFileVersion();
    void SetFileVersion(float);
    bool IsFileVersionTooHigh();
    unsigned int GetFORMSize();
    const char* GetPath();
    const char* GetFilename();
    unsigned int GetFileSize();
    _WIN32_FIND_DATAA* GetFileData();
    void GetCreateTime(_SYSTEMTIME*);
    void GetLastWriteTime(_FILETIME*);
    void GetLastWriteTime(_SYSTEMTIME*);
    void* GetCreator();
    void* GetSummary();
    bool MastersChecked(void*);
    bool GenIndexTable(void*, bool);
    TESFile* GetMasterFile(unsigned int);
    char* GetMasterFileName(unsigned int);
    unsigned int GetMasterFileCount();
    unsigned int GetFileIndex(TESFile*);
    void ClearMasters();
    void AddMaster(char*);
    bool AddMasters(void*);
    void RemoveMaster(unsigned int);
    bool DependsOnMaster(char*);
    bool MastersChanged();
    bool CheckLODPlugins();
    void* GetMasterList();
    unsigned char GetFileCompileIndex();
    void SetCompileIndex(unsigned char);
    void AddToDataHandler();
    bool CurrentGroupMayContainForm(TESForm*);
    void GetAnimationSequence(FormRecordHeader*);
    void ClearGroupStack();
    void OpenGroup(FormRecordHeader*);
    void CloseGroup();
    bool IsFormInCurrentGroup(TESForm*);
    bool IsGroupOpen();
    void StartAndEndGroupsForForm(TESForm*);
    void ResetCurrentForm();
    void TESRewind(bool getform);
    TESFileGroup* GetCurrentGroup();
    void* GetGroupList();
    void SetGroupMode(bool);
    void TESRewindChunk();
    bool NextForm(bool);
    bool HasNextForm();
    void RewindForm();
    unsigned char GetTESForm();
    unsigned int GetOffset();
    unsigned int GetOffsetChunk();
    bool SetOffset(unsigned int);
    bool SetOffsetChunk(unsigned int);
    int GetFormAtOffset(unsigned int);
    unsigned int CopyCurrentFormToBuffer(void*, unsigned int);
    int ReadCurrentForm();
    bool NextChunk();
    unsigned int GetChunkSize();
    bool GetChunkData(unsigned short*);
    bool GetChunkData(short*);
    bool GetChunkData(float*);
    bool GetChunkData(unsigned int*);
    bool GetChunkData(int*);
    bool GetChunkData(void*, unsigned int);
    void ClearCurrentChunk();
    bool HasMaster(char*);
    int WriteForm(TESForm*);
    int WriteFormContents(TESForm*);
    void LoadForm(TESForm*);
    int WriteChunkData(int, void*, unsigned int);
    unsigned int GetCurrentReadPosition();
    bool ForceSaveFormHeader(FormRecordHeader*, unsigned int);
    void SetMasterFile(bool);
    bool IsMasterFile();
    void SetOptimizedFile(bool);
    bool GetOptimizedFile();
    void SetChecked(bool);
    bool GetIsChecked();
    void SetAltered(bool);
    bool GetAltered();
    void SetActive(bool);
    bool GetActive();
    void SetLittleEndian(bool);
    bool GetLittleEndian();
    bool QEndian();
    void SetUnicode(bool);
    bool GetUnicode();
    bool GetHasGroups();
    void SetHasGroups(bool);
    float GetPercentage();
    void CopyToBackup();
    static void DeleteFileList(void*);
    TESFile* GetParentTESFile();
    TESFile* GetThreadSafeRootFile();
    void CopyThreadSafeParentAuxBuffer();
    void ClearAuxBuffer();
    void SetFile(BSFile*);
    BSFile* GetFile();
    int GetLastFileError();
    FormRecordHeader* GetFormData();
    unsigned int GetID();
    unsigned short GetFormVersion();
    bool TakeOwnership();
    static bool TakeFileOwnership(char*);
    static unsigned short GetFileFormVersion();
    void SetCached(bool);
    void SetCaching(bool);
    void ResetWithCachedFile();
    bool GetCached();
    bool GetCaching();
    unsigned int GetMasterCount();
    unsigned int GetFlags();
    unsigned int GetFNVVersionInfo();
    void InitEndian();
    bool IsCurrentFormCompressed();
    void DecompressCurrentForm();
    unsigned int GetDecompressedBufferSize();
    char* GetDecompressedBuffer();
    void ReleaseDecompressedBuffer();
    void ClearDecompressedBuffer();
    void ClearDecompressedFormBuffer();
    bool ReadFormHeader();
    bool ReadChunkHeader();
    BSSimpleList<_ULARGE_INTEGER*>* GetMasterDataList();
    void ClearMasterLists();
    void ClearThreadSafeFiles();
    void SetThreadSafeParent(TESFile*);
    TESFile* GetFileForThread(unsigned int);
    int EasyWrite(void*, unsigned int);
    void MoveToFilePosition(int);
    bool IsTempIDLoadable(unsigned int, unsigned int);
    void SetTempIDOwner(bool);
    bool GetTempIDOwner();
    static void SetTempIDOwnerForForm(unsigned int, TESFile*);
    static bool GetTempIDCanLoadFromFile(unsigned int, TESFile*);
    static TESFile* GetTempIDOwnerFile(unsigned int);
    void ClearTempIDOwner();

    bool FindForm(TESForm*);
    unsigned int GetIndexCount();
    const char* GetIndexName(unsigned int);
    BSSimpleList<TESFile*>* GetMasterList_00464df0();
    TESForm* TESMain_GetThread();
    void Func004720d0();
    bool Func00470c70(int, int);
    bool NextForm_00472150(bool);
    bool Func00473660();
    unsigned char Func00473250();
    int TESFile_GetTESChunk();
    bool Func00472890(void*, unsigned int);
    bool Func004726f0();
    void Func00471130();

    TESFile(const char* path, const char* filename, NiFile::OpenMode openMode);
    ~TESFile();
    bool IsEndianConversionRequired();
    bool GenIndexTable(BSSimpleList<TESFile*>* files, bool unknown);
    bool OpenTESFile(NiFile::OpenMode accessmode, bool lock);
    bool OpenTES(const char* path, const char* filename, NiFile::OpenMode openMode, bool closeOverride);
    void InitializeComponent();
    unsigned int GetChunkID();
    bool GetChunkData();
    bool GetNextChunk();
    bool GetByteAt428();
    Flt& GetField418();
    static char* IsTempIDLoadable();
    const char* GetName();
    void GetZeroByte();
    void LoadFormAndUpdateFlag();
    void SetField3DC(float);
    unsigned int GetFormID();
    TESRecordHeader* GetRecordHeader();
    void SetBufferSize(int);
    bool HasMasterFileChanged();
    unsigned int GetFieldAt3E0();
    void ReadTESInfo(TESForm*, CHUNK_ID);
    TESFile* GetFileByIndex(unsigned int);
    unsigned int GetField25C();
};

class TESRegionData
{
public:
    bool bOverride;
    bool m_bHasRegionData;
    unsigned char m_ucRegionPriority;
    unsigned char layoutPadding7[1];

    TESRegionData();
    TESRegionData(const TESRegionData& other);
    virtual ~TESRegionData();
    virtual void Save();
    virtual bool ApplyEntry(RegionDataEntry* apBase);
    virtual void SetForm(TESForm* apForm);
    virtual REGION_DATA_ID GetType();
    virtual TESRegionData* Clone();
    virtual TESRegionData* CopyFrom(const TESRegionData* apSrc);
    virtual void SetFromData(const TESRegionData* apSrc, unsigned int auFlags);
    virtual bool IsValid();

    bool ApplyEntry(BaseRegionData* data);
    void Initialize(TESRegion* region);
    bool SetPriority(unsigned char priority);
    BSSimpleList<RegionSound*>* GetOffsetC();
};

class BaseFormComponent
{
public:
    BaseFormComponent();

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);
};

class TESTexture : public BaseFormComponent
{
public:
    TESTexture();
    ~TESTexture();

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);
    virtual unsigned int GetTexturePathLength();
    virtual char* NormalizeTextureFilePath(void* result);
    virtual char* GetTextureResourcePath();

    void InitializeComponent();
    void ClearComponent();
    void BaseFormRecord(BaseFormComponent* component);
    bool IsEqualToBase(BaseFormComponent* component);
    bool TESTexture_CompareComponent(TESTexture* component);
    void Save(int chunk);

    static unsigned int GetTextureNameLength(TESForm* form);
    unsigned int GetTextureNameLength();
    static char* GetTextureResourceName(TESForm* apObj, TESObjectREFR* apRef);
    char* GetTextureResourceName();
    void AssignTextureName(char* apFullName);
    void AssignTextureName(const char* apFullName);
    void SetTexture(const char* apFullName);

    static void NormalizeTextureFilePath(char* path, char* output);
    static char* NormalizeTextureFilePath(void* result, char* path);
    static const char* GetAsNormalFile(BSStringT<char>& aOutFilename, const char* apTextureName);
    static const char* NormalizeTextureFilePath(BSS& result, const char* path);
    template <class StringType>
    static const char* NormalizeTextureFilePath(StringType& result, const char* path);
    static char* NormalFileToRegularFile(void* result, char* path);
    char* GetRegularTextureFilePath(void* result);
    static void GetRegularTextureFilePath(char* path, char* output);
    static char* GetRegularTextureFilePath(void* result, char* path);
    static void GetAsSkinFile(char* apTextureName, char* apSkinTextureName);
    static void GetAsSkinFile(const char* apTextureName, char* apSkinTextureName);
    static bool IsTextureChunk(int chunk);
    static void ReadTextureData(TESTexture* apTexture, TESFile* apFile);
    static char* GetMessageIconName(TESForm* form, TESObjectREFR* reference);

    unsigned long Unk_04();
    void GetNormalMap(String* result);
    char* GetPathRoot();

    BSStringT<char> FullNameComponent;
};

class TESRegionDataLandscape : public TESRegionData
{
public:
    TESTexture* m_pLandscapeTexture;

    TESRegionDataLandscape();
    virtual ~TESRegionDataLandscape();
    virtual bool LoadRegionDataLandscape(TESFile* apFile);
    virtual void vf10();
    virtual void vf11();
};


void* operator new(size_t) throw();
void operator delete(void*);

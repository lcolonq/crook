/*** Autogenerated by WIDL 10.0 from /build/wine-10.0/include/transact.idl - Do not edit ***/

#ifdef _WIN32
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif
#include <rpc.h>
#include <rpcndr.h>
#endif

#ifndef COM_NO_WINDOWS_H
#include <windows.h>
#include <ole2.h>
#endif

#ifndef __transact_h__
#define __transact_h__

/* Forward declarations */

#ifndef __ITransaction_FWD_DEFINED__
#define __ITransaction_FWD_DEFINED__
typedef interface ITransaction ITransaction;
#ifdef __cplusplus
interface ITransaction;
#endif /* __cplusplus */
#endif

#ifndef __ITransactionCloner_FWD_DEFINED__
#define __ITransactionCloner_FWD_DEFINED__
typedef interface ITransactionCloner ITransactionCloner;
#ifdef __cplusplus
interface ITransactionCloner;
#endif /* __cplusplus */
#endif

#ifndef __ITransaction2_FWD_DEFINED__
#define __ITransaction2_FWD_DEFINED__
typedef interface ITransaction2 ITransaction2;
#ifdef __cplusplus
interface ITransaction2;
#endif /* __cplusplus */
#endif

#ifndef __ITransactionDispenser_FWD_DEFINED__
#define __ITransactionDispenser_FWD_DEFINED__
typedef interface ITransactionDispenser ITransactionDispenser;
#ifdef __cplusplus
interface ITransactionDispenser;
#endif /* __cplusplus */
#endif

#ifndef __ITransactionOptions_FWD_DEFINED__
#define __ITransactionOptions_FWD_DEFINED__
typedef interface ITransactionOptions ITransactionOptions;
#ifdef __cplusplus
interface ITransactionOptions;
#endif /* __cplusplus */
#endif

#ifndef __ITransactionOutcomeEvents_FWD_DEFINED__
#define __ITransactionOutcomeEvents_FWD_DEFINED__
typedef interface ITransactionOutcomeEvents ITransactionOutcomeEvents;
#ifdef __cplusplus
interface ITransactionOutcomeEvents;
#endif /* __cplusplus */
#endif

#ifndef __ITmNodeName_FWD_DEFINED__
#define __ITmNodeName_FWD_DEFINED__
typedef interface ITmNodeName ITmNodeName;
#ifdef __cplusplus
interface ITmNodeName;
#endif /* __cplusplus */
#endif

/* Headers for imported files */

#include <unknwn.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <winerror.h>
#ifndef __ITransaction_FWD_DEFINED__
#define __ITransaction_FWD_DEFINED__
typedef interface ITransaction ITransaction;
#ifdef __cplusplus
interface ITransaction;
#endif /* __cplusplus */
#endif

#ifndef __ITransactionCloner_FWD_DEFINED__
#define __ITransactionCloner_FWD_DEFINED__
typedef interface ITransactionCloner ITransactionCloner;
#ifdef __cplusplus
interface ITransactionCloner;
#endif /* __cplusplus */
#endif

#ifndef __ITransaction2_FWD_DEFINED__
#define __ITransaction2_FWD_DEFINED__
typedef interface ITransaction2 ITransaction2;
#ifdef __cplusplus
interface ITransaction2;
#endif /* __cplusplus */
#endif

#ifndef __ITransactionDispenser_FWD_DEFINED__
#define __ITransactionDispenser_FWD_DEFINED__
typedef interface ITransactionDispenser ITransactionDispenser;
#ifdef __cplusplus
interface ITransactionDispenser;
#endif /* __cplusplus */
#endif

#ifndef __ITransactionOptions_FWD_DEFINED__
#define __ITransactionOptions_FWD_DEFINED__
typedef interface ITransactionOptions ITransactionOptions;
#ifdef __cplusplus
interface ITransactionOptions;
#endif /* __cplusplus */
#endif

#ifndef __ITransactionOutcomeEvents_FWD_DEFINED__
#define __ITransactionOutcomeEvents_FWD_DEFINED__
typedef interface ITransactionOutcomeEvents ITransactionOutcomeEvents;
#ifdef __cplusplus
interface ITransactionOutcomeEvents;
#endif /* __cplusplus */
#endif

#ifndef __ITmNodeName_FWD_DEFINED__
#define __ITmNodeName_FWD_DEFINED__
typedef interface ITmNodeName ITmNodeName;
#ifdef __cplusplus
interface ITmNodeName;
#endif /* __cplusplus */
#endif

typedef struct BOID {
    byte rgb[16];
} BOID;
#ifndef MAX_TRAN_DESC_DEFINED
#define MAX_TRAN_DESC_DEFINED
typedef enum TX_MISC_CONSTANTS {
    MAX_TRAN_DESC = 40
} TX_MISC_CONSTANTS;
#endif
typedef BOID XACTUOW;
typedef LONG ISOLEVEL;
typedef enum ISOLATIONLEVEL {
    ISOLATIONLEVEL_UNSPECIFIED = 0xffffffff,
    ISOLATIONLEVEL_CHAOS = 0x10,
    ISOLATIONLEVEL_READUNCOMMITTED = 0x100,
    ISOLATIONLEVEL_BROWSE = 0x100,
    ISOLATIONLEVEL_CURSORSTABILITY = 0x1000,
    ISOLATIONLEVEL_READCOMMITTED = 0x1000,
    ISOLATIONLEVEL_REPEATABLEREAD = 0x10000,
    ISOLATIONLEVEL_SERIALIZABLE = 0x100000,
    ISOLATIONLEVEL_ISOLATED = 0x100000
} ISOLATIONLEVEL;
typedef struct XACTTRANSINFO {
    XACTUOW uow;
    ISOLEVEL isoLevel;
    ULONG isoFlags;
    DWORD grfTCSupported;
    DWORD grfRMSupported;
    DWORD grfTCSupportedRetaining;
    DWORD grfRMSupportedRetaining;
} XACTTRANSINFO;
typedef struct XACTSTATS {
    ULONG cOpen;
    ULONG cCommitting;
    ULONG cCommitted;
    ULONG cAborting;
    ULONG cAborted;
    ULONG cInDoubt;
    ULONG cHeuristicDecision;
    FILETIME timeTransactionsUp;
} XACTSTATS;
typedef enum ISOFLAG {
    ISOFLAG_RETAIN_COMMIT_DC = 1,
    ISOFLAG_RETAIN_COMMIT = 2,
    ISOFLAG_RETAIN_COMMIT_NO = 3,
    ISOFLAG_RETAIN_ABORT_DC = 4,
    ISOFLAG_RETAIN_ABORT = 8,
    ISOFLAG_RETAIN_ABORT_NO = 12,
    ISOFLAG_RETAIN_DONTCARE = ISOFLAG_RETAIN_COMMIT_DC | ISOFLAG_RETAIN_ABORT_DC,
    ISOFLAG_RETAIN_BOTH = ISOFLAG_RETAIN_COMMIT | ISOFLAG_RETAIN_ABORT,
    ISOFLAG_RETAIN_NONE = ISOFLAG_RETAIN_COMMIT_NO | ISOFLAG_RETAIN_ABORT_NO,
    ISOFLAG_OPTIMISTIC = 16,
    ISOFLAG_READONLY = 32
} ISOFLAG;
typedef enum XACTTC {
    XACTTC_NONE = 0,
    XACTTC_SYNC_PHASEONE = 1,
    XACTTC_SYNC_PHASETWO = 2,
    XACTTC_SYNC = 2,
    XACTTC_ASYNC_PHASEONE = 4,
    XACTTC_ASYNC = 4
} XACTTC;
typedef enum XACTRM {
    XACTRM_OPTIMISTICLASTWINS = 1,
    XACTRM_NOREADONLYPREPARES = 2
} XACTRM;
typedef enum XACTCONST {
    XACTCONST_TIMEOUTINFINITE = 0
} XACTCONST;
typedef enum XACTHEURISTIC {
    XACTHEURISTIC_ABORT = 1,
    XACTHEURISTIC_COMMIT = 2,
    XACTHEURISTIC_DAMAGE = 3,
    XACTHEURISTIC_DANGER = 4
} XACTHEURISTIC;
typedef enum XACTSTAT {
    XACTSTAT_NONE = 0,
    XACTSTAT_OPENNORMAL = 0x1,
    XACTSTAT_OPENREFUSED = 0x2,
    XACTSTAT_PREPARING = 0x4,
    XACTSTAT_PREPARED = 0x8,
    XACTSTAT_PREPARERETAINING = 0x10,
    XACTSTAT_PREPARERETAINED = 0x20,
    XACTSTAT_COMMITTING = 0x40,
    XACTSTAT_COMMITRETAINING = 0x80,
    XACTSTAT_ABORTING = 0x100,
    XACTSTAT_ABORTED = 0x200,
    XACTSTAT_COMMITTED = 0x400,
    XACTSTAT_HEURISTIC_ABORT = 0x800,
    XACTSTAT_HEURISTIC_COMMIT = 0x1000,
    XACTSTAT_HEURISTIC_DAMAGE = 0x2000,
    XACTSTAT_HEURISTIC_DANGER = 0x4000,
    XACTSTAT_FORCED_ABORT = 0x8000,
    XACTSTAT_FORCED_COMMIT = 0x10000,
    XACTSTAT_INDOUBT = 0x20000,
    XACTSTAT_CLOSED = 0x40000,
    XACTSTAT_OPEN = 0x3,
    XACTSTAT_NOTPREPARED = 0x7ffc3,
    XACTSTAT_ALL = 0x7ffff
} XACTSTAT;
typedef struct XACTOPT {
    ULONG ulTimeout;
    char szDescription[40];
} XACTOPT;
/*****************************************************************************
 * ITransaction interface
 */
#ifndef __ITransaction_INTERFACE_DEFINED__
#define __ITransaction_INTERFACE_DEFINED__

DEFINE_GUID(IID_ITransaction, 0x0fb15084, 0xaf41, 0x11ce, 0xbd,0x2b, 0x20,0x4c,0x4f,0x4f,0x50,0x20);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("0fb15084-af41-11ce-bd2b-204c4f4f5020")
ITransaction : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE Commit(
        BOOL fRetaining,
        DWORD grfTC,
        DWORD grfRM) = 0;

    virtual HRESULT STDMETHODCALLTYPE Abort(
        BOID *pboidReason,
        BOOL fRetaining,
        BOOL fAsync) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetTransactionInfo(
        XACTTRANSINFO *pinfo) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(ITransaction, 0x0fb15084, 0xaf41, 0x11ce, 0xbd,0x2b, 0x20,0x4c,0x4f,0x4f,0x50,0x20)
#endif
#else
typedef struct ITransactionVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        ITransaction *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        ITransaction *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        ITransaction *This);

    /*** ITransaction methods ***/
    HRESULT (STDMETHODCALLTYPE *Commit)(
        ITransaction *This,
        BOOL fRetaining,
        DWORD grfTC,
        DWORD grfRM);

    HRESULT (STDMETHODCALLTYPE *Abort)(
        ITransaction *This,
        BOID *pboidReason,
        BOOL fRetaining,
        BOOL fAsync);

    HRESULT (STDMETHODCALLTYPE *GetTransactionInfo)(
        ITransaction *This,
        XACTTRANSINFO *pinfo);

    END_INTERFACE
} ITransactionVtbl;

interface ITransaction {
    CONST_VTBL ITransactionVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define ITransaction_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ITransaction_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ITransaction_Release(This) (This)->lpVtbl->Release(This)
/*** ITransaction methods ***/
#define ITransaction_Commit(This,fRetaining,grfTC,grfRM) (This)->lpVtbl->Commit(This,fRetaining,grfTC,grfRM)
#define ITransaction_Abort(This,pboidReason,fRetaining,fAsync) (This)->lpVtbl->Abort(This,pboidReason,fRetaining,fAsync)
#define ITransaction_GetTransactionInfo(This,pinfo) (This)->lpVtbl->GetTransactionInfo(This,pinfo)
#else
/*** IUnknown methods ***/
static inline HRESULT ITransaction_QueryInterface(ITransaction* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static inline ULONG ITransaction_AddRef(ITransaction* This) {
    return This->lpVtbl->AddRef(This);
}
static inline ULONG ITransaction_Release(ITransaction* This) {
    return This->lpVtbl->Release(This);
}
/*** ITransaction methods ***/
static inline HRESULT ITransaction_Commit(ITransaction* This,BOOL fRetaining,DWORD grfTC,DWORD grfRM) {
    return This->lpVtbl->Commit(This,fRetaining,grfTC,grfRM);
}
static inline HRESULT ITransaction_Abort(ITransaction* This,BOID *pboidReason,BOOL fRetaining,BOOL fAsync) {
    return This->lpVtbl->Abort(This,pboidReason,fRetaining,fAsync);
}
static inline HRESULT ITransaction_GetTransactionInfo(ITransaction* This,XACTTRANSINFO *pinfo) {
    return This->lpVtbl->GetTransactionInfo(This,pinfo);
}
#endif
#endif

#endif


#endif  /* __ITransaction_INTERFACE_DEFINED__ */

/*****************************************************************************
 * ITransactionCloner interface
 */
#ifndef __ITransactionCloner_INTERFACE_DEFINED__
#define __ITransactionCloner_INTERFACE_DEFINED__

DEFINE_GUID(IID_ITransactionCloner, 0x02656950, 0x2152, 0x11d0, 0x94,0x4c, 0x00,0xa0,0xc9,0x05,0x41,0x6e);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("02656950-2152-11d0-944c-00a0c905416e")
ITransactionCloner : public ITransaction
{
    virtual HRESULT STDMETHODCALLTYPE CloneWithCommitDisabled(
        ITransaction **ppITransaction) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(ITransactionCloner, 0x02656950, 0x2152, 0x11d0, 0x94,0x4c, 0x00,0xa0,0xc9,0x05,0x41,0x6e)
#endif
#else
typedef struct ITransactionClonerVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        ITransactionCloner *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        ITransactionCloner *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        ITransactionCloner *This);

    /*** ITransaction methods ***/
    HRESULT (STDMETHODCALLTYPE *Commit)(
        ITransactionCloner *This,
        BOOL fRetaining,
        DWORD grfTC,
        DWORD grfRM);

    HRESULT (STDMETHODCALLTYPE *Abort)(
        ITransactionCloner *This,
        BOID *pboidReason,
        BOOL fRetaining,
        BOOL fAsync);

    HRESULT (STDMETHODCALLTYPE *GetTransactionInfo)(
        ITransactionCloner *This,
        XACTTRANSINFO *pinfo);

    /*** ITransactionCloner methods ***/
    HRESULT (STDMETHODCALLTYPE *CloneWithCommitDisabled)(
        ITransactionCloner *This,
        ITransaction **ppITransaction);

    END_INTERFACE
} ITransactionClonerVtbl;

interface ITransactionCloner {
    CONST_VTBL ITransactionClonerVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define ITransactionCloner_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ITransactionCloner_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ITransactionCloner_Release(This) (This)->lpVtbl->Release(This)
/*** ITransaction methods ***/
#define ITransactionCloner_Commit(This,fRetaining,grfTC,grfRM) (This)->lpVtbl->Commit(This,fRetaining,grfTC,grfRM)
#define ITransactionCloner_Abort(This,pboidReason,fRetaining,fAsync) (This)->lpVtbl->Abort(This,pboidReason,fRetaining,fAsync)
#define ITransactionCloner_GetTransactionInfo(This,pinfo) (This)->lpVtbl->GetTransactionInfo(This,pinfo)
/*** ITransactionCloner methods ***/
#define ITransactionCloner_CloneWithCommitDisabled(This,ppITransaction) (This)->lpVtbl->CloneWithCommitDisabled(This,ppITransaction)
#else
/*** IUnknown methods ***/
static inline HRESULT ITransactionCloner_QueryInterface(ITransactionCloner* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static inline ULONG ITransactionCloner_AddRef(ITransactionCloner* This) {
    return This->lpVtbl->AddRef(This);
}
static inline ULONG ITransactionCloner_Release(ITransactionCloner* This) {
    return This->lpVtbl->Release(This);
}
/*** ITransaction methods ***/
static inline HRESULT ITransactionCloner_Commit(ITransactionCloner* This,BOOL fRetaining,DWORD grfTC,DWORD grfRM) {
    return This->lpVtbl->Commit(This,fRetaining,grfTC,grfRM);
}
static inline HRESULT ITransactionCloner_Abort(ITransactionCloner* This,BOID *pboidReason,BOOL fRetaining,BOOL fAsync) {
    return This->lpVtbl->Abort(This,pboidReason,fRetaining,fAsync);
}
static inline HRESULT ITransactionCloner_GetTransactionInfo(ITransactionCloner* This,XACTTRANSINFO *pinfo) {
    return This->lpVtbl->GetTransactionInfo(This,pinfo);
}
/*** ITransactionCloner methods ***/
static inline HRESULT ITransactionCloner_CloneWithCommitDisabled(ITransactionCloner* This,ITransaction **ppITransaction) {
    return This->lpVtbl->CloneWithCommitDisabled(This,ppITransaction);
}
#endif
#endif

#endif


#endif  /* __ITransactionCloner_INTERFACE_DEFINED__ */

/*****************************************************************************
 * ITransaction2 interface
 */
#ifndef __ITransaction2_INTERFACE_DEFINED__
#define __ITransaction2_INTERFACE_DEFINED__

DEFINE_GUID(IID_ITransaction2, 0x34021548, 0x0065, 0x11d3, 0xba,0xc1, 0x00,0xc0,0x4f,0x79,0x7b,0xe2);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("34021548-0065-11d3-bac1-00c04f797be2")
ITransaction2 : public ITransactionCloner
{
    virtual HRESULT STDMETHODCALLTYPE GetTransactionInfo2(
        XACTTRANSINFO *pinfo) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(ITransaction2, 0x34021548, 0x0065, 0x11d3, 0xba,0xc1, 0x00,0xc0,0x4f,0x79,0x7b,0xe2)
#endif
#else
typedef struct ITransaction2Vtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        ITransaction2 *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        ITransaction2 *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        ITransaction2 *This);

    /*** ITransaction methods ***/
    HRESULT (STDMETHODCALLTYPE *Commit)(
        ITransaction2 *This,
        BOOL fRetaining,
        DWORD grfTC,
        DWORD grfRM);

    HRESULT (STDMETHODCALLTYPE *Abort)(
        ITransaction2 *This,
        BOID *pboidReason,
        BOOL fRetaining,
        BOOL fAsync);

    HRESULT (STDMETHODCALLTYPE *GetTransactionInfo)(
        ITransaction2 *This,
        XACTTRANSINFO *pinfo);

    /*** ITransactionCloner methods ***/
    HRESULT (STDMETHODCALLTYPE *CloneWithCommitDisabled)(
        ITransaction2 *This,
        ITransaction **ppITransaction);

    /*** ITransaction2 methods ***/
    HRESULT (STDMETHODCALLTYPE *GetTransactionInfo2)(
        ITransaction2 *This,
        XACTTRANSINFO *pinfo);

    END_INTERFACE
} ITransaction2Vtbl;

interface ITransaction2 {
    CONST_VTBL ITransaction2Vtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define ITransaction2_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ITransaction2_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ITransaction2_Release(This) (This)->lpVtbl->Release(This)
/*** ITransaction methods ***/
#define ITransaction2_Commit(This,fRetaining,grfTC,grfRM) (This)->lpVtbl->Commit(This,fRetaining,grfTC,grfRM)
#define ITransaction2_Abort(This,pboidReason,fRetaining,fAsync) (This)->lpVtbl->Abort(This,pboidReason,fRetaining,fAsync)
#define ITransaction2_GetTransactionInfo(This,pinfo) (This)->lpVtbl->GetTransactionInfo(This,pinfo)
/*** ITransactionCloner methods ***/
#define ITransaction2_CloneWithCommitDisabled(This,ppITransaction) (This)->lpVtbl->CloneWithCommitDisabled(This,ppITransaction)
/*** ITransaction2 methods ***/
#define ITransaction2_GetTransactionInfo2(This,pinfo) (This)->lpVtbl->GetTransactionInfo2(This,pinfo)
#else
/*** IUnknown methods ***/
static inline HRESULT ITransaction2_QueryInterface(ITransaction2* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static inline ULONG ITransaction2_AddRef(ITransaction2* This) {
    return This->lpVtbl->AddRef(This);
}
static inline ULONG ITransaction2_Release(ITransaction2* This) {
    return This->lpVtbl->Release(This);
}
/*** ITransaction methods ***/
static inline HRESULT ITransaction2_Commit(ITransaction2* This,BOOL fRetaining,DWORD grfTC,DWORD grfRM) {
    return This->lpVtbl->Commit(This,fRetaining,grfTC,grfRM);
}
static inline HRESULT ITransaction2_Abort(ITransaction2* This,BOID *pboidReason,BOOL fRetaining,BOOL fAsync) {
    return This->lpVtbl->Abort(This,pboidReason,fRetaining,fAsync);
}
static inline HRESULT ITransaction2_GetTransactionInfo(ITransaction2* This,XACTTRANSINFO *pinfo) {
    return This->lpVtbl->GetTransactionInfo(This,pinfo);
}
/*** ITransactionCloner methods ***/
static inline HRESULT ITransaction2_CloneWithCommitDisabled(ITransaction2* This,ITransaction **ppITransaction) {
    return This->lpVtbl->CloneWithCommitDisabled(This,ppITransaction);
}
/*** ITransaction2 methods ***/
static inline HRESULT ITransaction2_GetTransactionInfo2(ITransaction2* This,XACTTRANSINFO *pinfo) {
    return This->lpVtbl->GetTransactionInfo2(This,pinfo);
}
#endif
#endif

#endif


#endif  /* __ITransaction2_INTERFACE_DEFINED__ */

/*****************************************************************************
 * ITransactionDispenser interface
 */
#ifndef __ITransactionDispenser_INTERFACE_DEFINED__
#define __ITransactionDispenser_INTERFACE_DEFINED__

DEFINE_GUID(IID_ITransactionDispenser, 0x3a6ad9e1, 0x23b9, 0x11cf, 0xad,0x60, 0x00,0xaa,0x00,0xa7,0x4c,0xcd);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("3a6ad9e1-23b9-11cf-ad60-00aa00a74ccd")
ITransactionDispenser : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE GetOptionsObject(
        ITransactionOptions **ppOptions) = 0;

    virtual HRESULT STDMETHODCALLTYPE BeginTransaction(
        IUnknown *punkOuter,
        ISOLEVEL isoLevel,
        ULONG isoFlags,
        ITransactionOptions *pOptions,
        ITransaction **ppTransaction) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(ITransactionDispenser, 0x3a6ad9e1, 0x23b9, 0x11cf, 0xad,0x60, 0x00,0xaa,0x00,0xa7,0x4c,0xcd)
#endif
#else
typedef struct ITransactionDispenserVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        ITransactionDispenser *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        ITransactionDispenser *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        ITransactionDispenser *This);

    /*** ITransactionDispenser methods ***/
    HRESULT (STDMETHODCALLTYPE *GetOptionsObject)(
        ITransactionDispenser *This,
        ITransactionOptions **ppOptions);

    HRESULT (STDMETHODCALLTYPE *BeginTransaction)(
        ITransactionDispenser *This,
        IUnknown *punkOuter,
        ISOLEVEL isoLevel,
        ULONG isoFlags,
        ITransactionOptions *pOptions,
        ITransaction **ppTransaction);

    END_INTERFACE
} ITransactionDispenserVtbl;

interface ITransactionDispenser {
    CONST_VTBL ITransactionDispenserVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define ITransactionDispenser_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ITransactionDispenser_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ITransactionDispenser_Release(This) (This)->lpVtbl->Release(This)
/*** ITransactionDispenser methods ***/
#define ITransactionDispenser_GetOptionsObject(This,ppOptions) (This)->lpVtbl->GetOptionsObject(This,ppOptions)
#define ITransactionDispenser_BeginTransaction(This,punkOuter,isoLevel,isoFlags,pOptions,ppTransaction) (This)->lpVtbl->BeginTransaction(This,punkOuter,isoLevel,isoFlags,pOptions,ppTransaction)
#else
/*** IUnknown methods ***/
static inline HRESULT ITransactionDispenser_QueryInterface(ITransactionDispenser* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static inline ULONG ITransactionDispenser_AddRef(ITransactionDispenser* This) {
    return This->lpVtbl->AddRef(This);
}
static inline ULONG ITransactionDispenser_Release(ITransactionDispenser* This) {
    return This->lpVtbl->Release(This);
}
/*** ITransactionDispenser methods ***/
static inline HRESULT ITransactionDispenser_GetOptionsObject(ITransactionDispenser* This,ITransactionOptions **ppOptions) {
    return This->lpVtbl->GetOptionsObject(This,ppOptions);
}
static inline HRESULT ITransactionDispenser_BeginTransaction(ITransactionDispenser* This,IUnknown *punkOuter,ISOLEVEL isoLevel,ULONG isoFlags,ITransactionOptions *pOptions,ITransaction **ppTransaction) {
    return This->lpVtbl->BeginTransaction(This,punkOuter,isoLevel,isoFlags,pOptions,ppTransaction);
}
#endif
#endif

#endif


#endif  /* __ITransactionDispenser_INTERFACE_DEFINED__ */

/*****************************************************************************
 * ITransactionOptions interface
 */
#ifndef __ITransactionOptions_INTERFACE_DEFINED__
#define __ITransactionOptions_INTERFACE_DEFINED__

DEFINE_GUID(IID_ITransactionOptions, 0x3a6ad9e0, 0x23b9, 0x11cf, 0xad,0x60, 0x00,0xaa,0x00,0xa7,0x4c,0xcd);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("3a6ad9e0-23b9-11cf-ad60-00aa00a74ccd")
ITransactionOptions : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE SetOptions(
        XACTOPT *pOptions) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetOptions(
        XACTOPT *pOptions) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(ITransactionOptions, 0x3a6ad9e0, 0x23b9, 0x11cf, 0xad,0x60, 0x00,0xaa,0x00,0xa7,0x4c,0xcd)
#endif
#else
typedef struct ITransactionOptionsVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        ITransactionOptions *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        ITransactionOptions *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        ITransactionOptions *This);

    /*** ITransactionOptions methods ***/
    HRESULT (STDMETHODCALLTYPE *SetOptions)(
        ITransactionOptions *This,
        XACTOPT *pOptions);

    HRESULT (STDMETHODCALLTYPE *GetOptions)(
        ITransactionOptions *This,
        XACTOPT *pOptions);

    END_INTERFACE
} ITransactionOptionsVtbl;

interface ITransactionOptions {
    CONST_VTBL ITransactionOptionsVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define ITransactionOptions_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ITransactionOptions_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ITransactionOptions_Release(This) (This)->lpVtbl->Release(This)
/*** ITransactionOptions methods ***/
#define ITransactionOptions_SetOptions(This,pOptions) (This)->lpVtbl->SetOptions(This,pOptions)
#define ITransactionOptions_GetOptions(This,pOptions) (This)->lpVtbl->GetOptions(This,pOptions)
#else
/*** IUnknown methods ***/
static inline HRESULT ITransactionOptions_QueryInterface(ITransactionOptions* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static inline ULONG ITransactionOptions_AddRef(ITransactionOptions* This) {
    return This->lpVtbl->AddRef(This);
}
static inline ULONG ITransactionOptions_Release(ITransactionOptions* This) {
    return This->lpVtbl->Release(This);
}
/*** ITransactionOptions methods ***/
static inline HRESULT ITransactionOptions_SetOptions(ITransactionOptions* This,XACTOPT *pOptions) {
    return This->lpVtbl->SetOptions(This,pOptions);
}
static inline HRESULT ITransactionOptions_GetOptions(ITransactionOptions* This,XACTOPT *pOptions) {
    return This->lpVtbl->GetOptions(This,pOptions);
}
#endif
#endif

#endif


#endif  /* __ITransactionOptions_INTERFACE_DEFINED__ */

/*****************************************************************************
 * ITransactionOutcomeEvents interface
 */
#ifndef __ITransactionOutcomeEvents_INTERFACE_DEFINED__
#define __ITransactionOutcomeEvents_INTERFACE_DEFINED__

DEFINE_GUID(IID_ITransactionOutcomeEvents, 0x3a6ad9e2, 0x23b9, 0x11cf, 0xad,0x60, 0x00,0xaa,0x00,0xa7,0x4c,0xcd);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("3a6ad9e2-23b9-11cf-ad60-00aa00a74ccd")
ITransactionOutcomeEvents : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE Committed(
        BOOL fRetaining,
        XACTUOW *pNewUOW,
        HRESULT hr) = 0;

    virtual HRESULT STDMETHODCALLTYPE Aborted(
        BOID *pboidReason,
        BOOL fRetaining,
        XACTUOW *pNewUOW,
        HRESULT hr) = 0;

    virtual HRESULT STDMETHODCALLTYPE HeuristicDecision(
        DWORD dwDecision,
        BOID *pboidReason,
        HRESULT hr) = 0;

    virtual HRESULT STDMETHODCALLTYPE Indoubt(
        ) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(ITransactionOutcomeEvents, 0x3a6ad9e2, 0x23b9, 0x11cf, 0xad,0x60, 0x00,0xaa,0x00,0xa7,0x4c,0xcd)
#endif
#else
typedef struct ITransactionOutcomeEventsVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        ITransactionOutcomeEvents *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        ITransactionOutcomeEvents *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        ITransactionOutcomeEvents *This);

    /*** ITransactionOutcomeEvents methods ***/
    HRESULT (STDMETHODCALLTYPE *Committed)(
        ITransactionOutcomeEvents *This,
        BOOL fRetaining,
        XACTUOW *pNewUOW,
        HRESULT hr);

    HRESULT (STDMETHODCALLTYPE *Aborted)(
        ITransactionOutcomeEvents *This,
        BOID *pboidReason,
        BOOL fRetaining,
        XACTUOW *pNewUOW,
        HRESULT hr);

    HRESULT (STDMETHODCALLTYPE *HeuristicDecision)(
        ITransactionOutcomeEvents *This,
        DWORD dwDecision,
        BOID *pboidReason,
        HRESULT hr);

    HRESULT (STDMETHODCALLTYPE *Indoubt)(
        ITransactionOutcomeEvents *This);

    END_INTERFACE
} ITransactionOutcomeEventsVtbl;

interface ITransactionOutcomeEvents {
    CONST_VTBL ITransactionOutcomeEventsVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define ITransactionOutcomeEvents_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ITransactionOutcomeEvents_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ITransactionOutcomeEvents_Release(This) (This)->lpVtbl->Release(This)
/*** ITransactionOutcomeEvents methods ***/
#define ITransactionOutcomeEvents_Committed(This,fRetaining,pNewUOW,hr) (This)->lpVtbl->Committed(This,fRetaining,pNewUOW,hr)
#define ITransactionOutcomeEvents_Aborted(This,pboidReason,fRetaining,pNewUOW,hr) (This)->lpVtbl->Aborted(This,pboidReason,fRetaining,pNewUOW,hr)
#define ITransactionOutcomeEvents_HeuristicDecision(This,dwDecision,pboidReason,hr) (This)->lpVtbl->HeuristicDecision(This,dwDecision,pboidReason,hr)
#define ITransactionOutcomeEvents_Indoubt(This) (This)->lpVtbl->Indoubt(This)
#else
/*** IUnknown methods ***/
static inline HRESULT ITransactionOutcomeEvents_QueryInterface(ITransactionOutcomeEvents* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static inline ULONG ITransactionOutcomeEvents_AddRef(ITransactionOutcomeEvents* This) {
    return This->lpVtbl->AddRef(This);
}
static inline ULONG ITransactionOutcomeEvents_Release(ITransactionOutcomeEvents* This) {
    return This->lpVtbl->Release(This);
}
/*** ITransactionOutcomeEvents methods ***/
static inline HRESULT ITransactionOutcomeEvents_Committed(ITransactionOutcomeEvents* This,BOOL fRetaining,XACTUOW *pNewUOW,HRESULT hr) {
    return This->lpVtbl->Committed(This,fRetaining,pNewUOW,hr);
}
static inline HRESULT ITransactionOutcomeEvents_Aborted(ITransactionOutcomeEvents* This,BOID *pboidReason,BOOL fRetaining,XACTUOW *pNewUOW,HRESULT hr) {
    return This->lpVtbl->Aborted(This,pboidReason,fRetaining,pNewUOW,hr);
}
static inline HRESULT ITransactionOutcomeEvents_HeuristicDecision(ITransactionOutcomeEvents* This,DWORD dwDecision,BOID *pboidReason,HRESULT hr) {
    return This->lpVtbl->HeuristicDecision(This,dwDecision,pboidReason,hr);
}
static inline HRESULT ITransactionOutcomeEvents_Indoubt(ITransactionOutcomeEvents* This) {
    return This->lpVtbl->Indoubt(This);
}
#endif
#endif

#endif


#endif  /* __ITransactionOutcomeEvents_INTERFACE_DEFINED__ */

/*****************************************************************************
 * ITmNodeName interface
 */
#ifndef __ITmNodeName_INTERFACE_DEFINED__
#define __ITmNodeName_INTERFACE_DEFINED__

DEFINE_GUID(IID_ITmNodeName, 0x30274f88, 0x6ee4, 0x474e, 0x9b,0x95, 0x78,0x07,0xbc,0x9e,0xf8,0xcf);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("30274f88-6ee4-474e-9b95-7807bc9ef8cf")
ITmNodeName : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE GetNodeNameSize(
        ULONG *pcbNodeNameSize) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetNodeName(
        ULONG cbNodeNameBufferSize,
        LPWSTR pNodeNameBuffer) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(ITmNodeName, 0x30274f88, 0x6ee4, 0x474e, 0x9b,0x95, 0x78,0x07,0xbc,0x9e,0xf8,0xcf)
#endif
#else
typedef struct ITmNodeNameVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        ITmNodeName *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        ITmNodeName *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        ITmNodeName *This);

    /*** ITmNodeName methods ***/
    HRESULT (STDMETHODCALLTYPE *GetNodeNameSize)(
        ITmNodeName *This,
        ULONG *pcbNodeNameSize);

    HRESULT (STDMETHODCALLTYPE *GetNodeName)(
        ITmNodeName *This,
        ULONG cbNodeNameBufferSize,
        LPWSTR pNodeNameBuffer);

    END_INTERFACE
} ITmNodeNameVtbl;

interface ITmNodeName {
    CONST_VTBL ITmNodeNameVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define ITmNodeName_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ITmNodeName_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ITmNodeName_Release(This) (This)->lpVtbl->Release(This)
/*** ITmNodeName methods ***/
#define ITmNodeName_GetNodeNameSize(This,pcbNodeNameSize) (This)->lpVtbl->GetNodeNameSize(This,pcbNodeNameSize)
#define ITmNodeName_GetNodeName(This,cbNodeNameBufferSize,pNodeNameBuffer) (This)->lpVtbl->GetNodeName(This,cbNodeNameBufferSize,pNodeNameBuffer)
#else
/*** IUnknown methods ***/
static inline HRESULT ITmNodeName_QueryInterface(ITmNodeName* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static inline ULONG ITmNodeName_AddRef(ITmNodeName* This) {
    return This->lpVtbl->AddRef(This);
}
static inline ULONG ITmNodeName_Release(ITmNodeName* This) {
    return This->lpVtbl->Release(This);
}
/*** ITmNodeName methods ***/
static inline HRESULT ITmNodeName_GetNodeNameSize(ITmNodeName* This,ULONG *pcbNodeNameSize) {
    return This->lpVtbl->GetNodeNameSize(This,pcbNodeNameSize);
}
static inline HRESULT ITmNodeName_GetNodeName(ITmNodeName* This,ULONG cbNodeNameBufferSize,LPWSTR pNodeNameBuffer) {
    return This->lpVtbl->GetNodeName(This,cbNodeNameBufferSize,pNodeNameBuffer);
}
#endif
#endif

#endif


#endif  /* __ITmNodeName_INTERFACE_DEFINED__ */

/* Begin additional prototypes for all interfaces */


/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __transact_h__ */

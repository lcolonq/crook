/*** Autogenerated by WIDL 10.0 from /build/wine-10.0/include/mimeinfo.idl - Do not edit ***/

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

#ifndef __mimeinfo_h__
#define __mimeinfo_h__

/* Forward declarations */

#ifndef __IMimeInfo_FWD_DEFINED__
#define __IMimeInfo_FWD_DEFINED__
typedef interface IMimeInfo IMimeInfo;
#ifdef __cplusplus
interface IMimeInfo;
#endif /* __cplusplus */
#endif

/* Headers for imported files */

#include <objidl.h>

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
 * IMimeInfo interface
 */
#ifndef __IMimeInfo_INTERFACE_DEFINED__
#define __IMimeInfo_INTERFACE_DEFINED__

typedef IMimeInfo *LPMIMEINFO;
DEFINE_GUID(IID_IMimeInfo, 0xf77459a0, 0xbf9a, 0x11cf, 0xba,0x4e, 0x00,0xc0,0x4f,0xd7,0x08,0x16);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("f77459a0-bf9a-11cf-ba4e-00c04fd70816")
IMimeInfo : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE GetMimeCLSIDMapping(
        UINT *pcTypes,
        LPCSTR **ppszTypes,
        CLSID **ppclsID) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IMimeInfo, 0xf77459a0, 0xbf9a, 0x11cf, 0xba,0x4e, 0x00,0xc0,0x4f,0xd7,0x08,0x16)
#endif
#else
typedef struct IMimeInfoVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IMimeInfo *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IMimeInfo *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IMimeInfo *This);

    /*** IMimeInfo methods ***/
    HRESULT (STDMETHODCALLTYPE *GetMimeCLSIDMapping)(
        IMimeInfo *This,
        UINT *pcTypes,
        LPCSTR **ppszTypes,
        CLSID **ppclsID);

    END_INTERFACE
} IMimeInfoVtbl;

interface IMimeInfo {
    CONST_VTBL IMimeInfoVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IMimeInfo_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMimeInfo_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMimeInfo_Release(This) (This)->lpVtbl->Release(This)
/*** IMimeInfo methods ***/
#define IMimeInfo_GetMimeCLSIDMapping(This,pcTypes,ppszTypes,ppclsID) (This)->lpVtbl->GetMimeCLSIDMapping(This,pcTypes,ppszTypes,ppclsID)
#else
/*** IUnknown methods ***/
static inline HRESULT IMimeInfo_QueryInterface(IMimeInfo* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static inline ULONG IMimeInfo_AddRef(IMimeInfo* This) {
    return This->lpVtbl->AddRef(This);
}
static inline ULONG IMimeInfo_Release(IMimeInfo* This) {
    return This->lpVtbl->Release(This);
}
/*** IMimeInfo methods ***/
static inline HRESULT IMimeInfo_GetMimeCLSIDMapping(IMimeInfo* This,UINT *pcTypes,LPCSTR **ppszTypes,CLSID **ppclsID) {
    return This->lpVtbl->GetMimeCLSIDMapping(This,pcTypes,ppszTypes,ppclsID);
}
#endif
#endif

#endif


#endif  /* __IMimeInfo_INTERFACE_DEFINED__ */

#define SID_IMimeInfo IID_IMimeInfo
/* Begin additional prototypes for all interfaces */


/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __mimeinfo_h__ */

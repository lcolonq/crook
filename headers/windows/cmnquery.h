/*** Autogenerated by WIDL 10.0 from /build/wine-10.0/include/cmnquery.idl - Do not edit ***/

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

#ifndef __cmnquery_h__
#define __cmnquery_h__

/* Forward declarations */

#ifndef __IPersistQuery_FWD_DEFINED__
#define __IPersistQuery_FWD_DEFINED__
typedef interface IPersistQuery IPersistQuery;
#ifdef __cplusplus
interface IPersistQuery;
#endif /* __cplusplus */
#endif

#ifndef __ICommonQuery_FWD_DEFINED__
#define __ICommonQuery_FWD_DEFINED__
typedef interface ICommonQuery ICommonQuery;
#ifdef __cplusplus
interface ICommonQuery;
#endif /* __cplusplus */
#endif

#ifndef __CommonQuery_FWD_DEFINED__
#define __CommonQuery_FWD_DEFINED__
#ifdef __cplusplus
typedef class CommonQuery CommonQuery;
#else
typedef struct CommonQuery CommonQuery;
#endif /* defined __cplusplus */
#endif /* defined __CommonQuery_FWD_DEFINED__ */

/* Headers for imported files */

#include <oaidl.h>

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
 * IPersistQuery interface
 */
#ifndef __IPersistQuery_INTERFACE_DEFINED__
#define __IPersistQuery_INTERFACE_DEFINED__

DEFINE_GUID(IID_IPersistQuery, 0x1a3114b8, 0xa62e, 0x11d0, 0xa6,0xc5, 0x00,0xa0,0xc9,0x06,0xaf,0x45);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("1a3114b8-a62e-11d0-a6c5-00a0c906af45")
IPersistQuery : public IPersist
{
    virtual HRESULT STDMETHODCALLTYPE WriteString(
        LPCWSTR section,
        LPCWSTR name,
        LPCWSTR value) = 0;

    virtual HRESULT STDMETHODCALLTYPE ReadString(
        LPCWSTR section,
        LPCWSTR name,
        LPWSTR buffer,
        INT buflen) = 0;

    virtual HRESULT STDMETHODCALLTYPE WriteInt(
        LPCWSTR section,
        LPCWSTR name,
        INT value) = 0;

    virtual HRESULT STDMETHODCALLTYPE ReadInt(
        LPCWSTR section,
        LPCWSTR name,
        INT *value) = 0;

    virtual HRESULT STDMETHODCALLTYPE WriteStruct(
        LPCWSTR section,
        LPCWSTR name,
        LPVOID value,
        DWORD size) = 0;

    virtual HRESULT STDMETHODCALLTYPE ReadStruct(
        LPCWSTR section,
        LPCWSTR name,
        LPVOID buffer,
        DWORD buflen) = 0;

    virtual HRESULT STDMETHODCALLTYPE Clear(
        ) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IPersistQuery, 0x1a3114b8, 0xa62e, 0x11d0, 0xa6,0xc5, 0x00,0xa0,0xc9,0x06,0xaf,0x45)
#endif
#else
typedef struct IPersistQueryVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IPersistQuery *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IPersistQuery *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IPersistQuery *This);

    /*** IPersist methods ***/
    HRESULT (STDMETHODCALLTYPE *GetClassID)(
        IPersistQuery *This,
        CLSID *pClassID);

    /*** IPersistQuery methods ***/
    HRESULT (STDMETHODCALLTYPE *WriteString)(
        IPersistQuery *This,
        LPCWSTR section,
        LPCWSTR name,
        LPCWSTR value);

    HRESULT (STDMETHODCALLTYPE *ReadString)(
        IPersistQuery *This,
        LPCWSTR section,
        LPCWSTR name,
        LPWSTR buffer,
        INT buflen);

    HRESULT (STDMETHODCALLTYPE *WriteInt)(
        IPersistQuery *This,
        LPCWSTR section,
        LPCWSTR name,
        INT value);

    HRESULT (STDMETHODCALLTYPE *ReadInt)(
        IPersistQuery *This,
        LPCWSTR section,
        LPCWSTR name,
        INT *value);

    HRESULT (STDMETHODCALLTYPE *WriteStruct)(
        IPersistQuery *This,
        LPCWSTR section,
        LPCWSTR name,
        LPVOID value,
        DWORD size);

    HRESULT (STDMETHODCALLTYPE *ReadStruct)(
        IPersistQuery *This,
        LPCWSTR section,
        LPCWSTR name,
        LPVOID buffer,
        DWORD buflen);

    HRESULT (STDMETHODCALLTYPE *Clear)(
        IPersistQuery *This);

    END_INTERFACE
} IPersistQueryVtbl;

interface IPersistQuery {
    CONST_VTBL IPersistQueryVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IPersistQuery_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IPersistQuery_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IPersistQuery_Release(This) (This)->lpVtbl->Release(This)
/*** IPersist methods ***/
#define IPersistQuery_GetClassID(This,pClassID) (This)->lpVtbl->GetClassID(This,pClassID)
/*** IPersistQuery methods ***/
#define IPersistQuery_WriteString(This,section,name,value) (This)->lpVtbl->WriteString(This,section,name,value)
#define IPersistQuery_ReadString(This,section,name,buffer,buflen) (This)->lpVtbl->ReadString(This,section,name,buffer,buflen)
#define IPersistQuery_WriteInt(This,section,name,value) (This)->lpVtbl->WriteInt(This,section,name,value)
#define IPersistQuery_ReadInt(This,section,name,value) (This)->lpVtbl->ReadInt(This,section,name,value)
#define IPersistQuery_WriteStruct(This,section,name,value,size) (This)->lpVtbl->WriteStruct(This,section,name,value,size)
#define IPersistQuery_ReadStruct(This,section,name,buffer,buflen) (This)->lpVtbl->ReadStruct(This,section,name,buffer,buflen)
#define IPersistQuery_Clear(This) (This)->lpVtbl->Clear(This)
#else
/*** IUnknown methods ***/
static inline HRESULT IPersistQuery_QueryInterface(IPersistQuery* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static inline ULONG IPersistQuery_AddRef(IPersistQuery* This) {
    return This->lpVtbl->AddRef(This);
}
static inline ULONG IPersistQuery_Release(IPersistQuery* This) {
    return This->lpVtbl->Release(This);
}
/*** IPersist methods ***/
static inline HRESULT IPersistQuery_GetClassID(IPersistQuery* This,CLSID *pClassID) {
    return This->lpVtbl->GetClassID(This,pClassID);
}
/*** IPersistQuery methods ***/
static inline HRESULT IPersistQuery_WriteString(IPersistQuery* This,LPCWSTR section,LPCWSTR name,LPCWSTR value) {
    return This->lpVtbl->WriteString(This,section,name,value);
}
static inline HRESULT IPersistQuery_ReadString(IPersistQuery* This,LPCWSTR section,LPCWSTR name,LPWSTR buffer,INT buflen) {
    return This->lpVtbl->ReadString(This,section,name,buffer,buflen);
}
static inline HRESULT IPersistQuery_WriteInt(IPersistQuery* This,LPCWSTR section,LPCWSTR name,INT value) {
    return This->lpVtbl->WriteInt(This,section,name,value);
}
static inline HRESULT IPersistQuery_ReadInt(IPersistQuery* This,LPCWSTR section,LPCWSTR name,INT *value) {
    return This->lpVtbl->ReadInt(This,section,name,value);
}
static inline HRESULT IPersistQuery_WriteStruct(IPersistQuery* This,LPCWSTR section,LPCWSTR name,LPVOID value,DWORD size) {
    return This->lpVtbl->WriteStruct(This,section,name,value,size);
}
static inline HRESULT IPersistQuery_ReadStruct(IPersistQuery* This,LPCWSTR section,LPCWSTR name,LPVOID buffer,DWORD buflen) {
    return This->lpVtbl->ReadStruct(This,section,name,buffer,buflen);
}
static inline HRESULT IPersistQuery_Clear(IPersistQuery* This) {
    return This->lpVtbl->Clear(This);
}
#endif
#endif

#endif


#endif  /* __IPersistQuery_INTERFACE_DEFINED__ */

#define OQWF_OKCANCEL            0x00000001
#define OQWF_DEFAULTFORM         0x00000002
#define OQWF_SINGLESELECT        0x00000004
#define OQWF_LOADQUERY           0x00000008
#define OQWF_REMOVESCOPES        0x00000010
#define OQWF_REMOVEFORMS         0x00000020
#define OQWF_ISSUEONOPEN         0x00000040
#define OQWF_SHOWOPTIONAL        0x00000080
#define OQWF_SAVEQUERYONOK       0x00000200
#define OQWF_HIDEMENUS           0x00000400
#define OQWF_HIDESEARCHUI        0x00000800
#define OQWF_PARAMISPROPERTYBAG  0x80000000
typedef struct __WIDL_cmnquery_generated_name_0000000E {
    DWORD cbStruct;
    DWORD dwFlags;
    CLSID clsidHandler;
    LPVOID pHandlerParameters;
    CLSID clsidDefaultForm;
    IPersistQuery *pPersistQuery;
    __C89_NAMELESS union {
        void *pFormParameters;
        IPropertyBag *ppbFormParameters;
    } __C89_NAMELESSUNIONNAME;
} OPENQUERYWINDOW;
typedef struct __WIDL_cmnquery_generated_name_0000000E *LPOPENQUERYWINDOW;
/*****************************************************************************
 * ICommonQuery interface
 */
#ifndef __ICommonQuery_INTERFACE_DEFINED__
#define __ICommonQuery_INTERFACE_DEFINED__

DEFINE_GUID(IID_ICommonQuery, 0xab50dec0, 0x6f1d, 0x11d0, 0xa1,0xc4, 0x00,0xaa,0x00,0xc1,0x6e,0x65);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("ab50dec0-6f1d-11d0-a1c4-00aa00c16e65")
ICommonQuery : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE OpenQueryWindow(
        HWND parent,
        LPOPENQUERYWINDOW query_window,
        IDataObject **data_object) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(ICommonQuery, 0xab50dec0, 0x6f1d, 0x11d0, 0xa1,0xc4, 0x00,0xaa,0x00,0xc1,0x6e,0x65)
#endif
#else
typedef struct ICommonQueryVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        ICommonQuery *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        ICommonQuery *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        ICommonQuery *This);

    /*** ICommonQuery methods ***/
    HRESULT (STDMETHODCALLTYPE *OpenQueryWindow)(
        ICommonQuery *This,
        HWND parent,
        LPOPENQUERYWINDOW query_window,
        IDataObject **data_object);

    END_INTERFACE
} ICommonQueryVtbl;

interface ICommonQuery {
    CONST_VTBL ICommonQueryVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define ICommonQuery_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ICommonQuery_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ICommonQuery_Release(This) (This)->lpVtbl->Release(This)
/*** ICommonQuery methods ***/
#define ICommonQuery_OpenQueryWindow(This,parent,query_window,data_object) (This)->lpVtbl->OpenQueryWindow(This,parent,query_window,data_object)
#else
/*** IUnknown methods ***/
static inline HRESULT ICommonQuery_QueryInterface(ICommonQuery* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static inline ULONG ICommonQuery_AddRef(ICommonQuery* This) {
    return This->lpVtbl->AddRef(This);
}
static inline ULONG ICommonQuery_Release(ICommonQuery* This) {
    return This->lpVtbl->Release(This);
}
/*** ICommonQuery methods ***/
static inline HRESULT ICommonQuery_OpenQueryWindow(ICommonQuery* This,HWND parent,LPOPENQUERYWINDOW query_window,IDataObject **data_object) {
    return This->lpVtbl->OpenQueryWindow(This,parent,query_window,data_object);
}
#endif
#endif

#endif


#endif  /* __ICommonQuery_INTERFACE_DEFINED__ */

/*****************************************************************************
 * CommonQuery coclass
 */

DEFINE_GUID(CLSID_CommonQuery, 0x83bc5ec0, 0x6f2a, 0x11d0, 0xa1,0xc4, 0x00,0xaa,0x00,0xc1,0x6e,0x65);

#ifdef __cplusplus
class DECLSPEC_UUID("83bc5ec0-6f2a-11d0-a1c4-00aa00c16e65") CommonQuery;
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(CommonQuery, 0x83bc5ec0, 0x6f2a, 0x11d0, 0xa1,0xc4, 0x00,0xaa,0x00,0xc1,0x6e,0x65)
#endif
#endif

/* Begin additional prototypes for all interfaces */


/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __cmnquery_h__ */

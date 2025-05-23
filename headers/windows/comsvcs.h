/*** Autogenerated by WIDL 10.0 from /build/wine-10.0/include/comsvcs.idl - Do not edit ***/

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

#ifndef __comsvcs_h__
#define __comsvcs_h__

/* Forward declarations */

#ifndef __IHolder_FWD_DEFINED__
#define __IHolder_FWD_DEFINED__
typedef interface IHolder IHolder;
#ifdef __cplusplus
interface IHolder;
#endif /* __cplusplus */
#endif

#ifndef __IDispenserDriver_FWD_DEFINED__
#define __IDispenserDriver_FWD_DEFINED__
typedef interface IDispenserDriver IDispenserDriver;
#ifdef __cplusplus
interface IDispenserDriver;
#endif /* __cplusplus */
#endif

#ifndef __IDispenserManager_FWD_DEFINED__
#define __IDispenserManager_FWD_DEFINED__
typedef interface IDispenserManager IDispenserManager;
#ifdef __cplusplus
interface IDispenserManager;
#endif /* __cplusplus */
#endif

#ifndef __DispenserManager_FWD_DEFINED__
#define __DispenserManager_FWD_DEFINED__
#ifdef __cplusplus
typedef class DispenserManager DispenserManager;
#else
typedef struct DispenserManager DispenserManager;
#endif /* defined __cplusplus */
#endif /* defined __DispenserManager_FWD_DEFINED__ */

#ifndef __ISharedProperty_FWD_DEFINED__
#define __ISharedProperty_FWD_DEFINED__
typedef interface ISharedProperty ISharedProperty;
#ifdef __cplusplus
interface ISharedProperty;
#endif /* __cplusplus */
#endif

#ifndef __ISharedPropertyGroup_FWD_DEFINED__
#define __ISharedPropertyGroup_FWD_DEFINED__
typedef interface ISharedPropertyGroup ISharedPropertyGroup;
#ifdef __cplusplus
interface ISharedPropertyGroup;
#endif /* __cplusplus */
#endif

#ifndef __ISharedPropertyGroupManager_FWD_DEFINED__
#define __ISharedPropertyGroupManager_FWD_DEFINED__
typedef interface ISharedPropertyGroupManager ISharedPropertyGroupManager;
#ifdef __cplusplus
interface ISharedPropertyGroupManager;
#endif /* __cplusplus */
#endif

#ifndef __SharedPropertyGroupManager_FWD_DEFINED__
#define __SharedPropertyGroupManager_FWD_DEFINED__
#ifdef __cplusplus
typedef class SharedPropertyGroupManager SharedPropertyGroupManager;
#else
typedef struct SharedPropertyGroupManager SharedPropertyGroupManager;
#endif /* defined __cplusplus */
#endif /* defined __SharedPropertyGroupManager_FWD_DEFINED__ */

/* Headers for imported files */

#include <unknwn.h>
#include <objidl.h>
#include <oaidl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef DWORD_PTR INSTID;
typedef DWORD_PTR RESID;
typedef DWORD RESOURCERATING;
typedef DWORD_PTR RESTYPID;
typedef LPOLESTR SRESID;
typedef LONG TIMEINSECS;
typedef DWORD_PTR TRANSID;
#ifndef __COMSVCSLib_LIBRARY_DEFINED__
#define __COMSVCSLib_LIBRARY_DEFINED__

DEFINE_GUID(LIBID_COMSVCSLib, 0x2a005c00, 0xa5de, 0x11cf, 0x9e,0x66, 0x00,0xaa,0x00,0xa3,0xf4,0x64);

/*****************************************************************************
 * IHolder interface
 */
#ifndef __IHolder_INTERFACE_DEFINED__
#define __IHolder_INTERFACE_DEFINED__

DEFINE_GUID(IID_IHolder, 0xbf6a1850, 0x2b45, 0x11cf, 0xbe,0x10, 0x00,0xaa,0x00,0xa2,0xfa,0x25);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("bf6a1850-2b45-11cf-be10-00aa00a2fa25")
IHolder : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE AllocResource(
        const RESTYPID typeid,
        RESID *resid) = 0;

    virtual HRESULT STDMETHODCALLTYPE FreeResource(
        const RESID _resid) = 0;

    virtual HRESULT STDMETHODCALLTYPE TrackResource(
        const RESID resid) = 0;

    virtual HRESULT STDMETHODCALLTYPE TrackResourceS(
        const SRESID resid) = 0;

    virtual HRESULT STDMETHODCALLTYPE UntrackResource(
        const RESID resid,
        const BOOL value) = 0;

    virtual HRESULT STDMETHODCALLTYPE UntrackResourceS(
        const SRESID resid,
        const BOOL value) = 0;

    virtual HRESULT STDMETHODCALLTYPE Close(
        ) = 0;

    virtual HRESULT STDMETHODCALLTYPE RequestDestroyResource(
        const RESID resid) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IHolder, 0xbf6a1850, 0x2b45, 0x11cf, 0xbe,0x10, 0x00,0xaa,0x00,0xa2,0xfa,0x25)
#endif
#else
typedef struct IHolderVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IHolder *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IHolder *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IHolder *This);

    /*** IHolder methods ***/
    HRESULT (STDMETHODCALLTYPE *AllocResource)(
        IHolder *This,
        const RESTYPID typeid,
        RESID *resid);

    HRESULT (STDMETHODCALLTYPE *FreeResource)(
        IHolder *This,
        const RESID _resid);

    HRESULT (STDMETHODCALLTYPE *TrackResource)(
        IHolder *This,
        const RESID resid);

    HRESULT (STDMETHODCALLTYPE *TrackResourceS)(
        IHolder *This,
        const SRESID resid);

    HRESULT (STDMETHODCALLTYPE *UntrackResource)(
        IHolder *This,
        const RESID resid,
        const BOOL value);

    HRESULT (STDMETHODCALLTYPE *UntrackResourceS)(
        IHolder *This,
        const SRESID resid,
        const BOOL value);

    HRESULT (STDMETHODCALLTYPE *Close)(
        IHolder *This);

    HRESULT (STDMETHODCALLTYPE *RequestDestroyResource)(
        IHolder *This,
        const RESID resid);

    END_INTERFACE
} IHolderVtbl;

interface IHolder {
    CONST_VTBL IHolderVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IHolder_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IHolder_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IHolder_Release(This) (This)->lpVtbl->Release(This)
/*** IHolder methods ***/
#define IHolder_AllocResource(This,typeid,resid) (This)->lpVtbl->AllocResource(This,typeid,resid)
#define IHolder_FreeResource(This,_resid) (This)->lpVtbl->FreeResource(This,_resid)
#define IHolder_TrackResource(This,resid) (This)->lpVtbl->TrackResource(This,resid)
#define IHolder_TrackResourceS(This,resid) (This)->lpVtbl->TrackResourceS(This,resid)
#define IHolder_UntrackResource(This,resid,value) (This)->lpVtbl->UntrackResource(This,resid,value)
#define IHolder_UntrackResourceS(This,resid,value) (This)->lpVtbl->UntrackResourceS(This,resid,value)
#define IHolder_Close(This) (This)->lpVtbl->Close(This)
#define IHolder_RequestDestroyResource(This,resid) (This)->lpVtbl->RequestDestroyResource(This,resid)
#else
/*** IUnknown methods ***/
static inline HRESULT IHolder_QueryInterface(IHolder* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static inline ULONG IHolder_AddRef(IHolder* This) {
    return This->lpVtbl->AddRef(This);
}
static inline ULONG IHolder_Release(IHolder* This) {
    return This->lpVtbl->Release(This);
}
/*** IHolder methods ***/
static inline HRESULT IHolder_AllocResource(IHolder* This,const RESTYPID typeid,RESID *resid) {
    return This->lpVtbl->AllocResource(This,typeid,resid);
}
static inline HRESULT IHolder_FreeResource(IHolder* This,const RESID _resid) {
    return This->lpVtbl->FreeResource(This,_resid);
}
static inline HRESULT IHolder_TrackResource(IHolder* This,const RESID resid) {
    return This->lpVtbl->TrackResource(This,resid);
}
static inline HRESULT IHolder_TrackResourceS(IHolder* This,const SRESID resid) {
    return This->lpVtbl->TrackResourceS(This,resid);
}
static inline HRESULT IHolder_UntrackResource(IHolder* This,const RESID resid,const BOOL value) {
    return This->lpVtbl->UntrackResource(This,resid,value);
}
static inline HRESULT IHolder_UntrackResourceS(IHolder* This,const SRESID resid,const BOOL value) {
    return This->lpVtbl->UntrackResourceS(This,resid,value);
}
static inline HRESULT IHolder_Close(IHolder* This) {
    return This->lpVtbl->Close(This);
}
static inline HRESULT IHolder_RequestDestroyResource(IHolder* This,const RESID resid) {
    return This->lpVtbl->RequestDestroyResource(This,resid);
}
#endif
#endif

#endif


#endif  /* __IHolder_INTERFACE_DEFINED__ */

/*****************************************************************************
 * IDispenserDriver interface
 */
#ifndef __IDispenserDriver_INTERFACE_DEFINED__
#define __IDispenserDriver_INTERFACE_DEFINED__

DEFINE_GUID(IID_IDispenserDriver, 0x208b3651, 0x2b48, 0x11cf, 0xbe,0x10, 0x00,0xaa,0x00,0xa2,0xfa,0x25);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("208b3651-2b48-11cf-be10-00aa00a2fa25")
IDispenserDriver : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE CreateResource(
        const RESTYPID restypid,
        RESID *resid,
        TIMEINSECS *destroy) = 0;

    virtual HRESULT STDMETHODCALLTYPE RateResource(
        const RESTYPID restypid,
        const RESID resid,
        const BOOL requires,
        RESOURCERATING *rating) = 0;

    virtual HRESULT STDMETHODCALLTYPE EnlistResource(
        const RESID resid,
        const TRANSID transid) = 0;

    virtual HRESULT STDMETHODCALLTYPE ResetResource(
        const RESID resid) = 0;

    virtual HRESULT STDMETHODCALLTYPE DestroyResource(
        const RESID resid) = 0;

    virtual HRESULT STDMETHODCALLTYPE DestroyResourceS(
        const SRESID resid) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IDispenserDriver, 0x208b3651, 0x2b48, 0x11cf, 0xbe,0x10, 0x00,0xaa,0x00,0xa2,0xfa,0x25)
#endif
#else
typedef struct IDispenserDriverVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IDispenserDriver *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IDispenserDriver *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IDispenserDriver *This);

    /*** IDispenserDriver methods ***/
    HRESULT (STDMETHODCALLTYPE *CreateResource)(
        IDispenserDriver *This,
        const RESTYPID restypid,
        RESID *resid,
        TIMEINSECS *destroy);

    HRESULT (STDMETHODCALLTYPE *RateResource)(
        IDispenserDriver *This,
        const RESTYPID restypid,
        const RESID resid,
        const BOOL requires,
        RESOURCERATING *rating);

    HRESULT (STDMETHODCALLTYPE *EnlistResource)(
        IDispenserDriver *This,
        const RESID resid,
        const TRANSID transid);

    HRESULT (STDMETHODCALLTYPE *ResetResource)(
        IDispenserDriver *This,
        const RESID resid);

    HRESULT (STDMETHODCALLTYPE *DestroyResource)(
        IDispenserDriver *This,
        const RESID resid);

    HRESULT (STDMETHODCALLTYPE *DestroyResourceS)(
        IDispenserDriver *This,
        const SRESID resid);

    END_INTERFACE
} IDispenserDriverVtbl;

interface IDispenserDriver {
    CONST_VTBL IDispenserDriverVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IDispenserDriver_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDispenserDriver_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDispenserDriver_Release(This) (This)->lpVtbl->Release(This)
/*** IDispenserDriver methods ***/
#define IDispenserDriver_CreateResource(This,restypid,resid,destroy) (This)->lpVtbl->CreateResource(This,restypid,resid,destroy)
#define IDispenserDriver_RateResource(This,restypid,resid,requires,rating) (This)->lpVtbl->RateResource(This,restypid,resid,requires,rating)
#define IDispenserDriver_EnlistResource(This,resid,transid) (This)->lpVtbl->EnlistResource(This,resid,transid)
#define IDispenserDriver_ResetResource(This,resid) (This)->lpVtbl->ResetResource(This,resid)
#define IDispenserDriver_DestroyResource(This,resid) (This)->lpVtbl->DestroyResource(This,resid)
#define IDispenserDriver_DestroyResourceS(This,resid) (This)->lpVtbl->DestroyResourceS(This,resid)
#else
/*** IUnknown methods ***/
static inline HRESULT IDispenserDriver_QueryInterface(IDispenserDriver* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static inline ULONG IDispenserDriver_AddRef(IDispenserDriver* This) {
    return This->lpVtbl->AddRef(This);
}
static inline ULONG IDispenserDriver_Release(IDispenserDriver* This) {
    return This->lpVtbl->Release(This);
}
/*** IDispenserDriver methods ***/
static inline HRESULT IDispenserDriver_CreateResource(IDispenserDriver* This,const RESTYPID restypid,RESID *resid,TIMEINSECS *destroy) {
    return This->lpVtbl->CreateResource(This,restypid,resid,destroy);
}
static inline HRESULT IDispenserDriver_RateResource(IDispenserDriver* This,const RESTYPID restypid,const RESID resid,const BOOL requires,RESOURCERATING *rating) {
    return This->lpVtbl->RateResource(This,restypid,resid,requires,rating);
}
static inline HRESULT IDispenserDriver_EnlistResource(IDispenserDriver* This,const RESID resid,const TRANSID transid) {
    return This->lpVtbl->EnlistResource(This,resid,transid);
}
static inline HRESULT IDispenserDriver_ResetResource(IDispenserDriver* This,const RESID resid) {
    return This->lpVtbl->ResetResource(This,resid);
}
static inline HRESULT IDispenserDriver_DestroyResource(IDispenserDriver* This,const RESID resid) {
    return This->lpVtbl->DestroyResource(This,resid);
}
static inline HRESULT IDispenserDriver_DestroyResourceS(IDispenserDriver* This,const SRESID resid) {
    return This->lpVtbl->DestroyResourceS(This,resid);
}
#endif
#endif

#endif


#endif  /* __IDispenserDriver_INTERFACE_DEFINED__ */

/*****************************************************************************
 * IDispenserManager interface
 */
#ifndef __IDispenserManager_INTERFACE_DEFINED__
#define __IDispenserManager_INTERFACE_DEFINED__

DEFINE_GUID(IID_IDispenserManager, 0x5cb31e10, 0x2b5f, 0x11cf, 0xbe,0x10, 0x00,0xaa,0x00,0xa2,0xfa,0x25);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("5cb31e10-2b5f-11cf-be10-00aa00a2fa25")
IDispenserManager : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE RegisterDispenser(
        IDispenserDriver *driver,
        LPCOLESTR name,
        IHolder **dispenser) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetContext(
        INSTID *id,
        TRANSID *transid) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IDispenserManager, 0x5cb31e10, 0x2b5f, 0x11cf, 0xbe,0x10, 0x00,0xaa,0x00,0xa2,0xfa,0x25)
#endif
#else
typedef struct IDispenserManagerVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IDispenserManager *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IDispenserManager *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IDispenserManager *This);

    /*** IDispenserManager methods ***/
    HRESULT (STDMETHODCALLTYPE *RegisterDispenser)(
        IDispenserManager *This,
        IDispenserDriver *driver,
        LPCOLESTR name,
        IHolder **dispenser);

    HRESULT (STDMETHODCALLTYPE *GetContext)(
        IDispenserManager *This,
        INSTID *id,
        TRANSID *transid);

    END_INTERFACE
} IDispenserManagerVtbl;

interface IDispenserManager {
    CONST_VTBL IDispenserManagerVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IDispenserManager_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDispenserManager_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDispenserManager_Release(This) (This)->lpVtbl->Release(This)
/*** IDispenserManager methods ***/
#define IDispenserManager_RegisterDispenser(This,driver,name,dispenser) (This)->lpVtbl->RegisterDispenser(This,driver,name,dispenser)
#define IDispenserManager_GetContext(This,id,transid) (This)->lpVtbl->GetContext(This,id,transid)
#else
/*** IUnknown methods ***/
static inline HRESULT IDispenserManager_QueryInterface(IDispenserManager* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static inline ULONG IDispenserManager_AddRef(IDispenserManager* This) {
    return This->lpVtbl->AddRef(This);
}
static inline ULONG IDispenserManager_Release(IDispenserManager* This) {
    return This->lpVtbl->Release(This);
}
/*** IDispenserManager methods ***/
static inline HRESULT IDispenserManager_RegisterDispenser(IDispenserManager* This,IDispenserDriver *driver,LPCOLESTR name,IHolder **dispenser) {
    return This->lpVtbl->RegisterDispenser(This,driver,name,dispenser);
}
static inline HRESULT IDispenserManager_GetContext(IDispenserManager* This,INSTID *id,TRANSID *transid) {
    return This->lpVtbl->GetContext(This,id,transid);
}
#endif
#endif

#endif


#endif  /* __IDispenserManager_INTERFACE_DEFINED__ */

/*****************************************************************************
 * DispenserManager coclass
 */

DEFINE_GUID(CLSID_DispenserManager, 0xecabb0c0, 0x7f19, 0x11d2, 0x97,0x8e, 0x00,0x00,0xf8,0x75,0x7e,0x2a);

#ifdef __cplusplus
class DECLSPEC_UUID("ecabb0c0-7f19-11d2-978e-0000f8757e2a") DispenserManager;
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(DispenserManager, 0xecabb0c0, 0x7f19, 0x11d2, 0x97,0x8e, 0x00,0x00,0xf8,0x75,0x7e,0x2a)
#endif
#endif

/*****************************************************************************
 * ISharedProperty interface
 */
#ifndef __ISharedProperty_INTERFACE_DEFINED__
#define __ISharedProperty_INTERFACE_DEFINED__

DEFINE_GUID(IID_ISharedProperty, 0x2a005c01, 0xa5de, 0x11cf, 0x9e,0x66, 0x00,0xaa,0x00,0xa3,0xf4,0x64);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("2a005c01-a5de-11cf-9e66-00aa00a3f464")
ISharedProperty : public IDispatch
{
    virtual HRESULT STDMETHODCALLTYPE get_Value(
        VARIANT *value) = 0;

    virtual HRESULT STDMETHODCALLTYPE put_Value(
        VARIANT value) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(ISharedProperty, 0x2a005c01, 0xa5de, 0x11cf, 0x9e,0x66, 0x00,0xaa,0x00,0xa3,0xf4,0x64)
#endif
#else
typedef struct ISharedPropertyVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        ISharedProperty *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        ISharedProperty *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        ISharedProperty *This);

    /*** IDispatch methods ***/
    HRESULT (STDMETHODCALLTYPE *GetTypeInfoCount)(
        ISharedProperty *This,
        UINT *pctinfo);

    HRESULT (STDMETHODCALLTYPE *GetTypeInfo)(
        ISharedProperty *This,
        UINT iTInfo,
        LCID lcid,
        ITypeInfo **ppTInfo);

    HRESULT (STDMETHODCALLTYPE *GetIDsOfNames)(
        ISharedProperty *This,
        REFIID riid,
        LPOLESTR *rgszNames,
        UINT cNames,
        LCID lcid,
        DISPID *rgDispId);

    HRESULT (STDMETHODCALLTYPE *Invoke)(
        ISharedProperty *This,
        DISPID dispIdMember,
        REFIID riid,
        LCID lcid,
        WORD wFlags,
        DISPPARAMS *pDispParams,
        VARIANT *pVarResult,
        EXCEPINFO *pExcepInfo,
        UINT *puArgErr);

    /*** ISharedProperty methods ***/
    HRESULT (STDMETHODCALLTYPE *get_Value)(
        ISharedProperty *This,
        VARIANT *value);

    HRESULT (STDMETHODCALLTYPE *put_Value)(
        ISharedProperty *This,
        VARIANT value);

    END_INTERFACE
} ISharedPropertyVtbl;

interface ISharedProperty {
    CONST_VTBL ISharedPropertyVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define ISharedProperty_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ISharedProperty_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ISharedProperty_Release(This) (This)->lpVtbl->Release(This)
/*** IDispatch methods ***/
#define ISharedProperty_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define ISharedProperty_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define ISharedProperty_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define ISharedProperty_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
/*** ISharedProperty methods ***/
#define ISharedProperty_get_Value(This,value) (This)->lpVtbl->get_Value(This,value)
#define ISharedProperty_put_Value(This,value) (This)->lpVtbl->put_Value(This,value)
#else
/*** IUnknown methods ***/
static inline HRESULT ISharedProperty_QueryInterface(ISharedProperty* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static inline ULONG ISharedProperty_AddRef(ISharedProperty* This) {
    return This->lpVtbl->AddRef(This);
}
static inline ULONG ISharedProperty_Release(ISharedProperty* This) {
    return This->lpVtbl->Release(This);
}
/*** IDispatch methods ***/
static inline HRESULT ISharedProperty_GetTypeInfoCount(ISharedProperty* This,UINT *pctinfo) {
    return This->lpVtbl->GetTypeInfoCount(This,pctinfo);
}
static inline HRESULT ISharedProperty_GetTypeInfo(ISharedProperty* This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo) {
    return This->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo);
}
static inline HRESULT ISharedProperty_GetIDsOfNames(ISharedProperty* This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId) {
    return This->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId);
}
static inline HRESULT ISharedProperty_Invoke(ISharedProperty* This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr) {
    return This->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr);
}
/*** ISharedProperty methods ***/
static inline HRESULT ISharedProperty_get_Value(ISharedProperty* This,VARIANT *value) {
    return This->lpVtbl->get_Value(This,value);
}
static inline HRESULT ISharedProperty_put_Value(ISharedProperty* This,VARIANT value) {
    return This->lpVtbl->put_Value(This,value);
}
#endif
#endif

#endif


#endif  /* __ISharedProperty_INTERFACE_DEFINED__ */

/*****************************************************************************
 * ISharedPropertyGroup interface
 */
#ifndef __ISharedPropertyGroup_INTERFACE_DEFINED__
#define __ISharedPropertyGroup_INTERFACE_DEFINED__

DEFINE_GUID(IID_ISharedPropertyGroup, 0x2a005c07, 0xa5de, 0x11cf, 0x9e,0x66, 0x00,0xaa,0x00,0xa3,0xf4,0x64);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("2a005c07-a5de-11cf-9e66-00aa00a3f464")
ISharedPropertyGroup : public IDispatch
{
    virtual HRESULT STDMETHODCALLTYPE CreatePropertyByPosition(
        int index,
        VARIANT_BOOL *exists,
        ISharedProperty **property) = 0;

    virtual HRESULT STDMETHODCALLTYPE get_PropertyByPosition(
        int index,
        ISharedProperty **property) = 0;

    virtual HRESULT STDMETHODCALLTYPE CreateProperty(
        BSTR name,
        VARIANT_BOOL *exists,
        ISharedProperty **property) = 0;

    virtual HRESULT STDMETHODCALLTYPE get_Property(
        BSTR name,
        ISharedProperty **property) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(ISharedPropertyGroup, 0x2a005c07, 0xa5de, 0x11cf, 0x9e,0x66, 0x00,0xaa,0x00,0xa3,0xf4,0x64)
#endif
#else
typedef struct ISharedPropertyGroupVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        ISharedPropertyGroup *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        ISharedPropertyGroup *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        ISharedPropertyGroup *This);

    /*** IDispatch methods ***/
    HRESULT (STDMETHODCALLTYPE *GetTypeInfoCount)(
        ISharedPropertyGroup *This,
        UINT *pctinfo);

    HRESULT (STDMETHODCALLTYPE *GetTypeInfo)(
        ISharedPropertyGroup *This,
        UINT iTInfo,
        LCID lcid,
        ITypeInfo **ppTInfo);

    HRESULT (STDMETHODCALLTYPE *GetIDsOfNames)(
        ISharedPropertyGroup *This,
        REFIID riid,
        LPOLESTR *rgszNames,
        UINT cNames,
        LCID lcid,
        DISPID *rgDispId);

    HRESULT (STDMETHODCALLTYPE *Invoke)(
        ISharedPropertyGroup *This,
        DISPID dispIdMember,
        REFIID riid,
        LCID lcid,
        WORD wFlags,
        DISPPARAMS *pDispParams,
        VARIANT *pVarResult,
        EXCEPINFO *pExcepInfo,
        UINT *puArgErr);

    /*** ISharedPropertyGroup methods ***/
    HRESULT (STDMETHODCALLTYPE *CreatePropertyByPosition)(
        ISharedPropertyGroup *This,
        int index,
        VARIANT_BOOL *exists,
        ISharedProperty **property);

    HRESULT (STDMETHODCALLTYPE *get_PropertyByPosition)(
        ISharedPropertyGroup *This,
        int index,
        ISharedProperty **property);

    HRESULT (STDMETHODCALLTYPE *CreateProperty)(
        ISharedPropertyGroup *This,
        BSTR name,
        VARIANT_BOOL *exists,
        ISharedProperty **property);

    HRESULT (STDMETHODCALLTYPE *get_Property)(
        ISharedPropertyGroup *This,
        BSTR name,
        ISharedProperty **property);

    END_INTERFACE
} ISharedPropertyGroupVtbl;

interface ISharedPropertyGroup {
    CONST_VTBL ISharedPropertyGroupVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define ISharedPropertyGroup_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ISharedPropertyGroup_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ISharedPropertyGroup_Release(This) (This)->lpVtbl->Release(This)
/*** IDispatch methods ***/
#define ISharedPropertyGroup_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define ISharedPropertyGroup_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define ISharedPropertyGroup_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define ISharedPropertyGroup_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
/*** ISharedPropertyGroup methods ***/
#define ISharedPropertyGroup_CreatePropertyByPosition(This,index,exists,property) (This)->lpVtbl->CreatePropertyByPosition(This,index,exists,property)
#define ISharedPropertyGroup_get_PropertyByPosition(This,index,property) (This)->lpVtbl->get_PropertyByPosition(This,index,property)
#define ISharedPropertyGroup_CreateProperty(This,name,exists,property) (This)->lpVtbl->CreateProperty(This,name,exists,property)
#define ISharedPropertyGroup_get_Property(This,name,property) (This)->lpVtbl->get_Property(This,name,property)
#else
/*** IUnknown methods ***/
static inline HRESULT ISharedPropertyGroup_QueryInterface(ISharedPropertyGroup* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static inline ULONG ISharedPropertyGroup_AddRef(ISharedPropertyGroup* This) {
    return This->lpVtbl->AddRef(This);
}
static inline ULONG ISharedPropertyGroup_Release(ISharedPropertyGroup* This) {
    return This->lpVtbl->Release(This);
}
/*** IDispatch methods ***/
static inline HRESULT ISharedPropertyGroup_GetTypeInfoCount(ISharedPropertyGroup* This,UINT *pctinfo) {
    return This->lpVtbl->GetTypeInfoCount(This,pctinfo);
}
static inline HRESULT ISharedPropertyGroup_GetTypeInfo(ISharedPropertyGroup* This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo) {
    return This->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo);
}
static inline HRESULT ISharedPropertyGroup_GetIDsOfNames(ISharedPropertyGroup* This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId) {
    return This->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId);
}
static inline HRESULT ISharedPropertyGroup_Invoke(ISharedPropertyGroup* This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr) {
    return This->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr);
}
/*** ISharedPropertyGroup methods ***/
static inline HRESULT ISharedPropertyGroup_CreatePropertyByPosition(ISharedPropertyGroup* This,int index,VARIANT_BOOL *exists,ISharedProperty **property) {
    return This->lpVtbl->CreatePropertyByPosition(This,index,exists,property);
}
static inline HRESULT ISharedPropertyGroup_get_PropertyByPosition(ISharedPropertyGroup* This,int index,ISharedProperty **property) {
    return This->lpVtbl->get_PropertyByPosition(This,index,property);
}
static inline HRESULT ISharedPropertyGroup_CreateProperty(ISharedPropertyGroup* This,BSTR name,VARIANT_BOOL *exists,ISharedProperty **property) {
    return This->lpVtbl->CreateProperty(This,name,exists,property);
}
static inline HRESULT ISharedPropertyGroup_get_Property(ISharedPropertyGroup* This,BSTR name,ISharedProperty **property) {
    return This->lpVtbl->get_Property(This,name,property);
}
#endif
#endif

#endif


#endif  /* __ISharedPropertyGroup_INTERFACE_DEFINED__ */

/*****************************************************************************
 * ISharedPropertyGroupManager interface
 */
#ifndef __ISharedPropertyGroupManager_INTERFACE_DEFINED__
#define __ISharedPropertyGroupManager_INTERFACE_DEFINED__

DEFINE_GUID(IID_ISharedPropertyGroupManager, 0x2a005c0d, 0xa5de, 0x11cf, 0x9e,0x66, 0x00,0xaa,0x00,0xa3,0xf4,0x64);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("2a005c0d-a5de-11cf-9e66-00aa00a3f464")
ISharedPropertyGroupManager : public IDispatch
{
    virtual HRESULT STDMETHODCALLTYPE CreatePropertyGroup(
        BSTR name,
        LONG *isolation,
        LONG *release,
        VARIANT_BOOL *exists,
        ISharedPropertyGroup **group) = 0;

    virtual HRESULT STDMETHODCALLTYPE get_Group(
        BSTR name,
        ISharedPropertyGroup **group) = 0;

    virtual HRESULT STDMETHODCALLTYPE get__NewEnum(
        IUnknown **retval) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(ISharedPropertyGroupManager, 0x2a005c0d, 0xa5de, 0x11cf, 0x9e,0x66, 0x00,0xaa,0x00,0xa3,0xf4,0x64)
#endif
#else
typedef struct ISharedPropertyGroupManagerVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        ISharedPropertyGroupManager *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        ISharedPropertyGroupManager *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        ISharedPropertyGroupManager *This);

    /*** IDispatch methods ***/
    HRESULT (STDMETHODCALLTYPE *GetTypeInfoCount)(
        ISharedPropertyGroupManager *This,
        UINT *pctinfo);

    HRESULT (STDMETHODCALLTYPE *GetTypeInfo)(
        ISharedPropertyGroupManager *This,
        UINT iTInfo,
        LCID lcid,
        ITypeInfo **ppTInfo);

    HRESULT (STDMETHODCALLTYPE *GetIDsOfNames)(
        ISharedPropertyGroupManager *This,
        REFIID riid,
        LPOLESTR *rgszNames,
        UINT cNames,
        LCID lcid,
        DISPID *rgDispId);

    HRESULT (STDMETHODCALLTYPE *Invoke)(
        ISharedPropertyGroupManager *This,
        DISPID dispIdMember,
        REFIID riid,
        LCID lcid,
        WORD wFlags,
        DISPPARAMS *pDispParams,
        VARIANT *pVarResult,
        EXCEPINFO *pExcepInfo,
        UINT *puArgErr);

    /*** ISharedPropertyGroupManager methods ***/
    HRESULT (STDMETHODCALLTYPE *CreatePropertyGroup)(
        ISharedPropertyGroupManager *This,
        BSTR name,
        LONG *isolation,
        LONG *release,
        VARIANT_BOOL *exists,
        ISharedPropertyGroup **group);

    HRESULT (STDMETHODCALLTYPE *get_Group)(
        ISharedPropertyGroupManager *This,
        BSTR name,
        ISharedPropertyGroup **group);

    HRESULT (STDMETHODCALLTYPE *get__NewEnum)(
        ISharedPropertyGroupManager *This,
        IUnknown **retval);

    END_INTERFACE
} ISharedPropertyGroupManagerVtbl;

interface ISharedPropertyGroupManager {
    CONST_VTBL ISharedPropertyGroupManagerVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define ISharedPropertyGroupManager_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ISharedPropertyGroupManager_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ISharedPropertyGroupManager_Release(This) (This)->lpVtbl->Release(This)
/*** IDispatch methods ***/
#define ISharedPropertyGroupManager_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define ISharedPropertyGroupManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define ISharedPropertyGroupManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define ISharedPropertyGroupManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
/*** ISharedPropertyGroupManager methods ***/
#define ISharedPropertyGroupManager_CreatePropertyGroup(This,name,isolation,release,exists,group) (This)->lpVtbl->CreatePropertyGroup(This,name,isolation,release,exists,group)
#define ISharedPropertyGroupManager_get_Group(This,name,group) (This)->lpVtbl->get_Group(This,name,group)
#define ISharedPropertyGroupManager_get__NewEnum(This,retval) (This)->lpVtbl->get__NewEnum(This,retval)
#else
/*** IUnknown methods ***/
static inline HRESULT ISharedPropertyGroupManager_QueryInterface(ISharedPropertyGroupManager* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static inline ULONG ISharedPropertyGroupManager_AddRef(ISharedPropertyGroupManager* This) {
    return This->lpVtbl->AddRef(This);
}
static inline ULONG ISharedPropertyGroupManager_Release(ISharedPropertyGroupManager* This) {
    return This->lpVtbl->Release(This);
}
/*** IDispatch methods ***/
static inline HRESULT ISharedPropertyGroupManager_GetTypeInfoCount(ISharedPropertyGroupManager* This,UINT *pctinfo) {
    return This->lpVtbl->GetTypeInfoCount(This,pctinfo);
}
static inline HRESULT ISharedPropertyGroupManager_GetTypeInfo(ISharedPropertyGroupManager* This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo) {
    return This->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo);
}
static inline HRESULT ISharedPropertyGroupManager_GetIDsOfNames(ISharedPropertyGroupManager* This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId) {
    return This->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId);
}
static inline HRESULT ISharedPropertyGroupManager_Invoke(ISharedPropertyGroupManager* This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr) {
    return This->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr);
}
/*** ISharedPropertyGroupManager methods ***/
static inline HRESULT ISharedPropertyGroupManager_CreatePropertyGroup(ISharedPropertyGroupManager* This,BSTR name,LONG *isolation,LONG *release,VARIANT_BOOL *exists,ISharedPropertyGroup **group) {
    return This->lpVtbl->CreatePropertyGroup(This,name,isolation,release,exists,group);
}
static inline HRESULT ISharedPropertyGroupManager_get_Group(ISharedPropertyGroupManager* This,BSTR name,ISharedPropertyGroup **group) {
    return This->lpVtbl->get_Group(This,name,group);
}
static inline HRESULT ISharedPropertyGroupManager_get__NewEnum(ISharedPropertyGroupManager* This,IUnknown **retval) {
    return This->lpVtbl->get__NewEnum(This,retval);
}
#endif
#endif

#endif


#endif  /* __ISharedPropertyGroupManager_INTERFACE_DEFINED__ */

/*****************************************************************************
 * SharedPropertyGroupManager coclass
 */

DEFINE_GUID(CLSID_SharedPropertyGroupManager, 0x2a005c11, 0xa5de, 0x11cf, 0x9e,0x66, 0x00,0xaa,0x00,0xa3,0xf4,0x64);

#ifdef __cplusplus
class DECLSPEC_UUID("2a005c11-a5de-11cf-9e66-00aa00a3f464") SharedPropertyGroupManager;
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(SharedPropertyGroupManager, 0x2a005c11, 0xa5de, 0x11cf, 0x9e,0x66, 0x00,0xaa,0x00,0xa3,0xf4,0x64)
#endif
#endif

#endif /* __COMSVCSLib_LIBRARY_DEFINED__ */
/* Begin additional prototypes for all interfaces */


/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __comsvcs_h__ */

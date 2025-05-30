/*** Autogenerated by WIDL 10.0 from /build/wine-10.0/include/iimgctx.idl - Do not edit ***/

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

#ifndef __iimgctx_h__
#define __iimgctx_h__

/* Forward declarations */

#ifndef __IImgCtx_FWD_DEFINED__
#define __IImgCtx_FWD_DEFINED__
typedef interface IImgCtx IImgCtx;
#ifdef __cplusplus
interface IImgCtx;
#endif /* __cplusplus */
#endif

/* Headers for imported files */

#include <unknwn.h>

#ifdef __cplusplus
extern "C" {
#endif

#define IMGCHG_SIZE     0x0001
#define IMGCHG_VIEW     0x0002
#define IMGCHG_COMPLETE 0x0004
#define IMGCHG_ANIMATE  0x0008
#define IMGCHG_MASK     0x000f
#define IMGLOAD_NOTLOADED 0x00100000
#define IMGLOAD_LOADING   0x00200000
#define IMGLOAD_STOPPED   0x00400000
#define IMGLOAD_ERROR     0x00800000
#define IMGLOAD_COMPLETE  0x01000000
#define IMGLOAD_MASK      0x01f00000
#define IMGBITS_NONE      0x02000000
#define IMGBITS_PARTIAL   0x04000000
#define IMGBITS_TOTAL     0x08000000
#define IMGBITS_MASK      0x0e000000
#define IMGANIM_ANIMATED  0x10000000
#define IMGANIM_MASK      0x10000000
#define IMGTRANS_OPAQUE   0x20000000
#define IMGTRANS_MASK     0x20000000
#define DWN_COLORMODE     0x0000003f
#define DWN_DOWNLOADONLY  0x00000040
#define DWN_FORCEDITHER   0x00000080
#define DWN_RAWIMAGE      0x00000100
#define DWN_MIRRORIMAGE   0x00000200
typedef void (__stdcall *PFNIMGCTXCALLBACK)(void *a,void *b);
/*****************************************************************************
 * IImgCtx interface
 */
#ifndef __IImgCtx_INTERFACE_DEFINED__
#define __IImgCtx_INTERFACE_DEFINED__

DEFINE_GUID(IID_IImgCtx, 0x3050f3d7, 0x98b5, 0x11cf, 0xbb,0x82, 0x00,0xaa,0x00,0xbd,0xce,0x0b);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("3050f3d7-98b5-11cf-bb82-00aa00bdce0b")
IImgCtx : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE Load(
        LPCWSTR url,
        DWORD flags) = 0;

    virtual HRESULT STDMETHODCALLTYPE SelectChanges(
        ULONG changeon,
        ULONG changeoff,
        BOOL signal) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetCallback(
        PFNIMGCTXCALLBACK fn,
        void *priv) = 0;

    virtual HRESULT STDMETHODCALLTYPE Disconnect(
        ) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetUpdateRects(
        RECT *rect,
        RECT *img,
        LONG *pcrc) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetStateInfo(
        ULONG *state,
        SIZE *size,
        BOOL clear_changes) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetPalette(
        HPALETTE *hpal) = 0;

    virtual HRESULT STDMETHODCALLTYPE Draw(
        HDC hdc,
        RECT *bounds) = 0;

    virtual HRESULT STDMETHODCALLTYPE Tile(
        HDC hdc,
        POINT *backorg,
        RECT *clip,
        SIZE *size) = 0;

    virtual HRESULT STDMETHODCALLTYPE StretchBlt(
        HDC hdc,
        int dstX,
        int dstY,
        int dstXE,
        int dstYE,
        int srcX,
        int srcY,
        int srcXE,
        int srcYE,
        DWORD rop) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IImgCtx, 0x3050f3d7, 0x98b5, 0x11cf, 0xbb,0x82, 0x00,0xaa,0x00,0xbd,0xce,0x0b)
#endif
#else
typedef struct IImgCtxVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IImgCtx *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IImgCtx *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IImgCtx *This);

    /*** IImgCtx methods ***/
    HRESULT (STDMETHODCALLTYPE *Load)(
        IImgCtx *This,
        LPCWSTR url,
        DWORD flags);

    HRESULT (STDMETHODCALLTYPE *SelectChanges)(
        IImgCtx *This,
        ULONG changeon,
        ULONG changeoff,
        BOOL signal);

    HRESULT (STDMETHODCALLTYPE *SetCallback)(
        IImgCtx *This,
        PFNIMGCTXCALLBACK fn,
        void *priv);

    HRESULT (STDMETHODCALLTYPE *Disconnect)(
        IImgCtx *This);

    HRESULT (STDMETHODCALLTYPE *GetUpdateRects)(
        IImgCtx *This,
        RECT *rect,
        RECT *img,
        LONG *pcrc);

    HRESULT (STDMETHODCALLTYPE *GetStateInfo)(
        IImgCtx *This,
        ULONG *state,
        SIZE *size,
        BOOL clear_changes);

    HRESULT (STDMETHODCALLTYPE *GetPalette)(
        IImgCtx *This,
        HPALETTE *hpal);

    HRESULT (STDMETHODCALLTYPE *Draw)(
        IImgCtx *This,
        HDC hdc,
        RECT *bounds);

    HRESULT (STDMETHODCALLTYPE *Tile)(
        IImgCtx *This,
        HDC hdc,
        POINT *backorg,
        RECT *clip,
        SIZE *size);

    HRESULT (STDMETHODCALLTYPE *StretchBlt)(
        IImgCtx *This,
        HDC hdc,
        int dstX,
        int dstY,
        int dstXE,
        int dstYE,
        int srcX,
        int srcY,
        int srcXE,
        int srcYE,
        DWORD rop);

    END_INTERFACE
} IImgCtxVtbl;

interface IImgCtx {
    CONST_VTBL IImgCtxVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IImgCtx_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IImgCtx_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IImgCtx_Release(This) (This)->lpVtbl->Release(This)
/*** IImgCtx methods ***/
#define IImgCtx_Load(This,url,flags) (This)->lpVtbl->Load(This,url,flags)
#define IImgCtx_SelectChanges(This,changeon,changeoff,signal) (This)->lpVtbl->SelectChanges(This,changeon,changeoff,signal)
#define IImgCtx_SetCallback(This,fn,priv) (This)->lpVtbl->SetCallback(This,fn,priv)
#define IImgCtx_Disconnect(This) (This)->lpVtbl->Disconnect(This)
#define IImgCtx_GetUpdateRects(This,rect,img,pcrc) (This)->lpVtbl->GetUpdateRects(This,rect,img,pcrc)
#define IImgCtx_GetStateInfo(This,state,size,clear_changes) (This)->lpVtbl->GetStateInfo(This,state,size,clear_changes)
#define IImgCtx_GetPalette(This,hpal) (This)->lpVtbl->GetPalette(This,hpal)
#define IImgCtx_Draw(This,hdc,bounds) (This)->lpVtbl->Draw(This,hdc,bounds)
#define IImgCtx_Tile(This,hdc,backorg,clip,size) (This)->lpVtbl->Tile(This,hdc,backorg,clip,size)
#define IImgCtx_StretchBlt(This,hdc,dstX,dstY,dstXE,dstYE,srcX,srcY,srcXE,srcYE,rop) (This)->lpVtbl->StretchBlt(This,hdc,dstX,dstY,dstXE,dstYE,srcX,srcY,srcXE,srcYE,rop)
#else
/*** IUnknown methods ***/
static inline HRESULT IImgCtx_QueryInterface(IImgCtx* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static inline ULONG IImgCtx_AddRef(IImgCtx* This) {
    return This->lpVtbl->AddRef(This);
}
static inline ULONG IImgCtx_Release(IImgCtx* This) {
    return This->lpVtbl->Release(This);
}
/*** IImgCtx methods ***/
static inline HRESULT IImgCtx_Load(IImgCtx* This,LPCWSTR url,DWORD flags) {
    return This->lpVtbl->Load(This,url,flags);
}
static inline HRESULT IImgCtx_SelectChanges(IImgCtx* This,ULONG changeon,ULONG changeoff,BOOL signal) {
    return This->lpVtbl->SelectChanges(This,changeon,changeoff,signal);
}
static inline HRESULT IImgCtx_SetCallback(IImgCtx* This,PFNIMGCTXCALLBACK fn,void *priv) {
    return This->lpVtbl->SetCallback(This,fn,priv);
}
static inline HRESULT IImgCtx_Disconnect(IImgCtx* This) {
    return This->lpVtbl->Disconnect(This);
}
static inline HRESULT IImgCtx_GetUpdateRects(IImgCtx* This,RECT *rect,RECT *img,LONG *pcrc) {
    return This->lpVtbl->GetUpdateRects(This,rect,img,pcrc);
}
static inline HRESULT IImgCtx_GetStateInfo(IImgCtx* This,ULONG *state,SIZE *size,BOOL clear_changes) {
    return This->lpVtbl->GetStateInfo(This,state,size,clear_changes);
}
static inline HRESULT IImgCtx_GetPalette(IImgCtx* This,HPALETTE *hpal) {
    return This->lpVtbl->GetPalette(This,hpal);
}
static inline HRESULT IImgCtx_Draw(IImgCtx* This,HDC hdc,RECT *bounds) {
    return This->lpVtbl->Draw(This,hdc,bounds);
}
static inline HRESULT IImgCtx_Tile(IImgCtx* This,HDC hdc,POINT *backorg,RECT *clip,SIZE *size) {
    return This->lpVtbl->Tile(This,hdc,backorg,clip,size);
}
static inline HRESULT IImgCtx_StretchBlt(IImgCtx* This,HDC hdc,int dstX,int dstY,int dstXE,int dstYE,int srcX,int srcY,int srcXE,int srcYE,DWORD rop) {
    return This->lpVtbl->StretchBlt(This,hdc,dstX,dstY,dstXE,dstYE,srcX,srcY,srcXE,srcYE,rop);
}
#endif
#endif

#endif


#endif  /* __IImgCtx_INTERFACE_DEFINED__ */

/* Begin additional prototypes for all interfaces */


/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __iimgctx_h__ */

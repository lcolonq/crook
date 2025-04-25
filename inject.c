#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#include <windows.h>
#include "d3d9helper.h"
#include "d3d9.h"
#include "d3dx9tex.h"

#include "dcimgui.h"
#include "dcimgui_impl_dx9.h"

#include "crook.h"

// stub for dinput8
typedef HRESULT (*TYPE_OF_DIRECTINPUT8CREATE)(HINSTANCE, DWORD, REFIID, LPVOID *, LPUNKNOWN);
TYPE_OF_DIRECTINPUT8CREATE ORIGINAL = NULL;
__attribute__((naked)) void DirectInput8Create() { __asm__("jmp *%0"::"m"(ORIGINAL):); }

IDirect3DTexture9 *MRGREEN = NULL;

void *INIT_ADDR = (void *) 0x004d94f0;
int32_t (*INIT_TRAMPOLINE)(HINSTANCE) = NULL;
typedef HRESULT WINAPI (*CREATE_TEX_TYPE)(
    struct IDirect3DDevice9 *device, const WCHAR *srcfile,
    UINT width, UINT height, UINT miplevels, DWORD usage, D3DFORMAT format,
    D3DPOOL pool, DWORD filter, DWORD mipfilter, D3DCOLOR colorkey, D3DXIMAGE_INFO *srcinfo,
    PALETTEENTRY *palette, struct IDirect3DTexture9 **texture);
int32_t init_hook(HINSTANCE handle) {
    puts("hello from the init hook");
    // IDirect3DDevice9 **devptr = (IDirect3DDevice9 **) 0x00db9714;
    // IDirect3DDevice9 *dev = *devptr;
    return INIT_TRAMPOLINE(handle);
}

void *RENDER_ADDR = (void *) 0x004a57a0;
uint8_t (*RENDER_TRAMPOLINE)(void) = NULL;
typedef struct { float x, y, z; DWORD color; } vertex;

void init_imgui(IDirect3DDevice9 *dev) {
    CIMGUI_CHECKVERSION();
    ImGui_CreateContext(NULL);
    ImGui_StyleColorsDark(NULL);
    cImGui_ImplDX9_Init(dev);
    ImGuiIO *io = ImGui_GetIO();
    io->DisplaySize.x = 1000.0;
    io->DisplaySize.y = 1000.0;
}

uint8_t render_hook(void) {
    IDirect3DDevice9 **devptr = (IDirect3DDevice9 **) 0x00db9714;
    IDirect3DDevice9 *dev = *devptr;
    if (!MRGREEN) {
        CREATE_TEX_TYPE create_tex = *((CREATE_TEX_TYPE *) 0x006ad214);
        printf("device: %p, D3DX_DEFAULT: %d\n", dev, D3DX_DEFAULT);
        HRESULT res = create_tex(
            dev,
            L"mrgreen.png",
            0, 0,
            -1, 0, 0, 1, -1, -1, 0, NULL, NULL,
            &MRGREEN);
        printf("texture load result: %ld\nD3DERR_INVALIDCALL: %ld, D3DERR_NOTAVAILABLE: %ld, D3DERR_OUTOFVIDEOMEMORY: %ld, D3DXERR_INVALIDDATA: %d\n", res, D3DERR_INVALIDCALL, D3DERR_NOTAVAILABLE, D3DERR_OUTOFVIDEOMEMORY, D3DXERR_INVALIDDATA);
        init_imgui(dev);
    }
    /* dev->lpVtbl->SetRenderState(dev, D3DRS_ZENABLE, FALSE); */
    /* dev->lpVtbl->SetRenderState(dev, D3DRS_ALPHABLENDENABLE, FALSE); */
    /* dev->lpVtbl->SetRenderState(dev, D3DRS_SCISSORTESTENABLE, FALSE); */
    /* dev->lpVtbl->SetRenderState(dev, D3DRS_LIGHTING, FALSE); */
    /* dev->lpVtbl->SetRenderState(dev, D3DRS_TEXTUREFACTOR, 0xffffffff); */
    /* dev->lpVtbl->SetRenderState(dev, D3DRS_DESTBLEND, D3DBLEND_ZERO); */
    /* dev->lpVtbl->SetRenderState(dev, D3DRS_SRCBLEND, D3DBLEND_ONE); */
    /* dev->lpVtbl->SetRenderState(dev, D3DRS_FILLMODE, D3DFILL_SOLID); */
    /* dev->lpVtbl->SetRenderState(dev, D3DRS_SHADEMODE, D3DSHADE_FLAT); */
    /* dev->lpVtbl->SetRenderState(dev, D3DRS_CULLMODE, D3DCULL_NONE); */
    dev->lpVtbl->SetPixelShader(dev, NULL);
    dev->lpVtbl->SetVertexShader(dev, NULL);
    dev->lpVtbl->SetRenderState(dev, D3DRS_CULLMODE, D3DCULL_NONE);
    dev->lpVtbl->SetRenderState(dev, D3DRS_LIGHTING, FALSE);
    dev->lpVtbl->SetRenderState(dev, D3DRS_ZENABLE, FALSE);
    dev->lpVtbl->SetRenderState(dev, D3DRS_ALPHABLENDENABLE, TRUE);
    dev->lpVtbl->SetRenderState(dev, D3DRS_ALPHATESTENABLE, FALSE);
    dev->lpVtbl->SetRenderState(dev, D3DRS_BLENDOP, D3DBLENDOP_ADD);
    dev->lpVtbl->SetRenderState(dev, D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
    dev->lpVtbl->SetRenderState(dev, D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
    dev->lpVtbl->SetRenderState(dev, D3DRS_SCISSORTESTENABLE, TRUE);
    dev->lpVtbl->SetRenderState(dev, D3DRS_SHADEMODE, D3DSHADE_GOURAUD);
    dev->lpVtbl->SetRenderState(dev, D3DRS_FOGENABLE, FALSE);
    dev->lpVtbl->SetTextureStageState(dev, 0, D3DTSS_COLOROP, D3DTOP_MODULATE);
    dev->lpVtbl->SetTextureStageState(dev, 0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
    dev->lpVtbl->SetTextureStageState(dev, 0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
    dev->lpVtbl->SetTextureStageState(dev, 0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
    dev->lpVtbl->SetTextureStageState(dev, 0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
    dev->lpVtbl->SetTextureStageState(dev, 0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);
    dev->lpVtbl->SetSamplerState(dev, 0, D3DSAMP_MINFILTER, D3DTEXF_POINT);
    dev->lpVtbl->SetSamplerState(dev, 0, D3DSAMP_MAGFILTER, D3DTEXF_POINT);
    HRESULT res;
    // D3DRECT rects[] = { (D3DRECT){ .x1 = 10, .y1 = 10, .x2 = 100, .y2 = 100 } };
    // HRESULT res = dev->lpVtbl->Clear(dev, 1, rects, D3DCLEAR_TARGET, D3DCOLOR_RGBA(127, 0, 0, 255), 0.0, 0);
    // if (res) { printf("failed Clear: %ld\n", res); }
    res = dev->lpVtbl->SetTexture(dev, 0, (IDirect3DBaseTexture9 *) MRGREEN);
    if (res) { printf("failed SetTexture: %ld\n", res); }
    res = dev->lpVtbl->SetFVF(dev, D3DFVF_XYZRHW | D3DFVF_TEX1);
    if (res) { printf("failed SetFVF: %ld\n", res); }
    // res = dev->lpVtbl->SetFVF(dev, D3DFVF_XYZRHW | D3DFVF_DIFFUSE);
    // if (res) { printf("failed SetFVF: %ld\n", res); }
    float verts[] = {
        10.0, 10.0, 1.0, 1.0, 0.0, 0.0,
        100.0, 10.0, 1.0, 1.0, 1.0, 0.0,
        10.0, 100.0, 1.0, 1.0, 0.0, 1.0,
        100.0, 100.0, 1.0, 1.0, 1.0, 1.0,
        // { 320.0f, 50.0f, 1.0f, 1.0f, D3DCOLOR_XRGB(0, 0, 255) },
        // { 520.0f, 400.0f, 1.0f, 1.0f, D3DCOLOR_XRGB(0, 255, 0) },
        // { 120.0f, 400.0f, 1.0f, 1.0f, D3DCOLOR_XRGB(255, 0, 0) },
    };
    // res = dev->lpVtbl->DrawPrimitiveUP(dev, D3DPT_TRIANGLELIST, 1, verts, sizeof(vertex));
    res = dev->lpVtbl->DrawPrimitiveUP(dev, D3DPT_TRIANGLESTRIP, 2, verts, sizeof(float) * 6);
    if (res) { printf("failed DrawPrimitiveUP: %ld\n", res); }
    cImGui_ImplDX9_NewFrame();
    ImGui_NewFrame();
    bool showdemo = true;
    ImGui_ShowDemoWindow(&showdemo);
    ImGui_EndFrame();
    ImGui_Render();
    cImGui_ImplDX9_RenderDrawData(ImGui_GetDrawData());
    dev->lpVtbl->SetRenderState(dev, D3DRS_ZENABLE, FALSE);
    dev->lpVtbl->SetRenderState(dev, D3DRS_ALPHABLENDENABLE, TRUE);
    dev->lpVtbl->SetRenderState(dev, D3DRS_SCISSORTESTENABLE, TRUE);
    dev->lpVtbl->SetFVF(dev, 0x144);
    return RENDER_TRAMPOLINE();
}

BOOLEAN WINAPI DllMain(IN HINSTANCE handle, IN DWORD reason, IN LPVOID reserved) {
    (void) reserved;
    switch (reason) {
    case DLL_PROCESS_ATTACH:
        puts("attached!");
        if (ORIGINAL == NULL) {
            puts("loading...");
            char buf[MAX_PATH];
            GetSystemDirectoryA(buf, MAX_PATH);
            strncat(buf, "\\dinput8.dll", MAX_PATH - 1);
            HMODULE lib = LoadLibraryA(buf);
            ORIGINAL = (TYPE_OF_DIRECTINPUT8CREATE) GetProcAddress(lib, "DirectInput8Create");
            printf("loaded! %p\n", ORIGINAL);
        }
        puts("pre-trampoline");
        INIT_TRAMPOLINE = trampoline_32(INIT_ADDR, init_hook);
        RENDER_TRAMPOLINE = trampoline_32(RENDER_ADDR, render_hook);
        puts("post-trampoline");
        break;
    case DLL_PROCESS_DETACH:
        puts("detached!");
        break;
    }
    return TRUE;
}

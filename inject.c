#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#define WIN32_LEAN_AND_MEAN

#include "windows.h"
#include "d3d9helper.h"
#include "d3d9.h"
#include "d3dx9tex.h"
#include "winsock2.h"
#include "ws2tcpip.h"

#define IMGUI_BACKEND_HAS_WINDOWS_H 1
#include "dcimgui.h"
#include "dcimgui_impl_dx9.h"
#include "dcimgui_impl_win32.h"

#include "crook.h"

int COINS_LAST = 0;
void *COINS_ADDR = (void *) 0x03eb7d6c;

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
    // IDirect3DDevice9 **devptr = (IDirect3DDevice9 **) 0x00db9714;
    // IDirect3DDevice9 *dev = *devptr;
    void *addr = NULL;
    find_signature(&addr, 1, (signature){
            // 0x55,
            // 0x8b, 0xec,
            // 0x81, 0xec, 0x68, 0x01, 0x00, 0x00,
            // 0xa1, 0x20, 0x0c, 0x6d, 0x00,
            SIGNATURE_WILDCARD,
            SIGNATURE_WILDCARD, SIGNATURE_WILDCARD,
            SIGNATURE_WILDCARD, SIGNATURE_WILDCARD, 0x68, 0x01, 0x00, 0x00,
            0xa1, 0x20, 0x0c, 0x6d, 0x00,
            0x33, 0xc5,
            SIGNATURE_END
        });
    printf("address we found: %p\n", addr);
    return INIT_TRAMPOLINE(handle);
}

void *WNDPROC_ADDR = (void *) 0x004da1c0;
LRESULT WINAPI (*WNDPROC_TRAMPOLINE)(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) = NULL;
LRESULT WINAPI wndproc_hook(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    if (cImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam)) return true;
    return WNDPROC_TRAMPOLINE(hWnd, msg, wParam, lParam);
}

void *RENDER_ADDR = (void *) 0x004a57a0;
uint8_t (*RENDER_TRAMPOLINE)(void) = NULL;
typedef struct { float x, y, z, rhw; DWORD color; } vertex;

void init_imgui(HWND win, IDirect3DDevice9 *dev) {
    CIMGUI_CHECKVERSION();
    ImGui_CreateContext(NULL);
    ImGui_StyleColorsDark(NULL);
    cImGui_ImplWin32_Init(win);
    cImGui_ImplDX9_Init(dev);
    // ImGuiIO *io = ImGui_GetIO();
    // io->DisplaySize.x = 1000.0;
    // io->DisplaySize.y = 1000.0;
}

WSADATA WSA;
SOCKET BUS = INVALID_SOCKET;
void init_network() {
    int res = WSAStartup(MAKEWORD(2, 2), &WSA);
    if (res) panic("failed to initialized winsock: %d\n", res);

    struct addrinfo *result = NULL, hints;
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    res = getaddrinfo("shiro", "32050", &hints, &result);
    if (res) panic("failed to resolve address: %d\n", res);
    BUS = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (BUS == INVALID_SOCKET) panic("failed to create socket");
    res = connect(BUS, result->ai_addr, (int) result->ai_addrlen);
    if (res == SOCKET_ERROR) panic("failed to connect");
    long unsigned int mode = 1;
    ioctlsocket(BUS, FIONBIO, &mode);
}

char BUS_BUFFER[4096];
size_t BUS_CURSOR = 0;
void bus_handle_msg(char *msg) {
    printf("message received: %s\n", msg);
    *((int *) COINS_ADDR) += 1;
}
bool bus_handle_line() {
    for (size_t i = 0; i < sizeof(BUS_BUFFER); ++i) {
        if (BUS_BUFFER[i] == '\n') {
            BUS_BUFFER[i] = 0;
            bus_handle_msg(BUS_BUFFER);
            size_t len = i + 1;
            memmove(BUS_BUFFER, BUS_BUFFER + len, len);
            BUS_CURSOR -= len;
            return true;
        }
    }
    return false;
}
void bus_recv_and_dispatch() {
    char buf[4096] = {0};
    ssize_t len = recv(BUS, buf, sizeof(buf), 0);
    if (len < 0) return;
    if (BUS_CURSOR + len >= sizeof(BUS_BUFFER)) panic("recv buffer overflow");
    memcpy(BUS_BUFFER + BUS_CURSOR, buf, len);
    BUS_CURSOR += len;
    while (bus_handle_line());
}

void bus_send(char *msg) {
    size_t len = strlen(msg);
    int res = send(BUS, msg, (int) len, 0);
    if (res == SOCKET_ERROR) panic("failed to send: %s\n", msg);
}

uint8_t render_hook(void) {
    IDirect3DDevice9 **devptr = (IDirect3DDevice9 **) 0x00db9714;
    IDirect3DDevice9 *dev = *devptr;
    HWND *winptr = (HWND *) 0x00db6bf4;
    HWND win = *winptr;
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
        init_imgui(win, dev);
        init_network();
        bus_send("(pub (monitor lamulana test) ())\n");
        bus_send("(sub (monitor lamulana msg))\n");
    }
    bus_recv_and_dispatch();
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
    float verts[] = {
        10.0, 10.0, 1.0, 1.0, 0.0, 0.0,
        500.0, 10.0, 1.0, 1.0, 1.0, 0.0,
        10.0, 500.0, 1.0, 1.0, 0.0, 1.0,
        500.0, 500.0, 1.0, 1.0, 1.0, 1.0,
    };
    // res = dev->lpVtbl->DrawPrimitiveUP(dev, D3DPT_TRIANGLESTRIP, 2, verts, sizeof(float) * 6);
    // if (res) { printf("failed DrawPrimitiveUP: %ld\n", res); }
    cImGui_ImplDX9_NewFrame();
    cImGui_ImplWin32_NewFrame();
    ImGui_NewFrame();
    bool showdemo = true;
    ImGui_ShowDemoWindow(&showdemo);
    {
        int coins = *(int *) COINS_ADDR;
        if (coins != COINS_LAST) {
            COINS_LAST = coins;
            char buf[256] = {};
            snprintf(buf, sizeof(buf), "(pub (monitor lamulana test) %d)\n", coins);
            bus_send(buf);
        }
        ImGui_Begin("collecting coins", NULL, 0);
        ImGui_SliderInt("cash NOW", (int *) COINS_ADDR, -10, 10000);
        ImGui_End();
    }
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
        WNDPROC_TRAMPOLINE = trampoline_32(WNDPROC_ADDR, wndproc_hook);
        RENDER_TRAMPOLINE = trampoline_32(RENDER_ADDR, render_hook);
        puts("post-trampoline");
        break;
    case DLL_PROCESS_DETACH:
        puts("detached!");
        break;
    }
    return TRUE;
}

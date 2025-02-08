#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#include <windows.h>

#include "crook.h"

// stub for libguy
int get_guy() {
    return 99;
}

// stub for dinput8
typedef HRESULT (*thefunctionxd)(HINSTANCE, DWORD, REFIID, LPVOID *, LPUNKNOWN);
thefunctionxd ORIGINAL = NULL;
__attribute__((naked)) void DirectInput8Create() { __asm__("jmp *%0"::"m"(ORIGINAL):); }

int bar(int x) {
    printf("bar: %d\n", x);
    return x;
}

int (*foo_trampoline)(int) = NULL;
int baz(int x) {
    int y = foo_trampoline(x);
    int z = y + 100;
    printf("baz: %d\n", z);
    return z;
}

void *FOO_ADDR = (void *) 0x00000001400014b4;

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
            ORIGINAL = (thefunctionxd) GetProcAddress(lib, "DirectInput8Create");
            printf("loaded! %p\n", ORIGINAL);
        }
        puts("pre-trampoline");
        foo_trampoline = TRAMPOLINE(FOO_ADDR, baz);
        puts("post-trampoline");
        break;
    case DLL_PROCESS_DETACH:
        puts("detached!");
        break;
    }
    return TRUE;
}

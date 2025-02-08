#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#include <windows.h>

#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>

int foo(int x) {
    int y = x * 2;
    printf("foo: %d\n", y);
    return y;
}

int main() {
    HINSTANCE h = GetModuleHandle(NULL);
    void *v = NULL;
    puts("before");
    DirectInput8Create(h, 0x0800, &IID_IDirectInput8W, &v, NULL);
    printf("hello computer, foo is 0x%p\n", foo);
    int res = foo(10);
    printf("result: %d\n", res);
    return EXIT_SUCCESS;
}

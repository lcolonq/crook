CC = x86_64-w64-mingw32-gcc
CC32 = i686-w64-mingw32-gcc
CFLAGS_TEST = -Wall -g
CFLAGS_INJECT = -Wall -g -lcapstone

.PHONY: run debug

test.exe: test.c
	$(CC) $< $(CFLAGS_TEST) -L. -ldinput8 -ldxguid -o $@

test32.exe: test.c
	$(CC32) $< $(CFLAGS_TEST) -L. -ldinput8 -ldxguid -o $@

inject.dll: inject.c
	$(CC) -DTRAMPOLINE=trampoline_64 $< $(CFLAGS_INJECT) -shared -o $@

inject32.dll: inject.c
	$(CC32) -DTRAMPOLINE=trampoline_32 $< -L/nix/store/5pmimd5qj4g1fdzq4i3ky24cp6xc9vj9-capstone-i686-w64-mingw32-5.0.3/lib $(CFLAGS_INJECT) -shared -o $@

libguy.dll: libguy.c
	$(CC) $< $(CFLAGS_TEST) -shared -o $@

run: test.exe
	wine64 $<

debug: test.exe
	wine64 bin/gdbserver.exe 'localhost:31337' $< 

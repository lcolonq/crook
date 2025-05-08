CC = x86_64-w64-mingw32-gcc
CC32 = i686-w64-mingw32-gcc
CXX32 = i686-w64-mingw32-g++
CFLAGS_INJECT = -Wall -g -lcapstone -L. -limgui -Iheaders/ -Iheaders/windows/ -Iimgui/dcimgui/ -Iimgui/dcimgui/backends/ -Iimgui/imgui/ -lws2_32 -mwindows
CFLAGS_IMGUI = -Iimgui/imgui/ -Iimgui/dcimgui/ -Iimgui/imgui/backends/ -ldwmapi -mwindows

.PHONY: all clean run

all: inject_lamulana.dll

# inject.dll: inject.c crook.h
# 	$(CC) -DCROOK_64BIT=1 -DTRAMPOLINE=trampoline_64 -DFOO=0x00000001400014b4 $< $(CFLAGS_INJECT) -shared -o $@

inject_lamulana.dll: inject.c crook.h imgui.dll
	$(CC32) -DTRAMPOLINE=trampoline_32 -DFOO=0x0040147c $< -L$(CAPSTONE32_PATH)/lib $(CFLAGS_INJECT) -shared -o $@

imgui.dll: imgui/dcimgui/dcimgui.cpp imgui/dcimgui/backends/dcimgui_impl_dx9.cpp imgui/dcimgui/backends/dcimgui_impl_win32.cpp imgui/imgui/*.cpp imgui/imgui/backends/imgui_impl_dx9.cpp imgui/imgui/backends/imgui_impl_win32.cpp
	$(CXX32) $^ $(CFLAGS_IMGUI) -shared -o $@

imgui.a: imgui/dcimgui/dcimgui.cpp imgui/dcimgui/backends/dcimgui_impl_dx9.cpp imgui/dcimgui/backends/dcimgui_impl_win32.cpp imgui/imgui/*.cpp imgui/imgui/backends/imgui_impl_dx9.cpp imgui/imgui/backends/imgui_impl_win32.cpp
	$(CXX32) $^ $(CFLAGS_IMGUI) -static -o $@

clean:
	rm -f inject_lamulana.dll

run: inject_lamulana.dll
	cd lamulana_runtime && WINEDLLOVERRIDES="dinput8=n,b" wine LaMulanaWin.exe

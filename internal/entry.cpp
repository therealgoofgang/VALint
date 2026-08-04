	#include "./cheat.h";
#include "xorstring.h"
#include <Windows.h>
#include <winternl.h>
#include <ntstatus.h>
#include "jcode.hpp"


void call_draw_transition_hook(uintptr_t* viewportclient, UCanvas* _canvas, std::uintptr_t a3) {
	return reinterpret_cast<void(*)(uintptr_t * viewportclient, UCanvas * _canvas, std::uintptr_t a3, uintptr_t, void*)>(spoofcall_stub)(viewportclient, _canvas, a3, Offsets::MagicOffsets, (void*)PostRender);
}

typedef enum _MEMORY_INFORMATION_CLASS {
    MemoryBasicInformation
} MEMORY_INFORMATION_CLASS;

extern "C" NTSTATUS __query_virtual_memory(
    HANDLE p_handle,
    void* base_addr,
    MEMORY_INFORMATION_CLASS memory_info_class,
    void* mbi,
    std::size_t mbi_length,
    std::size_t* mbi_out_length
);


class shadow_vmt
{
public:
    template <typename type>
    bool hook(uint64_t module_base, uint64_t address, int index, void* function, type* original)
    {
        this->virtual_table = *(uintptr_t**)(address);
        if (reinterpret_cast<void*>(this->virtual_table[index]) != function)
        {
            while (this->virtual_table[this->vtable_size])
            {
                this->vtable_size++;
            }
            if (index < this->vtable_size)
            {

                this->allocated_vtable = reinterpret_cast<uintptr_t*>(
                    spoofed_malloc(this->vtable_size * sizeof(uintptr_t), PAGE_EXECUTE_READWRITE)
                    );

                for (int i = 0; i < this->vtable_size; i++)
                {
                    this->allocated_vtable[i] = this->virtual_table[i];
                }
                *original = reinterpret_cast<type>(this->virtual_table[index]);
                this->allocated_vtable[index] = reinterpret_cast<uintptr_t>(function);
                *(uintptr_t**)(address) = this->allocated_vtable;
                return true;
            }
        }
        return false;
    }

private:

    uint64_t spoofed_malloc(int32_t size, uint32_t alignment)
    {
        return reinterpret_cast<uint64_t(__cdecl*)(int32_t, uint32_t, uintptr_t, void*)>(spoofcall_stub)(
            size,
            alignment,
            0x46C4660,
            (void*)&fmemory::malloc
            );
    }

    uintptr_t* virtual_table;
    uintptr_t* allocated_vtable;
    int vtable_size;
};

void CheatInit() {

    SPOOF_FUNC;

    auto base = Memory::get_module(ez(L"VALORANT-Win64-Shipping.exe").d());
    if (!base)
        return;
    VALORANT::Module = base;
    initialize_spoofcall(reinterpret_cast<uint8_t*>(base));

    classes::init();

    uintptr_t* gworld = *(uintptr_t**)(base + Offsets::State);
    auto WorldPtr = *(UWorld**)gworld;
    keys::space = kismentsystemlibrary::Conv_StringToName(L"SpaceBar");
    keys::insert = kismentsystemlibrary::Conv_StringToName(L"Insert");
    keys::left_mouse = kismentsystemlibrary::Conv_StringToName(L"LeftMouseButton");

    keys::w = kismentsystemlibrary::Conv_StringToName(L"W");
    keys::A = kismentsystemlibrary::Conv_StringToName(L"A");
    keys::s = kismentsystemlibrary::Conv_StringToName(L"S");
    keys::d = kismentsystemlibrary::Conv_StringToName(L"D");

    if (G::GameInstance = GameplayStatics::get_game_instance(WorldPtr)) {

        if (ULocalPlayer* LocalPlayers = Memory::R<ULocalPlayer*>((uintptr_t)G::GameInstance + 0x40))
        {
            if (G::LocalPlayer = Memory::R<ULocalPlayer*>((uintptr_t)LocalPlayers))
            {
                if (UObject* game_engine = kismentsystemlibrary::get_outer_object(G::GameInstance))
                {
                    if (DefaultMediumFont = Memory::R<UObject*>((uintptr_t)game_engine + 0x60))
                    {
                        if (auto Viewport = G::LocalPlayer->ViewportClient())
                        {
                            static shadow_vmt viewport_hook;

                            bool hook_success = viewport_hook.hook<decltype(pRender)>(
                                base,                                    // module_base
                                (uintptr_t)Viewport,                     // address de l'objet viewport
                                0x68,                                    // index dans la VMT
                                (void*)call_draw_transition_hook,        // fonction de hook
                                &pRender                                 // pointeur vers l'original
                            );

                            if (!hook_success) {
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
}


void random_delay() {
	int delay_ms = rand() % 2000 + 500;  // Random delay between 500ms and 2500ms
	Sleep(delay_ms);
}




extern "C" __declspec(dllexport) int dsqdqsdfff(int code, WPARAM wParam, LPARAM lParam) {

	SPOOF_FUNC;
	return CallNextHookEx(NULL, code, wParam, lParam);

}
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {

	SPOOF_FUNC;
	if (ul_reason_for_call != DLL_PROCESS_ATTACH)
		return TRUE;

#ifndef DEV
    HMODULE handle = NULL;
    BOOL ret = GetModuleHandleExW(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_PIN, (LPCWSTR)DllMain, &handle);
    if (!ret)
        MessageBoxA(0, "DLL PINNING FAILED!", "HAZE", 0);
#endif

	using DisableFunc = BOOL(WINAPI*)(HMODULE);
	auto disableCalls = reinterpret_cast<DisableFunc>(
	SPOOF_CALL(Memory::resolve_api)("kernel32.dll", "DisableThreadLibraryCalls"));
	if (disableCalls) disableCalls(hModule);
	SPOOF_CALL(Memory::clear_pe_header)(hModule);
	SPOOF_CALL(Beep)(501, 500);
	SPOOF_CALL(CheatInit)();


	return TRUE;
}


		





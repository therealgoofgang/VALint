#pragma once

#include <cstdint>
#define MAX_VMT_METHODS 512

void* FindWritableRDataSpace(size_t sizeRequired) {
    HMODULE hModule = GetModuleHandle(nullptr);
    MODULEINFO modInfo = {};
    GetModuleInformation(GetCurrentProcess(), hModule, &modInfo, sizeof(modInfo));

    uint8_t* base = (uint8_t*)modInfo.lpBaseOfDll;
    uint8_t* end = base + modInfo.SizeOfImage;

    for (uint8_t* ptr = base; ptr < end; ptr += 0x1000) {
        MEMORY_BASIC_INFORMATION mbi;
        VirtualQuery(ptr, &mbi, sizeof(mbi));

        if ((mbi.Protect & (PAGE_READWRITE | PAGE_WRITECOPY | PAGE_EXECUTE_READWRITE)) && mbi.State == MEM_COMMIT) {
            size_t space = mbi.RegionSize;
            for (size_t offset = 0; offset + sizeRequired <= space; offset += sizeof(void*)) {
                bool found = true;
                for (size_t i = 0; i < sizeRequired; i++) {
                    if (ptr[offset + i] != 0x00) {
                        found = false;
                        break;
                    }
                }
                if (found)
                    return &ptr[offset];
            }
        }
    }
    return nullptr;

}

void** originalVMT = nullptr;
    void** customVMT = nullptr;
    int methodCount = 0;
    int hookIndex = -1;
    void* originalFn = nullptr;

    void reinstract(void* instance, void* hookFunction, int index) {
        originalVMT = *(void***)instance;
        hookIndex = index;

        // Count methods
        while (originalVMT[methodCount] && methodCount < MAX_VMT_METHODS) {
            methodCount++;
        }

        // Allocate stealth space in module's writable memory
        customVMT = (void**)FindWritableRDataSpace(methodCount * sizeof(void*)); // Stealthy way u fucking gian nigga
        if (!customVMT) return;

        // Copy original VMT because Shadow is our legit mememory :P
        for (int i = 0; i < methodCount; ++i)
            customVMT[i] = originalVMT[i];

        // Store original function and hook
        originalFn = originalVMT[index];
        customVMT[index] = hookFunction;

        // Replace instance's vtable
        DWORD old;
        VirtualProtect(instance, sizeof(void*), PAGE_READWRITE, &old);
        *(void***)instance = customVMT;
        VirtualProtect(instance, sizeof(void*), old, &old);
    }

namespace Hook
{
    void VMT(void* Addr, void* PDes, int Index, void** Ret) {

        // Validate the provided address
        if (!Addr) {
       
            return;
        }

        // Get the VMT (Virtual Method Table) by dereferencing Addr
        auto VTable = *reinterpret_cast<std::uintptr_t**>(Addr);
        if (!VTable) {
          
            return;
        }

        // Find the number of methods in the VMT (null-terminated)
        int Methods = 0;
        while (VTable[Methods] != 0) {  // VMT is typically null-terminated
            ++Methods;
        }

        if (Index >= Methods || Index < 0) {
            
            return;
        }

        // Backup the original function pointer at the specified index
        *Ret = reinterpret_cast<void*>(VTable[Index]);

        // Create a new VMT array with the same number of methods
        auto VTableBuf = std::make_unique<std::uintptr_t[]>(Methods);
        std::memcpy(VTableBuf.get(), VTable, Methods * sizeof(std::uintptr_t));

        // Hook the function at the specified index
        VTableBuf[Index] = reinterpret_cast<std::uintptr_t>(PDes);


        // Replace the VMT pointer in the object with the new hooked VMT
        *reinterpret_cast<std::uintptr_t**>(Addr) = VTableBuf.release();

        
    }

	void vhook(void* addr, void* pDes, int index, void** ret) {

		auto vtable = Memory::R<uintptr_t*>(std::uintptr_t(addr));
		int methods = 0;

		for (int i = 0; Memory::R<uintptr_t>((uintptr_t)vtable + (i * 0x8)); i++) methods++;

		auto vtable_buf = new uint64_t[methods * 0x8];
		for (int count = 0; count < methods; ++count) {
			vtable_buf[count] = Memory::R<uintptr_t>((uintptr_t)vtable + (count * 0x8));

			*ret = (void*)vtable[index];

			vtable_buf[index] = (uintptr_t)(pDes);
			*(uint64_t**)(std::uintptr_t(addr)) = vtable_buf;
			//memory::write<uint64_t*>(std::uintptr_t(addr), vtable_buf);
		}

	}

	
}
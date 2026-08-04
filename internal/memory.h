#pragma once
#include <cstdint>
#include "offsets.h"
#include "unrealengine.h"
#include <Psapi.h>
#include <vector>
#include "definitions.hpp"
#include "importher.hpp"
#include <Psapi.h>
#include <vector>
#include <softintrin.h>
#include "Hookign/spoofer.h"
#include "Hookign/ret_spoofing.h"

namespace Memory
{
    inline bool is_bad_write_ptr(LPVOID ptr, uint64_t size)
    {
        SPOOF_FUNC;
        return ptr ? false : true;
    }

    inline bool valid_pointer(uint64_t address)
    {
        SPOOF_FUNC;
        if (!is_bad_write_ptr((LPVOID)address, (uint64_t)8)) return true;
        else return false;
    }

    template<typename t>
    inline t R(DWORD_PTR address, const t& def = t())
    {
        SPOOF_FUNC;
        if (valid_pointer(address)) {
            return *(t*)(address);
        }
    }

    template<typename t>
    inline bool W(DWORD_PTR address, const t& value)
    {
        SPOOF_FUNC;
        if (valid_pointer(address)) {
            *(t*)(address) = value;
            return true;
        }
        return false;
    }
    //template <typename T>
    //__forceinline T R(std::uintptr_t address) {
    //    SPOOF_FUNC;
    //    return *reinterpret_cast<T*>(address);
    //}

    //template <typename T>
    //__forceinline void W(std::uintptr_t address, T value) {
    //    SPOOF_FUNC;
    //    *reinterpret_cast<T*>(address) = value;
    //}


    //template<typename t>
    //inline t R(DWORD_PTR address, const t& def = t())
    //{
    //    SPOOF_FUNC;
    //    if (valid_pointer(address)) {
    //        SPOOF_FUNC;
    //        return *(t*)(address);
    //    }
    //}

    //template<typename t>
    //inline bool W(DWORD_PTR address, const t& value)
    //{
    //    SPOOF_FUNC;
    //    if (valid_pointer(address)) {
    //        SPOOF_FUNC;
    //        *(t*)(address) = value;
    //        return true;
    //    }
    //    return false;
    //}

    inline bool IsValidPointer(uintptr_t address) {
        MEMORY_BASIC_INFORMATION mbi;
        if (!VirtualQuery(reinterpret_cast<LPCVOID>(address), &mbi, sizeof(mbi))) {
            return false;
        }
        if (mbi.Protect & (PAGE_GUARD | PAGE_NOACCESS)) {
            return false;
        }
        return true;
    }

    inline uintptr_t resolve_api(const char* module, const char* func) {
        auto hMod = LoadLibraryA(module);
        return reinterpret_cast<uintptr_t>(GetProcAddress(hMod, func));
    }

    inline void clear_pe_header(HMODULE hModule) {
        DWORD old;
        VirtualProtect(hModule, 0x1000, PAGE_EXECUTE_READWRITE, &old);
        memset(hModule, 0, 0x1000);
        VirtualProtect(hModule, 0x1000, old, &old);
    }


    inline uint64_t get_module(wchar_t* name) {
        SPOOF_FUNC;
        const ntos::peb* peb = reinterpret_cast<ntos::peb*>(__readgsqword(0x60));
        if (!peb) return uint64_t(0);

        const ntos::list_entry head = peb->Ldr->InMemoryOrderModuleList;

        for (auto curr = head; curr.Flink != &peb->Ldr->InMemoryOrderModuleList; curr = *curr.Flink) {
            ntos::ldr_data_table_entry* mod = reinterpret_cast<ntos::ldr_data_table_entry*>(contains_record(curr.Flink, ntos::ldr_data_table_entry, InMemoryOrderLinks));

            if (mod->BaseDllName.Buffer)
                if (crt::wcsicmp_insensitive(mod->BaseDllName.Buffer, name))
                {
                    return uint64_t(mod->DllBase);
                }
        }

        return uint64_t(0);
    }


    template<typename T>
    class simple_data_locator {
        T* _data;
        size_t capacity;
        size_t length;

    public:
        simple_data_locator() : _data(nullptr), capacity(0), length(0) {}

        ~simple_data_locator() {
            SPOOF_FUNC;
            LI_FN(free)(_data);
        }

        void push_back(T value) {
            SPOOF_FUNC;
            if (length == capacity) {
                capacity = capacity == 0 ? 1 : capacity * 2;
                _data = (T*)LI_FN(realloc)(_data, capacity * sizeof(T));
            }
            _data[length++] = value;
        }

        T operator[](size_t index) const {
            SPOOF_FUNC;
            return _data[index];
        }

        size_t size() const {
            SPOOF_FUNC;
            return length;
        }

        T* data() {
            SPOOF_FUNC;
            return _data;
        }

        const T* data() const {
            SPOOF_FUNC;
            return _data;
        }
    };

    uint64_t ida_scanner(uint64_t module_base, const char* signature, int p_index, bool relativeAddress)
    {
        SPOOF_FUNC;
        auto pattern_to_byte = [](const char* pattern) -> simple_data_locator<int>
            {
                simple_data_locator<int> bytes;
                auto start = const_cast<char*>(pattern);
                auto end = const_cast<char*>(pattern) + LI_FN(strlen)(pattern);

                for (auto current = start; current < end; ++current)
                {
                    if (*current == '?')
                    {
                        ++current;
                        if (*current == '?') ++current;
                        bytes.push_back(-1);
                    }
                    else
                    {
                        bytes.push_back(LI_FN(strtoul)(current, &current, 16));
                    }
                }
                return bytes;
            };

        auto dos_header = reinterpret_cast<PIMAGE_DOS_HEADER>(module_base);
        auto nt_headers = reinterpret_cast<PIMAGE_NT_HEADERS>((reinterpret_cast<uint8_t*>(module_base) + dos_header->e_lfanew));
        auto text_section = reinterpret_cast<PIMAGE_SECTION_HEADER>(IMAGE_FIRST_SECTION(nt_headers));

        auto size_of_image = text_section->SizeOfRawData;
        auto pattern_bytes = pattern_to_byte(signature);
        auto scan_bytes = reinterpret_cast<uint8_t*>(module_base) + text_section->VirtualAddress;

        auto s = pattern_bytes.size();
        auto d = pattern_bytes.data();

        auto mbi = MEMORY_BASIC_INFORMATION{ 0 };
        uint8_t* next_address = 0;

        for (auto i = 0ul; i < size_of_image - s; ++i)
        {
            bool found = true;
            for (auto j = 0ul; j < s; ++j)
            {
                auto current_address = scan_bytes + i + j;
                if (current_address >= next_address)
                {
                    if (!LI_FN(VirtualQuery)(reinterpret_cast<void*>(current_address), &mbi, sizeof(mbi)))
                    {
                        break;
                    }

                    if (mbi.Protect == PAGE_NOACCESS)
                    {
                        i += ((reinterpret_cast<uintptr_t>(mbi.BaseAddress) + mbi.RegionSize) - (reinterpret_cast<uintptr_t>(scan_bytes) + i));
                        i--;
                        found = false;
                        break;
                    }
                    else
                    {
                        next_address = reinterpret_cast<uint8_t*>(mbi.BaseAddress) + mbi.RegionSize;
                    }
                }

                if (scan_bytes[i + j] != d[j] && d[j] != -1)
                {
                    found = false;
                    break;
                }
            }

            if (found)
            {
                if (relativeAddress)
                {
                    return static_cast<uintptr_t>(reinterpret_cast<uintptr_t>(&scan_bytes[i]) + *reinterpret_cast<const int*>(reinterpret_cast<uintptr_t>(&scan_bytes[i]) + (p_index - sizeof(int))) + p_index);
                }
                else
                {
                    return reinterpret_cast<uintptr_t>(&scan_bytes[i]);
                }
            }
        }

        return NULL;
    }

}
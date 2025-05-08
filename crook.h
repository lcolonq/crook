#pragma once

#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#include <windows.h>

#include <capstone/capstone.h>

void panic_(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
    exit(EXIT_FAILURE);
}

#define STRSTR(x) #x
#define STR(x) STRSTR(x)
#define panic(format, ...) panic_("error [" __FILE__ ":" STR(__LINE__) "] " format "\n" __VA_OPT__(,) __VA_ARGS__)

void unprotect(void *target, size_t len) {
    DWORD old;
    if (!VirtualProtect(target, len, PAGE_EXECUTE_READWRITE, &old)) {
        panic("failed to unprotect memory");
    }
}

typedef int32_t signature[];
#define SIGNATURE_WILDCARD -1
#define SIGNATURE_END -42
size_t signature_len(signature sig) {
    size_t i = 0;
    for (; sig[i] != SIGNATURE_END; ++i);
    return i;
}
bool match_signature(signature sig, uint8_t *buf) {
    for (size_t i = 0; sig[i] != SIGNATURE_END; ++i) {
        if (sig[i] >= 0 && sig[i] <= 0xff) {
            uint8_t expected = (uint8_t) sig[i];
            if (expected != buf[i]) return false;
        } else switch (sig[i]) {
            case SIGNATURE_WILDCARD: break;
            default:
                panic("unknown signature matcher %d", sig[i]);
                break;
        }
    }
    return true;
}
size_t find_signature(void *out[], size_t outlen, signature sig) {
    HMODULE hmod = GetModuleHandle(NULL);
    IMAGE_DOS_HEADER *dos_header = (IMAGE_DOS_HEADER *) hmod;
    int32_t offset = dos_header->e_lfanew;
    IMAGE_NT_HEADERS *nt_headers = (IMAGE_NT_HEADERS *) ((uint8_t *) hmod + offset);
    printf("the pe signature: %s\n", (char *) &(nt_headers->Signature));
    printf("the signature length: %u\n", signature_len(sig));
    size_t siglen = signature_len(sig);
    size_t outidx = 0;

    for (int i = 0; i < nt_headers->FileHeader.NumberOfSections; ++i) {
        IMAGE_SECTION_HEADER *sec = IMAGE_FIRST_SECTION(nt_headers) + i;
        uint8_t *addr = (uint8_t *) hmod + sec->VirtualAddress;
        printf("section %d: %p (size %ld)\n", i, addr, sec->SizeOfRawData);
        size_t maxoff = sec->SizeOfRawData - siglen;
        for (size_t off = 0; off < maxoff; ++off) {
            if (match_signature(sig, addr + off)) {
                printf("found match at: %p\n", addr + off);
                if (outidx < outlen) {
                    out[outidx] = addr + off;
                    outidx += 1;
                    if (outidx >= outlen) return outidx;
                }
            }
        }
    }
}

void *trampoline_alloc(size_t len) {
    void *mem = calloc(len, 1);
    unprotect(mem, len);
    return mem;
}

#ifndef CROOK_64BIT
void destructive_hook_32(void *target, void *hook) {
    uint8_t template[] = {0xe9, 0x00, 0x00, 0x00, 0x00};
    size_t len = sizeof(template);
    int32_t diff = (int32_t) hook - ((int32_t) target + (int32_t) len);
    if (diff > INT32_MAX || diff < INT32_MIN) panic("it's too far");
    uint32_t offset = (uint32_t) diff;
    *((uint32_t *)(template+1)) = offset;
    uint8_t *tbytes = (uint8_t *) target;
    unprotect(target, len);
    for (int i = 0; i < len; ++i) {
        tbytes[i] = template[i];
    }
}

void *build_trampoline_32(void *target, size_t len) {
    uint8_t template[] = {
        0xe9, 0x00, 0x00, 0x00, 0x00
    };
    size_t tlen = sizeof(template);
    uint8_t *ret = trampoline_alloc(len + tlen);
    uint32_t toff = (uint32_t) target + len;
    int32_t diff = (int32_t) toff - ((int32_t) ret + (int32_t) len + (int32_t) tlen);
    *((uint32_t *)(template+1)) = diff;
    uint8_t *tbytes = (uint8_t *) target;
    for (int i = 0; i < len; ++i) {
        ret[i] = tbytes[i];
    }
    for (int i = 0; i < tlen; ++i) {
        ret[len+i] = template[i];
    }
    return ret;
}

void dump_function_32(void *target, size_t len) {
    csh handle;
    cs_insn *insn;
    if (cs_open(CS_ARCH_X86, CS_MODE_32, &handle) != CS_ERR_OK) {
        panic("failed to open capstone handler");
    }
    size_t count = cs_disasm(handle, target, len, 0, 0, &insn);
    for (int i = 0; i < count; ++i) {
        printf("%llx %s %s\n", insn[i].address, insn[i].mnemonic, insn[i].op_str);
    }
    cs_free(insn, count);
    cs_close(&handle);
}

size_t round_to_next_instruction_32(void *target, size_t len) {
    csh handle;
    cs_insn *ins;
    if (cs_open(CS_ARCH_X86, CS_MODE_32, &handle) != CS_ERR_OK) {
        panic("failed to open capstone handler");
    }
    // 15 is max size of x86 instruction
    size_t count = cs_disasm(handle, target, len + 15, 0, 0, &ins);
    size_t ret = 0;
    printf("patching instructions at 0x%p:\n", target);
    for (int i = 0; i < count; ++i) {
        printf(" 0x%p+%llx: %s %s\n", target, ins[i].address, ins[i].mnemonic, ins[i].op_str);
        if (ins[i].address >= len) {
            ret = ins[i].address;
            break;
        }
    }
    if (ret < len) panic("could not identify instruction after %u bytes", len);
    cs_free(ins, count);
    cs_close(&handle);
    return ret;
}

uint8_t TRAMPOLINE_TEMPLATE_32[] = {
    0xe9, 0x00, 0x00, 0x00, 0x00,
};
size_t TRAMPOLINE_TEMPLATE_LEN_32 = sizeof(TRAMPOLINE_TEMPLATE_32);
void install_trampoline_hook_32(void *target, void *hook) {
    unprotect(target, TRAMPOLINE_TEMPLATE_LEN_32);
    int32_t diff = (int32_t) hook - ((int32_t) target + (int32_t) TRAMPOLINE_TEMPLATE_LEN_32);
    uint32_t offset = (uint32_t) diff;
    uint8_t *tbytes = (uint8_t *) target;
    for (int i = 0; i < TRAMPOLINE_TEMPLATE_LEN_32; ++i) {
        tbytes[i] = TRAMPOLINE_TEMPLATE_32[i];
    }
    *((uint32_t *)(tbytes+1)) = offset;
}

void *trampoline_32(void *target, void *hook) {
    size_t len = round_to_next_instruction_32(target, TRAMPOLINE_TEMPLATE_LEN_32);
    void *ret = build_trampoline_32(target, len);
    install_trampoline_hook_32(target, hook);
    return ret;
}
#endif

#ifdef CROOK_64BIT
void destructive_hook_64(void *target, void *hook) {
    // push high bytes of address
    // push low bytes of address
    // ret
    uint8_t template[] = {
        0x48, 0xb8, // mov rax,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // immediate
        0xff, 0xe0, // jmp rax
    };
    size_t len = sizeof(template);
    uint64_t offset = (uint64_t) hook;
    *((uint64_t *)(template+2)) = offset;
    uint8_t *tbytes = (uint8_t *) target;
    unprotect(target, len);
    for (int i = 0; i < len; ++i) {
        tbytes[i] = template[i];
    }
}

void *build_trampoline_64(void *target, size_t len) {
    uint8_t template[] = {
        0x66, 0x68, 0x00, 0x00, // push most significant bytes
        0x66, 0x68, 0x00, 0x00,
        0x66, 0x68, 0x00, 0x00,
        0x66, 0x68, 0x00, 0x00, // push least significant bytes
        0xc3, // ret
    };
    size_t tlen = sizeof(template);
    uint8_t *ret = trampoline_alloc(len + tlen);
    uint64_t toff = (uint64_t) target + len;
    *((uint16_t *)(template+2)) = (uint16_t) (toff >> 48);
    *((uint16_t *)(template+6)) = (uint16_t) (toff >> 32);
    *((uint16_t *)(template+10)) = (uint16_t) (toff >> 16);
    *((uint16_t *)(template+14)) = (uint16_t) toff;
    uint8_t *tbytes = (uint8_t *) target;
    for (int i = 0; i < len; ++i) {
        ret[i] = tbytes[i];
    }
    for (int i = 0; i < tlen; ++i) {
        ret[len+i] = template[i];
    }
    return ret;
}

void dump_function_64(void *target, size_t len) {
    csh handle;
    cs_insn *insn;
    if (cs_open(CS_ARCH_X86, CS_MODE_64, &handle) != CS_ERR_OK) {
        panic("failed to open capstone handler");
    }
    size_t count = cs_disasm(handle, target, len, 0, 0, &insn);
    for (int i = 0; i < count; ++i) {
        printf("%llx %s %s\n", insn[i].address, insn[i].mnemonic, insn[i].op_str);
    }
    cs_free(insn, count);
    cs_close(&handle);
}

size_t round_to_next_instruction_64(void *target, size_t len) {
    csh handle;
    cs_insn *ins;
    if (cs_open(CS_ARCH_X86, CS_MODE_64, &handle) != CS_ERR_OK) {
        panic("failed to open capstone handler");
    }
    // 15 is max size of x86 instruction
    size_t count = cs_disasm(handle, target, len + 15, 0, 0, &ins);
    size_t ret = 0;
    printf("patching instructions at 0x%p:\n", target);
    for (int i = 0; i < count; ++i) {
        printf(" 0x%p+%llx: %s %s\n", target, ins[i].address, ins[i].mnemonic, ins[i].op_str);
        if (ins[i].address >= len) {
            ret = ins[i].address;
            break;
        }
    }
    if (ret < len) panic("could not identify instruction after %u bytes", len);
    cs_free(ins, count);
    cs_close(&handle);
    return ret;
}

uint8_t TRAMPOLINE_TEMPLATE_64[] = {
    0x48, 0xb8, // mov rax,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // immediate
    0xff, 0xe0, // jmp rax
};
size_t TRAMPOLINE_TEMPLATE_LEN_64 = sizeof(TRAMPOLINE_TEMPLATE_64);
void install_trampoline_hook_64(void *target, void *hook) {
    unprotect(target, TRAMPOLINE_TEMPLATE_LEN_64);
    uint64_t offset = (uint64_t) hook;
    uint8_t *tbytes = (uint8_t *) target;
    for (int i = 0; i < TRAMPOLINE_TEMPLATE_LEN_64; ++i) {
        tbytes[i] = TRAMPOLINE_TEMPLATE_64[i];
    }
    *((uint64_t *)(tbytes+2)) = offset;
}

void *trampoline_64(void *target, void *hook) {
    size_t len = round_to_next_instruction_64(target, TRAMPOLINE_TEMPLATE_LEN_64);
    void *ret = build_trampoline_64(target, len);
    install_trampoline_hook_64(target, hook);
    return ret;
}
#endif

global _start

; Variables:
   ; var    char    *src    @ ebp-0x4C
   ; var    int32_t var_ch  @ ebp-0xC
   ; arg    int32_t arg_4h  @ ebp-0x4
   ; var    int32_t var_68h @ esp-0x4

section .data
   str.p db "(%p)", 0xA, 0

section .text

_p:
    push ebp
    mov ebp, esp
    sub esp, 0x68
    mov eax, dword [src]
    mov dword [esp], eax
    call sym.imp.fflush
    lea eax, dword [src]
    mov dword [esp], eax
    call sym.imp.gets
    mov eax, dword [arg_4h]
    mov dword [var_ch], eax
    mov eax, dword [var_ch]
    and eax, 0xb0000000
    cmp eax, 0xb0000000
    jne 0x8048527

    mov eax, str.p
    mov edx, dword [var_ch]
    mov dword [var_68h], edx
    mov dword [esp], eax
    call sym.imp.printf
    mov dword [esp], 1
    call sym.imp._exit

    ;------------------------> 0x8048527
    lea eax, dword [src]
    mov dword [esp], eax
    call sym.imp.puts
    lea eax, dword [src]
    mov dword [esp], eax
    call sym.imp.strdup
    leave
    ret


_start:
   push ebp
   mov ebp, esp
   and esp, 0xfffffff0
   call sym.p
   leave
   ret
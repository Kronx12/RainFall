global _start

; Variables:
   ; var char       *s      @ esp+0x10
   ; var size_t     size    @ esp+0x4
   ; var size_t     nitems  @ esp+0x8
   ; var FILE       *stream @ esp+0xC

section .data
   str.Good..._Wait_what db "Good... Wait what?", 0xA, 0
   str.bin_sh db '/bin/sh', 0

section .text

_run:
   push ebp
   mov ebp, esp
   sub esp, 0x18
   mov eax, dword [obj.stdout]
   mov edx, eax
   mov eax, str.Good..._Wait_what
   mov, dword [stream], edx
   mov dword [nitems], 0x13
   mov dword [size], 1
   mov dword [esp], eax
   call sym.imp._IO_fwrite
   mov dword [esp], str.bin_sh
   call sym.imp.system
   leave
   ret

_start:
   push ebp
   mov ebp, esp
   and esp, 0xfffffff0
   sub esp, 0x50
   lea eax, dword [s]
   mov dword [esp], eax
   call sym.imp.gets
   leave
   ret
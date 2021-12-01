On this level we can't use `objdump -d ./level0`, so we may use `gdb` with `disass`:
```asm
[...]
   0x08048ed4 <+20>:    call   0x8049710 <atoi>
   0x08048ed9 <+25>:	cmp    $0x1a7,%eax
   0x08048ede <+30>:	jne    0x8048f58 <main+152>
   0x08048ee0 <+32>:	movl   $0x80c5348,(%esp)
   0x08048ee7 <+39>:	call   0x8050bf0 <strdup>
[...]
   0x08048f4a <+138>:	movl   $0x80c5348,(%esp)
   0x08048f51 <+145>:	call   0x8054640 <execv>
   0x08048f56 <+150>:	jmp    0x8048f80 <main+192>
[...]
```

We can see that the executable use an `atoi` on argv[1] and compare with the value `0x1a7 = 423`.
So, if we set argv[1] at 423, it will execute a bash with `system('/bin/sh')`:

```bash
./level0 423
$ whoami
level1
$ cd .. && cat level1/.pass
1fe8a524fa4bec01ca4ea2a869af2a02260d4a7d5fe7e7c24d8617e6dca12d3a
```
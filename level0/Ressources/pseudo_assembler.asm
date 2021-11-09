global _start

; Variables:
   ; arg char     **str    @ ebp+0xC
   ; var uid_t    var_20h  @ esp+0x4
   ; var uid_t    var_1ch  @ esp+0x8
   ; var int32_t  var_18h  @ esp+0xC
   ; var int32_t  var_14h  @ esp+0x10
   ; var int32_t  var_10h  @ esp+0x14
   ; var uid_t    var_ch   @ esp+0x18
   ; var int32_t  var_8h   @ esp+0x1C

section .data
   str.bin_sh  db '/bin/sh', 0
   str.no      db 'No !', 0xA, 0

section .text

_start:
   push ebp
   mov esp, ebp
   and esp, 0xfffffff0
   sub esp, 0x20
   mov eax, dword [str]
   add eax, 4
   mov eax, dword [eax]

   ; Set parameter
   mov dword [esp], eax
   ; Call atoi
   call sym.atoi

   ; Compare l'int extrait ci-dessus avec la valeur 423
   cmp eax, 0x1a7
   ; Si elle sont differente on saute a la partie affichage du "No !"
   jne 0x8048f58

   ; Sinon on execute le code suivant

   ; Set parameter
   mov dword [esp], str_bin_sh
   ; Call strdup
   call sym.__strdup

   mov dword [var_14h], eax
   mov dword [var_10h], 0
   
   ; GET Effective Group ID
   call sym.getegid
   ; Save result
   mov dword [var_8h], eax

   ; GET Effective User ID
   call sym.geteuid
   ; Save result
   mov dword [var_ch], eax

   ; SET Real, Effective and Saved Group ID
   mov eax, dword [var_8h]
   mov dword [var_1ch], eax
   mov eax, dword [var_8h]
   mov dword [var_20h], eax
   mov eax, dword [var_8h]
   mov dword [esp], eax
   call sym.setresgid

   ; SET Real, Effective and Saved User ID
   mov eax, dword [var_ch]
   mov dword [var_1ch], eax
   mov eax, dword [var_ch]
   mov dword [var_10ch], eax
   mov eax, dword [var_ch]
   mov dword [var_20ch], eax
   call sym.setresuid

   ; Set path parameter for execv
   lea eax, dword [var_14h]
   mov dword [var_20h], eax

   ; Create argv parameter for execv
   mov dword [esp], str_bin_sh

   ; Execve /bin/sh => open shell
   call sym.execv
   jmp 0x8048f80

   ------------------------> 0x8048f58
   mov eax, dword [obj.stderr]
   mov edx, eax
   mov eax, str_no
   mov dword [var_18h], edx
   mov dword [var_1ch], 5
   mov dword [var_20h], 1
   mov dword [esp], eax

   call sym._IO_fwrite

   ------------------------> 0x8048f80
   mov eax, 0
   leave
   ret
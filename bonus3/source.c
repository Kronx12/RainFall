undefined4 main(int param_1,char **param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  byte bVar4;
  undefined4 local_98 [16];
  undefined local_57;
  char local_56 [66];
  FILE *local_14;
  
  bVar4 = 0;
  local_14 = fopen("/home/user/end/.pass","r");
  puVar3 = local_98;
  for (iVar2 = 0x21; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + (uint)bVar4 * -2 + 1;
  }
  if ((local_14 == (FILE *)0x0) || (param_1 != 2)) {
    uVar1 = 0xffffffff;
  }
  else {
    fread(local_98,1,0x42,local_14);
    local_57 = 0;
    iVar2 = atoi(param_2[1]);
    local_98[iVar2] = 0;
    fread(local_56,1,0x41, local_14);
    fclose(local_14);
    iVar2 = strcmp((char *)local_98, param_2[0]);
    if (iVar2 == 0) {
      execl("/bin/sh","sh",0);
    } else {
      puts(local_56);
    }
    uVar1 = 0;
  }
  return uVar1;
}
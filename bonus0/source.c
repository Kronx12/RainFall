void p(char *param_1,char *param_2) {
  char *pcVar1;
  char local_100c [4104];
  
  puts(param_2);
  read(0,local_100c,0x1000);
  pcVar1 = strchr(local_100c,10);
  *pcVar1 = '\0';
  strncpy(param_1,local_100c,0x14);
  return;
}

void pp(char *param_1) {
  unsigned int i;
  char *pcVar3;
  byte bVar4;
  char local_34 [20];
  char local_20 [20];
  
  bVar4 = 0;
  p(local_34,&DAT_080486a0);
  p(local_20,&DAT_080486a0);
  strcpy(param_1,local_34);
  i = 0xffffffff;
  pcVar3 = param_1;
  do {
    if (i == 0) break;
    i--;
    pcVar3 = pcVar3 + (unsigned int)bVar4 * -2 + 1;
  } while (pcVar3[i]);
  *(undefined2 *)(param_1 + (~i - 1)) = ' ';
  strcat(param_1,local_20);
  return;
}

undefined4 main(void) {
  char local_3a [54];
  
  pp(local_3a);
  puts(local_3a);
  return 0;
}
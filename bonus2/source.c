#include <stdio.h>

int language;

int greetuser(void) {
  unsigned int local_4c;
  unsigned int local_48;
  unsigned int local_44;
  unsigned int local_40;
  unsigned short local_3c;
  unsigned char local_3a;
  
  if (language == 1) {
    local_4c = 0xc3767948;
    local_48 = 0x20a4c3a4;
    local_44 = 0x69a4c370;
    local_40 = 0xc3a4c376;
    local_3c = 0x20a4;
    local_3a = 0;
  }
  else {
    if (language == 2) {
      local_4c = 0x64656f47;
      local_48 = 0x64696d65;
      local_44 = 0x21676164;
      local_40 = CONCAT22(local_40._2_2_,0x20);
    }
    else {
      if (language == 0) {
        local_4c = 0x6c6c6548;
        local_48 = CONCAT13(local_48._3_1_,0x206f);
      }
    }
  }
  strcat((char *)&local_4c,&stack0x00000004);
  puts((char *)&local_4c);
  return;
}


int main(int argc, char **argv) {
  unsigned int uVar1;
  int iVar2;
  unsigned int *puVar3;
  unsigned int *puVar4;
  char bVar5;
  char local_60[40];
  char acStack56[36];
  char *env_lang;
  
  bVar5 = 0;
  if (argc == 3) {
    for (int i = 0; i < 40; i++)
      local_60[i] = 0;

    strncpy(local_60, argv[1], 40);
    strncpy(acStack56, argv[2], 32);

    // Set language to corresponding lang
    env_lang = getenv("LANG");
    if (env_lang != NULL) {
      iVar2 = memcmp(env_lang, "fi", 2);
      if (iVar2 == 0)
        language = 1;
      else {
        iVar2 = memcmp(env_lang, "nl", 2);
        if (iVar2 == 0)
          language = 2;
      }
    }

    puVar4 = (unsigned int *)&stack0xffffff50;
    for (int i = 0; i < 19; i++)
      puVar4[i] = local_60[i];
    uVar1 = greetuser();
  }
  else
    uVar1 = 1;
  return uVar1;
}
#include <stdio.h>

unsigned int m = 0;

void p(char *print) {
    printf(print);
    return ;
}

void n(void) {
  char local_20c [520];
  
  fgets(local_20c,0x200,stdin);
  p(local_20c);
  if (m == 0x1025544) {
    system("/bin/cat /home/user/level5/.pass");
  }
  return;
}

void main() {
    n();
    return;
}
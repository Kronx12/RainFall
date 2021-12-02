int main(int ac, int argv)
{
  int result;
  char str[40];
  int value;

  value = atoi(*(char **)(argv + 4));
  if (value < 10)
  {
    memcpy(str, *(void **)(argv + 8), value * 4);
    if (value == 0x574f4c46)
    {
      execl("/bin/sh", "sh", 0);
    }
    result = 0;
  }
  else
    result = 1;
  return result;
}
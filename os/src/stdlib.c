#include "stdlib.h"

void memset(unsigned char *dst, unsigned char value, size_t len)
{
  for (unsigned char *i = dst; i < dst + len; ++i)
  {
    *i = value;
  }
}

unsigned int strlen(char *str)
{
  char *end = str;
  while (*end != 0)
  {
    ++end;
  }
  return end - str;
}
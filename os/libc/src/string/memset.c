#include <string.h>

void *memset(void *dst, int value, size_t len)
{
  unsigned char *buf = (unsigned char *)dst;
  for (size_t i = 0; i < len; i++)
    buf[i] = (unsigned char)value;
  return dst;
}

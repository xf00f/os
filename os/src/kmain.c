#include "stdlib.h"
#include "vga.h"

int _start()
{
  fb_clear();
  fb_print(0, "EVM/OS Operational", WHITE, BLACK);
  return 6;
}

#include <stdio.h>
#include "multiboot.h"
#include "tty.h"

int _start(/*multiboot_info_t *mbd, unsigned int magic*/)
{
  terminal_initialize();
  printf("EVM/OS Operational");
  return 6;
}

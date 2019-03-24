#include "stdlib.h"
#include "vga.h"

void outb(unsigned short port, unsigned char data);
unsigned char *fb = (unsigned char *)0x000B8000;

/** fb_write_cell:
 *  Writes a character with the given foreground and background to the cell number in the framebuffer.
 *
 *  @param i  The cell number
 *  @param c  The character
 *  @param fg The foreground color
 *  @param bg The background color
 */
void fb_write_cell(unsigned int i, char c, Color fg, Color bg)
{
  fb[i * 2] = c;
  fb[i * 2 + 1] = ((bg & 0x0F) << 4) | (fg & 0x0F);
}

void fb_print(unsigned int i, char *str, Color fg, Color bg)
{
  char *c = str;
  while (*c != 0)
  {
    fb_write_cell(i++, *c++, fg, bg);
    fb_move_cursor(i);
  }
}

void fb_clear()
{
  for (int i = 0; i < 80 * 25; ++i)
  {
    fb_write_cell(i, ' ', WHITE, BLACK);
  }
}

/* The I/O ports */
#define FB_COMMAND_PORT 0x3D4
#define FB_DATA_PORT 0x3D5

/* The I/O port commands */
#define FB_HIGH_BYTE_COMMAND 14
#define FB_LOW_BYTE_COMMAND 15

void fb_move_cursor(uint16_t pos)
{
  outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
  outb(FB_DATA_PORT, ((pos >> 8) & 0x00FF));
  outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
  outb(FB_DATA_PORT, pos & 0x00FF);
}
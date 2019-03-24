#include <stdint.h>

typedef enum
{
  BLACK = 0,
  BLUE = 1,
  GREEN = 2,
  CYAN = 3,
  RED = 4,
  MAGENTA = 5,
  BROWN = 6,
  LIGHT_GREY = 7,
  DARK_GREY = 8,
  LIGHT_BLUE = 9,
  LIGHT_GREEN = 10,
  LIGHT_CYAN = 11,
  LIGHT_RED = 12,
  LIGHT_MAGENTA = 13,
  LIGHT_BROWN = 14,
  WHITE = 15,
} Color;

void fb_write_cell(unsigned int i, char c, Color fg, Color bg);
void fb_print(unsigned int i, char *str, Color fg, Color bg);
void fb_clear();
void fb_move_cursor(uint16_t pos);
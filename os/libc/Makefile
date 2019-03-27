SOURCE_DIR = src
C_FILES = $(wildcard $(SOURCE_DIR)/**/*.c)
C_OBJECTS = $(C_FILES:$(SOURCE_DIR)/%.c=bin/%.o)
AS_FILES = $(wildcard $(SOURCE_DIR)/**/*.s)
AS_OBJECTS = $(AS_FILES:$(SOURCE_DIR)/%.s=bin/%.o)
OBJECTS = $(C_OBJECTS) $(AS_OBJECTS)
LIBK_OBJECTS = $(C_OBJECTS:.o=.libk.o)
CC = i686-elf-gcc
CFLAGS = -c -std=gnu99 -ffreestanding -Wall -Wextra -ggdb -Isrc/include -I../kernel/src
LIBK_CFLAGS = $(CFLAGS) -D__is_libk
LDFLAGS = -T link.ld -ffreestanding -nostdlib
AS = nasm
ASFLAGS = -f elf -Fdwarf -g

.PHONY: build clean

build: bin/libc.a bin/libk.a

bin:
	find ./src -type d | sed -e "s|\./src|./bin|" | xargs mkdir -p

bin/libc.a: bin $(OBJECTS)
	$(AR) rcs $@ $(OBJECTS)

bin/libk.a: bin $(LIBK_OBJECTS)
	$(AR) rcs $@ $(LIBK_OBJECTS)

$(C_OBJECTS): bin/%.o: src/%.c
	$(CC) $(CFLAGS) $< -o $@

$(LIBK_OBJECTS): bin/%.libk.o: src/%.c
	$(CC) $(LIBK_CFLAGS) $< -o $@

$(AS_OBJECTS): bin/%.o: src/%.s
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -rf bin

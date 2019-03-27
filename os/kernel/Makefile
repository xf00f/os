SOURCE_DIR = src
C_FILES = $(wildcard $(SOURCE_DIR)/*.c)
C_OBJECTS = $(C_FILES:$(SOURCE_DIR)/%.c=bin/%.o)
AS_FILES = $(wildcard $(SOURCE_DIR)/*.s)
AS_OBJECTS = $(AS_FILES:$(SOURCE_DIR)/%.s=bin/%.o)
OBJECTS = $(C_OBJECTS) $(AS_OBJECTS)
CC = i686-elf-gcc
CFLAGS = -c -std=gnu99 -ffreestanding -Wall -Wextra -ggdb -I../libc/src/include
LDFLAGS = -T link.ld -ffreestanding -nostdlib -L../libc/bin
AS = nasm
ASFLAGS = -f elf -Fdwarf -g

.PHONY: build clean

build: bin/kernel.elf

bin:
	find ./src -type d | sed -e "s|\./src|./bin|" | xargs mkdir -p

bin/kernel.elf: bin $(OBJECTS) link.ld ../libc/bin/libk.a
	$(CC) $(LDFLAGS) $(OBJECTS) -lgcc -lk -o bin/kernel.elf
	grub-file --is-x86-multiboot bin/kernel.elf || rm bin/kernel.elf

../libc/bin/libk.a:
	cd ../libc && $(MAKE)

$(C_OBJECTS): bin/%.o: src/%.c
	$(CC) $(CFLAGS) $< -o $@

$(AS_OBJECTS): bin/%.o: src/%.s
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -rf bin

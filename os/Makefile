SOURCE_DIR = src
C_FILES = $(wildcard $(SOURCE_DIR)/*.c)
C_OBJECTS = $(C_FILES:$(SOURCE_DIR)/%.c=bin/%.o)
AS_FILES = $(wildcard $(SOURCE_DIR)/*.s)
AS_OBJECTS = $(AS_FILES:$(SOURCE_DIR)/%.s=bin/%.o)
OBJECTS = $(C_OBJECTS) $(AS_OBJECTS)
CC = i686-elf-gcc
CFLAGS = -c -std=gnu99 -ffreestanding -Wall -Wextra -ggdb
LDFLAGS = -T link.ld -ffreestanding -nostdlib
AS = nasm
ASFLAGS = -f elf -Fdwarf -g

.PHONY: build clean

build: bin/os.iso

bin:
	mkdir -p bin

bin/os.iso: bin bin/kernel.elf
	mkdir -p bin/img/boot/grub
	cp bin/kernel.elf bin/img/boot/
	cp grub.cfg bin/img/boot/grub/
	grub-mkrescue -o bin/os.iso bin/img

bin/kernel.elf: $(OBJECTS) link.ld
	$(CC) $(LDFLAGS) $(OBJECTS) -lgcc -o bin/kernel.elf

$(C_OBJECTS): bin/%.o: src/%.c src/%.h
	$(CC) $(CFLAGS) $< -o $@

$(AS_OBJECTS): bin/%.o: src/%.s
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -rf bin

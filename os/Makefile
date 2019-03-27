.PHONY: build clean

build: bin/os.iso

bin:
	mkdir -p bin/img/boot/grub

bin/os.iso: bin kernel/bin/kernel.elf
	cp kernel/bin/kernel.elf bin/img/boot/
	cp grub.cfg bin/img/boot/grub/
	grub-mkrescue -o bin/os.iso bin/img

kernel/bin/kernel.elf: libc/bin/libk.a
	cd kernel && make

libc/bin/libk.a:
	cd libc && make

clean:
	rm -rf bin
	cd kernel && make clean
	cd libc && make clean

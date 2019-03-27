TASKS = build clean

.PHONY: $(TASKS) run run-shell run-gdb build-image

$(TASKS):
	docker run -v $(PWD)/os:/opt/os xf00f/os make $@

run: build
	qemu-system-i386 -D qemu.log -monitor stdio -vga cirrus \
		-serial file:kernel.log \
		-nodefaults -gdb tcp:0.0.0.0:1234 -cdrom os/iso/bin/os.iso

run-shell:
	docker run -v $(PWD)/os:/opt/os -it xf00f/os /bin/bash

run-gdb:
	docker run -v $(PWD)/os:/opt/os -it --detach-keys="ctrl-u,u" xf00f/os gdb -x gdb-init

build-image:
	docker build -t xf00f/os .
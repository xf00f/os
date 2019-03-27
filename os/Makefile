.PHONY: build clean

build:
	cd libc && $(MAKE) bin/libk.a
	cd kernel && $(MAKE)
	cd iso && $(MAKE)

clean:
	cd libc && $(MAKE) clean
	cd kernel && $(MAKE) clean
	cd iso && $(MAKE) clean

# os

An operating system.

## Requirements

Requires Docker and QEMU on the host system.

For mac use the [official Docker installation](https://hub.docker.com/editions/community/docker-ce-desktop-mac), and:

```
brew install qemu
```

## Usage

First build the build environment:

```
make build-image
```

Then build the kernel:

```
make build
```

Finally, run it:

```
make run
```

If you want to connect the debugger:

```
make run-gdb
```

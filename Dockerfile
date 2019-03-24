FROM gcc:8.3.0

WORKDIR /root

RUN apt-get update

# Grub
RUN apt-get install -y gettext autopoint bison flex
RUN git clone --depth=1 git://git.savannah.gnu.org/grub.git \
  && cd grub \
  && ./bootstrap \
  && ./configure --target=i386 --with-platform=pc \
  && make -j8 \
  && make install \
  && cd .. \
  && rm -rf grub

# Cross compile binutils
RUN curl -O ftp://ftp.gnu.org/gnu/binutils/binutils-2.32.tar.gz \
  && tar -zxf binutils-2.32.tar.gz \
  && mkdir binutils-build \
  && cd binutils-build \
  && ../binutils-2.32/configure --target=i686-elf --with-sysroot --disable-nls --disable-werror \
  && make -j8 \
  && make install \
  && cd .. \
  && rm -rf binutils*

# Cross compile gcc
RUN apt-get install -y libgmp3-dev libmpc-dev libmpfr-dev
RUN curl -O ftp://ftp.gnu.org/gnu/gcc/gcc-8.3.0/gcc-8.3.0.tar.gz \
  && tar -zxf gcc-8.3.0.tar.gz \
  && mkdir gcc-build \
  && cd gcc-build \
  && ../gcc-8.3.0/configure --target=i686-elf --disable-nls --enable-languages=c,c++ --without-headers \
  && make -j8 all-gcc \
  && make -j8 all-target-libgcc \
  && make install-gcc \
  && make install-target-libgcc \
  && cd .. \
  && rm -rf gcc*

# Other tools
RUN apt-get install -y nasm gdb xorriso

RUN mkdir -p /opt/os
WORKDIR /opt/os
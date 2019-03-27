global loader
extern _start

MAGIC_NUMBER equ 0x1BADB002
FLAGS equ 0x0
CHECKSUM equ -MAGIC_NUMBER
KERNEL_STACK_SIZE equ 4096

section .multiboot
align 4
        dd MAGIC_NUMBER
        dd FLAGS
        dd CHECKSUM

section .bss
align 16
stack_bottom:
        resb KERNEL_STACK_SIZE
stack_top:

section .text
loader:
        mov esp, stack_top
        call _start
        cli
.hang:
        hlt
        jmp .hang

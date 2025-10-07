.data

    .global c
    .align 1
c:
    .byte -20

    .global i
    .align 4
i:
    .int -256

    .global j
    .align 4
j:
    .long 512

    .global l
    .align 8
l:
    .quad 128

    .global us
    .align 2
us:
    .short 111

    .global ui
    .align 4
ui:
    .int 1024

    .global ul
    .align 8
ul:
    .quad 2048

.text

.globl aux
.type aux, @function
aux:
    pushq %rbp
    movq %rsp, %rbp

    # j = 68000;
    movl $68000, j(%rip)

    # l = 4096;
    movq $4096, l(%rip)

    # i = j;
    movl j(%rip), %eax
    movl %eax, i(%rip)

    # j = 10 + i - 5;  (equivalent to i + 5)
    movl i(%rip), %eax
    addl $5, %eax
    movl %eax, j(%rip)

    # i = (i * 2) - (j + 5);
    movl i(%rip), %eax
    shll $1, %eax               # eax = i*2 (mais eficiente que lea)
    movl j(%rip), %edx
    addl $5, %edx               # edx = j+5
    subl %edx, %eax             # eax = (i*2) - (j+5)
    movl %eax, i(%rip)

    # ui = i;
    movl i(%rip), %eax
    movl %eax, ui(%rip)

    # j = c; (sign-extend byte to 32-bit)
    movsbl c(%rip), %eax
    movl %eax, j(%rip)

    # ul = ui; (zero-extend 32-bit ui into 64-bit ul)
    movl ui(%rip), %eax
    movq %rax, ul(%rip)         # movl automaticamente zera os 32 bits altos

    # us = ul; (truncate to low 16 bits)
    movw ul(%rip), %ax          # carrega diretamente os 16 bits baixos
    movw %ax, us(%rip)

    # c = i + j; (store low 8 bits)
    movl i(%rip), %eax
    addl j(%rip), %eax          # soma diretamente da memória
    movb %al, c(%rip)

    # Operações com ponteiros:
    # long *ptr; ptr = &l; *ptr = 128;
    # Como ptr aponta para l, *ptr = 128 equivale a l = 128
    movq $128, l(%rip)

    # int *iptr; iptr = &i; j = j + *iptr;
    # Como iptr aponta para i, *iptr equivale a i
    # Portanto j = j + *iptr é o mesmo que j = j + i
    movl j(%rip), %eax
    addl i(%rip), %eax
    movl %eax, j(%rip)

    leave
    ret

.size aux, .-aux
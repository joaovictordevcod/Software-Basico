.section .data

a:
.int 0
.global a
.align 4

b:
.quad 2
.global b
.align 8

.text

.global ex02

ex02:
    # Carregar valor de 'a'
    movl a(%rip), %eax      # %eax = a (0)
    
    # Primeiro if: if (a)
    testl %eax, %eax        # testa se a != 0
    jz .L3                  # pula para fim se a == 0
    
    # Carregar valor de 'b' 
    movq b(%rip), %rcx      # %rcx = b (2)
    
    # Segundo if: if (b < 5)
    cmpq $5, %rcx           # compara b com 5
    jge .L1                 # pula para else se b >= 5
    
    # Bloco if (b < 5): b = (a << 1) + (a * b)
    movl %eax, %edx         # %edx = a
    shll $1, %edx           # %edx = a << 1 (a * 2)
    
    movslq %eax, %rax       # extende a para 64 bits
    imulq %rcx, %rax        # %rax = a * b
    
    addq %rdx, %rax         # %rax = (a << 1) + (a * b)
    movq %rax, b(%rip)      # b = resultado
    jmp .L3                 # pula para o fim
    
.L1:
    # Bloco else: a = b ^ 0x1FL
    xorq $0x1F, %rcx        # %rcx = b ^ 0x1F
    movl %ecx, a(%rip)      # a = resultado (trunca para int)

.L3:
    ret

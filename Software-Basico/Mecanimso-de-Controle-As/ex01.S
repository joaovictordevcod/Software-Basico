.section .data

a:
.int 30
.global a
.align 4

b:
.int 45
.global b
.align 4

c:
.int -60
.global c
.align 4

d:
.int 25
.global d 
.align 4

.text

.global ex01

ex01:
    # Carregar valores das variáveis globais
    movl a(%rip), %eax      # %eax = a (30)
    movl b(%rip), %ecx      # %ecx = b (45)
    movl c(%rip), %edx      # %edx = c (-60)
    movl d(%rip), %esi      # %esi = d (25)
    
    # Primeiro if: if (a > b)
    cmpl %ecx, %eax         # compara a com b
    jle .L1                 # pula para .L1 se a <= b
    
    # Bloco do primeiro if: a > b
    negl %edx               # c = -c
    movl %edx, c(%rip)      # salva c na memória
    
    movl $3, %r8d           # carrega 3 em %r8d
    movl %edx, %eax         # move c para %eax para divisão
    cltd                    # estende sinal para %edx:%eax
    idivl %r8d              # divide %edx:%eax por %r8d (c / 3)
    movl %eax, d(%rip)      # d = c / 3
    
    # Atualizar registradores com novos valores
    movl c(%rip), %edx      # recarrega c
    movl d(%rip), %esi      # recarrega d

.L1:
    # Segundo if: if (b >= a)
    movl a(%rip), %eax      # recarrega a
    movl b(%rip), %ecx      # recarrega b
    cmpl %eax, %ecx         # compara b com a
    jl .L2                  # pula para .L2 se b < a
    
    # Bloco do segundo if: b >= a
    addl %ecx, %eax         # %eax = a + b
    imull %edx, %eax        # %eax = (a + b) * c
    movl %eax, c(%rip)      # c = (a + b) * c
    
    movl $1024, %eax        # carrega 1024
    movl %eax, d(%rip)      # d = 1024

.L2:
    ret


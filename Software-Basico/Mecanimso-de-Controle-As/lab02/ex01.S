.section .data
    # short vet[4] = {50, 10, 67, 42};
.globl vet
    vet: .word 50, 10, 67, 42
    
    # short max = 0;
.globl max
    max: .word 0

.section .text
.globl ex01

ex01:
    # char i;
    # for (i = 0; i < 4; i++) 
    
    # Inicializar i = 0
    movb $0, %al          # i = 0 (usando %al para char)
    
loop_start:
    # Comparar i < 4
    cmpb $4, %al
    jge loop_end          # se i >= 4, sair do loop
    
    # Verificar if (vet[i] > max)
    # Calcular endereço de vet[i]
    movzbq %al, %rcx      # estender i para 64 bits em %rcx
    leaq vet(%rip), %rdi  # carregar endereço base de vet
    movw (%rdi,%rcx,2), %dx  # carregar vet[i] em %dx (2 bytes por short)
    
    # Carregar max
    movw max(%rip), %si   # carregar max em %si
    
    # Comparar vet[i] > max
    cmpw %si, %dx
    jle skip_assignment   # se vet[i] <= max, pular atribuição
    
    # max = vet[i];
    movw %dx, max(%rip)
    
skip_assignment:
    # i++
    incb %al
    jmp loop_start
    
loop_end:
    ret
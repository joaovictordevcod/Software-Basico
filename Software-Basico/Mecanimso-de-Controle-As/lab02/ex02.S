.section .data
    # unsigned char letters[] = "abcdefghij";
.globl letters
    letters: .string "abcdefghij"
    
    # int even = 0;
.globl even
    even: .long 0
    
    # int odd = 0;
.globl odd
    odd: .long 0

.section .text
.globl ex02

ex02:
    # unsigned int count = 0;
    movl $0, %eax         # count = 0 (usando %eax para unsigned int)
    
while_start:
    # while (letters[count])
    leaq letters(%rip), %rdi    # carregar endereço base de letters
    movzbl (%rdi,%rax,1), %ecx  # carregar letters[count] em %ecx (1 byte por char)
    testb %cl, %cl              # testar se letters[count] == 0
    jz while_end                # se zero, sair do while
    
    # Verificar if (letters[count++] & 1)
    # Primeiro fazer o pós-incremento: salvar valor atual, depois incrementar count
    movb %cl, %dl               # salvar letters[count] em %dl antes do incremento
    incl %eax                   # count++ (pós-incremento)
    
    # Testar se o valor salvo é ímpar (bit 0 = 1)
    testb $1, %dl               # testar bit 0 de letters[count] (antes do incremento)
    jz increment_even           # se bit 0 = 0 (par), pular para even++
    
    # odd++;
    movl odd(%rip), %r8d        # carregar valor atual de odd
    incl %r8d                   # incrementar
    movl %r8d, odd(%rip)        # salvar de volta
    jmp while_start             # voltar ao início do while
    
increment_even:
    # Ramo else: even++;
    movl even(%rip), %r9d       # carregar valor atual de even
    incl %r9d                   # incrementar
    movl %r9d, even(%rip)       # salvar de volta
    jmp while_start             # voltar ao início do while
    
while_end:
    ret
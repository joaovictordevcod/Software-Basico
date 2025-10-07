#include <stdio.h>

unsigned char rotate_left(unsigned char x, int n) {
    n = n % 8;
    
    if (n == 0) {
        return x;
    }
    return (x << n) | (x >> (8 - n));
}

int main() {
    unsigned char valor;
    int deslocamento;
    
    // Teste com o exemplo fornecido: 0x61
    printf("Testando com valor 0x61 (0110 0001):\n");
    valor = 0x61;
    
    printf("Valor original: 0x%02x (%d)\n", valor, valor);
    
    // Teste com 1 bit (deve resultar em 0xc2)
    deslocamento = 1;
    printf("Rotate left %d bit:  0x%02x (%d)\n", deslocamento, 
           rotate_left(valor, deslocamento), rotate_left(valor, deslocamento));
    
    // Teste com 2 bits (deve resultar em 0x85)
    deslocamento = 2;
    printf("Rotate left %d bits: 0x%02x (%d)\n", deslocamento, 
           rotate_left(valor, deslocamento), rotate_left(valor, deslocamento));
    
    // Teste com 7 bits (deve resultar em 0xb0)
    deslocamento = 7;
    printf("Rotate left %d bits: 0x%02x (%d)\n", deslocamento, 
           rotate_left(valor, deslocamento), rotate_left(valor, deslocamento));
    
    printf("\n");
    
    // Testes adicionais com outros valores
    printf("Testes adicionais:\n");
    
    // Teste com 0xFF (todos os bits em 1)
    valor = 0xFF;
    printf("Valor 0xFF, rotate left 3: 0x%02x\n", rotate_left(valor, 3));
    
    // Teste com 0x80 (apenas o bit mais significativo)
    valor = 0x80;
    printf("Valor 0x80, rotate left 1: 0x%02x\n", rotate_left(valor, 1));
    
    // Teste com 0x01 (apenas o bit menos significativo)
    valor = 0x01;
    printf("Valor 0x01, rotate left 7: 0x%02x\n", rotate_left(valor, 7));
    
    // Teste com rotação de 0 (deve manter o valor original)
    valor = 0xAB;
    printf("Valor 0xAB, rotate left 0: 0x%02x\n", rotate_left(valor, 0));
    
    // Teste com rotação completa (8 bits = volta ao original)
    printf("Valor 0xAB, rotate left 8: 0x%02x (deve ser igual ao original)\n", 
           rotate_left(valor, 8));
    
    return 0;
}

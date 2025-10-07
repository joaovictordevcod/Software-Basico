#include <limits.h> 
#include <stdio.h>

int leading_zeros(unsigned short n) {
    int bits_do_short = sizeof(unsigned short) * CHAR_BIT; 
    int zeros_encontrados = 0;
    int bit_ativo = 0; 

    if (n == 0) {
        return bits_do_short; 
    }

    for (int i = bits_do_short - 1; i >= 0; i--) {
        if ((n & (1 << i)) != 0) {
            bit_ativo = 1;
        } else if (bit_ativo == 0) {
            zeros_encontrados++; 
        }
    }
    return zeros_encontrados;
}

int main() {
    unsigned short numero1 = 0x0083; 
    unsigned short numero2 = 0x0607;
    unsigned short numero3 = 0;

    printf("Zeros à esquerda de %d: %d\n", numero1, leading_zeros(numero1)); 
    printf("Zeros à esquerda de %d: %d\n", numero2, leading_zeros(numero2)); 
    printf("Zeros à esquerda de %d: %d\n", numero3, leading_zeros(numero3));

    return 0;
}
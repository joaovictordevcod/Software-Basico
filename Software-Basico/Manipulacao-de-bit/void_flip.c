#include <stdio.h>



void flip(int *value, int bit)

{

    *value ^= (1 << bit);
    printf("Bit %d flipado\n", bit);

}



int main() {

  int value;



  value = 0x00000000;

  flip(&value, 0);

  printf("0x00000001 == 0x%08X\n", value);



  value = 0xF0000000;

  flip(&value, 31);

  printf("0x70000000 == 0x%08X\n", value);



  value = 0xF002000F;

  flip(&value, 16);

  printf("0xF003000F == 0x%08X\n", value);



  return 0;

}
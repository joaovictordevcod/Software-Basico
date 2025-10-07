#include <stdio.h>



void dump(void *p, int n) {

  unsigned char *p1 = p;

  while (n--) {

    printf("%p - 0x%02X\n", p1, *p1);

    p1++;

  }

}



int main(void) {

  short s = -3;

  int i = -151;

  char c = 150;

  

  printf("dump de s: %d\n", s);

  dump(&s, sizeof(s));



  printf("\ndump de i: %d\n", i);

  dump(&i, sizeof(i));



  printf("\ndump de c: %d\n", c);

  dump(&c, sizeof(c));



  return 0;

}

/* 
short s = -3
O valor -3 em complemento de dois (16 bits) é representado como 0xFFFD
Em little-endian: byte menos significativo (0xFD) vem primeiro, depois o mais significativo (0xFF)
2. int i = -151
O valor -151 em complemento de dois (32 bits) é representado como 0xFFFFFF69
Em little-endian: 0x69, 0xFF, 0xFF, 0xFF (do byte menos para o mais significativo)
3. char c = 150
O valor 150 (0x96) quando interpretado como signed char vira -106
Isso acontece porque em signed char, valores acima de 127 são interpretados como negativos
150 - 256 = -106
*/

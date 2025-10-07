#include <stdio.h>

#include <math.h>



#define getsig(i)        ((i)>>31 & 1)

#define getexp(i)        ((i)>>23 & 0xff)

#define getfrac(i)       ((i) & 0x7fffff)

#define makefloat(s,e,f) ( (((s) & 1) << 31) | (((e) & 0xff) << 23) | ((f) & 0x7fffff) )



typedef union {

  float f;

  unsigned int i;

} U;



float float2(float value)

{

  U u;

  u.f = value;



  unsigned int s = getsig(u.i);

  unsigned int e = getexp(u.i);

  unsigned int f = getfrac(u.i);



  /* NaN ou infinito: retorna sem alteração */

  if (e == 0xff) {

    return value;

  }



  if (e == 0) {

    /* denormalizado (ou zero): desloca a fração à esquerda */

    f <<= 1;

    /* se a operação gerou o bit implícito, normaliza */

    if (f & 0x00800000U) {

      e = 1;

      f &= 0x007fffffU;

    }

  } else {

    /* normalizado: incrementa Escreva uma função C chamada float2() que, manipulando diretamente a representação de ponto flutuante, multiplique o valor de seu parâmetro por 2.o expoente */

    e += 1;

    /* se estourou para 0xff, vira infinito (fração zero) */

    if (e == 0xff) {

      f = 0;

    }

  }



  u.i = makefloat(s, e, f);

  return u.f;

}
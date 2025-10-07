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



float int2float(int value)

{
    unsigned int s=0;
    if(value < 0){
        s=1;
        value=-value;
    }
    unsigned int E=0;

    unsigned int mask=0x80000000;

    for(int i=31; i>=0; i--){
        if(value & mask){
            E=i;
            break;
        }
        mask>>=1;
    }

    unsigned int e=E+127;
    unsigned int f;
    f = value << (23-E);

    U u;
    u.i = makefloat(s,e,f);
    return u.f;

}



int main() {

   int i;



   printf("\n******** int2float ****************\n");



   i = 0;

   printf(" %d -> %+10.4f, %+10.4f\n", i, (float)i, int2float(i));



   i = 1;

   printf(" %d -> %+10.4f, %+10.4f\n", i, (float)i, int2float(i));



   i = -1;

   printf(" %d -> %+10.4f, %+10.4f\n", i, (float)i, int2float(i));



   i = 12345;

   printf(" %d -> %+10.4f, %+10.4f\n", i, (float)i, int2float(i));



   i = -12345;

   printf(" %d -> %+10.4f, %+10.4f\n", i, (float)i, int2float(i));



   i = 13631488;

   printf(" %d -> %+10.4f, %+10.4f\n", i, (float)i, int2float(i));



   i = 1879048192;

   printf(" %d -> %+10.4f, %+10.4f\n", i, (float)i, int2float(i));



   i = 0x7fffffff;

   printf(" %d -> %+10.4f, %+10.4f\n", i, (float)i, int2float(i));



   i = -i;

   printf(" %d -> %+10.4f, %+10.4f\n", i, (float)i, int2float(i));



   return 0;

}
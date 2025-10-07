struct X {

  char a;

  long b;

  int  c;

};



union Y {

  unsigned int a;

  char b[26];

  short c[4];

};



struct S {

  int a[4];

  union Y y;

  struct X x;

};



union R {

  short a;

  struct S b[2];

  char c;

  union Y d;

  int e[3];

  struct X *f[5];

};
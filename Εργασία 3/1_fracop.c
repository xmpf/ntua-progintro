#include <stdio.h>

unsigned int sign = 0;

typedef struct complex_t {
  long int up;
  long int down;
}complex_t;

long int gcd (long int f, long int s)
{
  while (f != s) {
    if (f > s)
      f -= s;
    else
      s -= f;
  }
  return f;
}

long int abs (long int num)
{
  if (num < 0)
    num = -(num);

  return num;
}

int main ()
{
  complex_t a;
  complex_t b;
  complex_t result = {0, 0};
  
  char op;
  int it;
  
  long int aker    = 0;
  long int arith   = 0;
  long int paron   = 0;
  long int gcd_var = 0;

  scanf ("%d", &it);
  while (it-- > 0) {
    
    sign = 0;

    scanf (" %c", &op);
    scanf (" %ld %ld %ld %ld", &a.up, &a.down, &b.up, &b.down);

    if (a.down == 0 || b.down == 0) {
      printf ("error\n");
      continue;
    }

    if (op == '/' && (b.up == 0 || a.down == 0)) {
      printf ("error\n");
      continue;
    }
    
    if (a.up < 0 && a.down < 0) {
      a.up   = -a.up;
      a.down = -a.down;
    }
    
    if (b.up < 0 && b.down < 0) {
      b.up   = -b.up;
      b.down = -b.down;
    }

    switch (op) {
      
      case '+':
        result.up   = (a.up * b.down) + (b.up * a.down);
        result.down = (a.down * b.down);
        break;

      case '-':
        result.up = (a.up * b.down) - (b.up * a.down);
        result.down = (a.down * b.down);
        break;

      case '*':
        result.up   = (a.up * b.up);
        result.down = (a.down * b.down);
        break;

      case '/':
        result.up   = (a.up * b.down);
        result.down = (a.down * b.up);
        break;
    }
    
    if (result.up == 0) {
      printf ("0 0 1\n");
      continue;
    }
  
    if ((result.up > 0 && result.down < 0) || (result.up < 0 && result.down > 0))
      printf ("-");

    gcd_var = gcd (abs (result.up), abs (result.down));
    aker    = abs (result.up / result.down);
    arith   = abs ((result.up / gcd_var));
    paron   = abs ((result.down / gcd_var));
    arith   = abs (arith - (aker * paron));

    printf ("%ld %ld %ld\n", aker, arith, paron);
  }
  
  return 0;
}

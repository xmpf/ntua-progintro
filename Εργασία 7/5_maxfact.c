#include <stdio.h>

int factorial (int n)
{
  int f = 1;
  while (n > 1) {
    f = f * n;
    n -= 1;
  }
  
  return f;
}

int main ()
{
  int n;
  int i;

  scanf ("%d", &n);

  for (i = 1; factorial (i) < n; ++i) {}
  
  if (factorial (i) > n) { i -= 1; }
  printf ("%d\n", i);

  return 0;
}

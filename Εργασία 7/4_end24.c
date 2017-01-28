#include <stdio.h>

int main ()
{
  int n;
  int nSqr;
  
  scanf ("%d", &n);
  
  nSqr = n * n;

  if (nSqr % 100 == 24)
    printf ("yes\n");
  else
    printf ("no\n");

  return 0;
}

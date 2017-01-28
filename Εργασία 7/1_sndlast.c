#include <stdio.h>

int main ()
{
  unsigned long int num;
  scanf ("%ul", &num);
  printf ("%d\n", ((num / 10) % 10));
  return 0;
}

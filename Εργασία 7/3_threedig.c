#include <stdio.h>

int main ()
{
  int num;
  scanf ("%d", &num);

  if (num >= 100 && num <= 999)
    printf ("yes\n");
  else
    printf ("no\n");

  return 0;
}

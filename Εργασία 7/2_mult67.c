#include <stdio.h>

int main ()
{
  int num;
  scanf ("%d", &num);
  
  if (num == 0) {
    printf ("no\n");
    return 0;
  }

  if (num % 6 != 0 && num % 7 == 0)
    printf ("yes\n");
  else
    printf ("no\n");

  return 0;
}

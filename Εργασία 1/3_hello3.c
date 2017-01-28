#include <stdio.h>

/** function prototypes **/
void hello ();

int main ()
{
  int i;
  for (i = 1; i <= 20; i++) {
    hello ();
  }
}

void hello ()
{
  printf ("hello world\n");
}

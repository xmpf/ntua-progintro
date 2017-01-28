#include <stdio.h>

/** function prototypes **/
void hello ();

int main ()
{
  hello ();
  hello ();
  hello ();
  hello ();
  return 0;
}

void hello ()
{
  printf ("hello world\n");
}

#include <stdio.h>

/** global variables **/
const int n = 20;
int i;

/** function prototypes **/
void num_hello ();

int main ()
{
  for (i = 1; i <= n; i++) {
    num_hello ();
  }
  return 0;
}

void num_hello ()
{
  printf ("%d hello world\n", i);
}

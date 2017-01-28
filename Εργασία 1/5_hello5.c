#include <stdio.h>

void hello ()
{
  printf ("hello world\n");
}

int main ()
{
 int i, n;
 scanf  ("%d", &n);

 if (n <= 0)
   printf ("nothing today\n");

 for (i = 1; i <= n; i++) {
   hello ();
 }
 
 return 0; 
}

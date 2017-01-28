#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{

  int N;
  int i,j;
  long int sum;
  long int *a;

  scanf ("%d", &N);
  a = (long int *)malloc((N + 1) * sizeof (long int));
  for (i = 1; i <= N; i++)
    scanf ("%ld", &a[i]);
  
  a[0] = 2<<12;  
  i = 1;
  j = N;
  while ( i < j ) {
    sum = a[i] + a[j];
    if (abs (a[0]) > abs (sum))
      a[0] = sum;
    
    if (sum == 0)
      break;
    else if (sum > 0)
      j -= 1;
    else
      i += 1;
  }

  printf ("%ld\n", a[0]);
  
  free (a);
  a = NULL;

  return 0;
}

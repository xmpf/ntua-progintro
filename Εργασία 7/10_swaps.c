#include <stdio.h>
#include <stdlib.h>

int main ()
{
  int N;
  int i = 0, k = 0;
  int first = 0, last = 0;
  int swaps = 0;
  int *A;

  scanf ("%d", &N);

  A = (int *)malloc (N * sizeof (int));
  

  for (i = 0; i < N; scanf ("%d", &A[i++]))
    ;
  
  for (i = 0; i < N; i++) {
    if (A[i] > 0)
      k += 1;
    else
      swaps += k;
  }
  
  for (i = 0; A[i] > 0; i++)
    ;
  
  first = A[i];
  
  for (i = N - 1; A[i] < 0; i--)
    ;

  last = A[i];

  printf ("%d\n", swaps);
  printf ("%d\n%d\n", first, last);

  free (A);
  A = NULL;

  return 0;
}

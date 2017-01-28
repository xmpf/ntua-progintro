#include <stdio.h>
#include <stdlib.h>

int main ()
{
  int N;
  int i,j;
  int *a;
  int sum = 0;

  scanf ("%d", &N);

  a = (int *)malloc ((N) * sizeof (int));
  if (a == NULL) {
    printf ("Error: Unable to allocate memory!\n");
    return -1;
  }

  for (i = 0; i < N; i++)
    scanf ("%d", &a[i]);

  for (i = N - 1; i >= 2; i--) {
    sum = 0;
    for (j = i - 1; j >= 1; j--) {
       sum += a[j]; 

      if (sum == a[i] + a[j - 1]) {
        printf ("%d\n", i + 1);
        goto EXIT;
      }

    }
  }
  printf ("0\n");
EXIT:
  free (a);
  a = NULL;

  return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main ()
{ 
  int N;
  int i;
  int *a;
  int sum;

  scanf ("%d", &N);
  a = (int *)malloc ((N + 1) * sizeof (int));
  if (a == NULL) {
    return -1;
  }
  
  a[0] = 0;
  sum = 0;
  for (i = 1; i <= N; i++) {
    scanf ("%d", &a[i]);
    sum += a[i];
    if (sum < 0) {
      sum = 0;
    }
    else
      if (a[0] < sum)
        a[0] = sum;

  }

  printf ("%d\n", a[0]);

  free (a);
  a = NULL;
  
  return 0;
}


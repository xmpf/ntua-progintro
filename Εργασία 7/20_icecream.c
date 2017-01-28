#include <stdio.h>
#include <stdlib.h>

int main ()
{
  int *a;
  int b;
  int n,k;
  int i,j;
  int max;

  scanf ("%d %d", &n, &k);
  a = (int *)malloc ((n + 1) * sizeof (int));

  for (i = 1; i <= n; i++) {
    scanf ("%d", &a[i]);
  }
  
  i = 0;
  j = 1;
  max = 0;
  b = 0;
  while (i < n && j <= n) {
    if (a[j] - a[i] <= 2*k) {
      b++;
      j++;
    }
    else {
      i++;
      if (max < b)
        max = b;
      b = j - i;
    }
    if (max < b)
      max = b;
  }

  printf ("%d\n", max);
  
  free (a);
  a = NULL;

  return 0;
}

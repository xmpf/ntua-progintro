#include <stdio.h>
#include <stdlib.h>

int main ()
{
  int i, j;
  int n, x;
  int *a;
  int total = 0;

  scanf ("%d %d", &n, &x);

  a = (int *)malloc(n * sizeof (int));
  if (a == NULL) {
    return -1;
  }
  
  for (i = 0; i < n; scanf ("%d", &a[i++]))
      ;

  for (i = 0; i < n - 1; i++) {
    
    if (a[i] >= x)
      continue;
    else {
      j = i;
      while (++j < n) {
        if (a[j] >= x)
          continue;
        else if (a[i] + a[j] == x)
          total += 1;
      }
    }
  }

  printf ("%d\n", total);

  free (a);
  a = NULL;

  return 0;
}

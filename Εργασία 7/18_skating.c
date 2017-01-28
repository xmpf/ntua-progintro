#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main ()
{
  int n;
  int max;
  int i;
  int *slope;
  int *sum;
  
  scanf ("%d", &n);
  
  slope = (int *)malloc (n * sizeof (int));
  if (slope == NULL) {
    fprintf (stderr, "Error: Unable to allocate requested memory for [a].\n");
    return -1;
  }
  sum = (int *)malloc (n * sizeof (int));
  if (sum == NULL) {
    free (slope);
    slope = NULL;
    fprintf (stderr, "Error: Unable to allocate requested memory for [sum].\n");
    return -1;
  }

  memset (sum, 0, sizeof(sum));
  for (i = 0; i < n; i++) {
    scanf ("%d", &slope[i]);
  }
  
  sum[n - 1] = slope[n - 1];
  max = 0;
  for (i = n - 2; i >= 0; i--) {
    sum[i] = slope[i] + sum[i + 1];

    if (max < sum[i]) { max = sum[i]; }
  }
  
  printf ("%d\n", max);

  free (slope);
  slope = NULL;

  free (sum);
  sum = NULL;

  return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef long long int big;

int main ()
{
  big N;
  big sumi = 0,sumj = 0, max = 0,i,j;
  big *a;
  
  scanf ("%lld", &N);
  a = (big *)malloc ((N + 1) * sizeof (big));
  if (a == NULL) {
    printf ("Error: Unable to allocate requested memory!\n");
    return -1;
  }

  for (i = 1; i <= N; i++)
    scanf ("%lld", &a[i]);
  
  sumi = a[1];
  sumj = a[N];
  for (i = 1; i < N;) {
    for (j = N; j > i;) {
      if (sumi < sumj) {
        i += 1;
        sumi += a[i];
      }
      else {
        j -= 1;
        sumj += a[j];
      }

      if (sumi == sumj) {
        if (max < sumi) {
          max = sumi;
        }
      }
    }
    if (i >= j)
      break;
  }  
  printf ("%lld\n", max);

  free (a);
  a = NULL;

  return 0;
}

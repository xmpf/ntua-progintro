#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT2 30
#define LIMIT3 20
#define LIMIT5 10

int main ()
{
  long long N = 0;
  long long total = 0;
  long long p = 0;

  int i,j,k;

  long long pow2[LIMIT2];
  long long pow3[LIMIT3];
  long long pow5[LIMIT5];
  
  int *t_total;

  scanf ("%lld", &N);
  
  t_total = (int *)calloc(N + 1, sizeof(int));
  memset (t_total, 0, (N + 1) * sizeof(int));

  for (i = LIMIT2 - 1; i >= 0; i--) {
    pow2[i] = pow (2, i);
    if (i < LIMIT3) {
      pow3[i] = pow (3, i);
      if (i < LIMIT5)
        pow5[i] = pow (5, i);
    }
  }
  

  for (i = 0; i < LIMIT2; i++) {
    for (j = 0; j < LIMIT3; j++) {
      for (k = 0; k < LIMIT5; k++) {
        
        p = pow2[i] + pow3[j] + pow5[k];
        
        if (p <= N) {
          t_total[p] = 1;
//          printf ("%9lld::\t2:%d\t3:%d\t5:%d\n", p, i, j, k);
        }
        else
          break;

      }
    }
  }
  
  for (i = 1; i <= N; i++)
    if (t_total[i])
      total += 1;

  printf ("%lld\n", total);

  free (t_total);
  t_total = NULL;

  return 0;
}

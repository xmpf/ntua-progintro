#include <stdio.h>
#include <stdlib.h>

int main ()
{
  int *table;
  unsigned int N;
  unsigned int i, j;
  unsigned int *multiples;
  unsigned int total = 0;

  scanf ("%d", &N);
  
  table = (int *)malloc ((N + 1) * sizeof (int));
  multiples = (unsigned int *)malloc((N + 1) * sizeof (unsigned int));

  if (table == NULL || multiples == NULL) {
    printf ("Error: Unable to allocate memory\n");
    return -1;
  }

  table[0] = table[1] = 0;
  for (i = 2; i <= N; i++) {
    multiples[i] = 0;
    if (N % i == 0) {
      table[i] = 1;
    }
    else
      table[i] = 0;
  }

  for (i = 2; i <= N; i++) {
    if (table[i] == 1) {
      for (j = 1; i * j <= N; j++) {
        multiples[i * j] = i * j;
      }
    }
    if (multiples[i])
      total += 1;
  }
  
  printf ("%u\n", total);

  free (table);
  table = NULL;
  
  free (multiples);
  multiples = NULL;

  return 0;
}

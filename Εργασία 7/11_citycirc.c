#include <stdio.h>
#include <stdlib.h>

int main ()
{
  int N;
  int *town;
  int sum;
  int i, j;

  scanf ("%d", &N);

  town = (int *)malloc ((N + 1) * sizeof (int));
  
  sum = 0;
  for (i = 1; i <= N; i++) {
    scanf ("%d", &town[i]);
    sum += town[i];
  }
  
  if (sum < 0)
    printf ("0\n");
  else {
    for (i = 1; i <= N; i++) {
      sum = town[i];
      for (j = i + 1; j != i && sum >= 0; j++) {
        sum += town[j];
        if (j == N)
          j = 1;
      }

      if (i == j)
        break;
    }
    printf ("%d\n", i);
  }

  free (town);
  town = NULL;

  return 0;
}

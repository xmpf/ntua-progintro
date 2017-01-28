#include <stdio.h>
#include <stdlib.h>

int main ()
{
  int N;
  
  int i;
  int j;

  int *array;
  
  int max = 0;
  int odd;
  int even;

  scanf ("%d", &N);

  array = (int *)malloc (N * sizeof (int));
  if (array == NULL) {
    printf ("Error: Unable to allocate memory!\n");
    return -1;
  }

  for (i = 0; i < N; i++)
    scanf ("%d", &array[i]);

  for (i = 0; i < N; i++) {
    
    odd = 0;
    even = 0;

    for (j = i; j < N; j++) {

      if (array[j] & 1)
        odd += 1;
      else
        even += 1;

    if (odd == even) {
     if (max + i < (j + 1))
       max = j - i + 1;
    }

    }
  }
  
  printf ("%d\n", max);

  free (array);
  array = NULL;

  return 0;
}

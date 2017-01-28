#include <stdio.h>
#include <stdlib.h>

int main ()
{
  int N;
  int i;
  int *num;
  int a, b;
  int x, y;
  
  scanf ("%d", &N);
  num = (int *)malloc (N * sizeof (int));

  for (i = 0; i < N; i++)
    scanf ("%d", &num[i]);
  
  a = 0;
  b = 1;
  for (i = 2; i < N; i++) {
    x = num[i] + i - (num[b] + b);
    y = num[i] + i - (num[a] + 2*b) + a;

    if (x > 0 || y > 0) {
      if (x > y)
        b = i;
      else {
        a = b;
        b = i;
      }
    }

  }
  
  printf ("%d\n", num[a] + num[b] + (b - a));

  free (num);
  num = NULL;

  return 0;
}

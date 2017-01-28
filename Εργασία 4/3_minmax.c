#include <stdio.h>

int main ()
{
  int N, M;
  int i, j;
  
  int array[100][100];
  int columns[100];
  int rows[100];
  
  int maxc;
  int minr;

  scanf ("%d %d", &N, &M);
  for (i = 0; i < N; i++) {
    for (j = 0; j < M; j++) {
      scanf ("%d", &array[i][j]);
    }
  }
  
  for (j = 0; j < M; j++) {
    maxc = array[0][j];
    for (i = 0; i < N; i++) {
      if (maxc < array[i][j])
        maxc = array[i][j];
    }
    columns[j] = maxc;
  }

  for (i = 0; i < N; i++) {
    minr = array[i][0];
    for (j = 0; j < M; j++) {
      if (minr > array[i][j])
        minr = array[i][j];
    }
    rows[i] = minr;
  }
  
  maxc = columns[0];
  for (i = 0; i < M; i++) {
    if (maxc > columns[i])
      maxc = columns[i];
  }
  printf ("%d\n", maxc);

  minr = rows[0];
  for (i = 0; i < N; i++)
    if (minr < rows[i])
      minr = rows[i];
  printf ("%d\n", minr);

  return 0;

}

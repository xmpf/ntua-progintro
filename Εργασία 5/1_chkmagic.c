#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FORMAT "%ld"

typedef long int m_int;

void check_malloc (void *address)
{
  if (address == NULL) {
    fprintf (stderr, "Error: Unable to allocate memory!\n");
    exit (EXIT_FAILURE);
  }
}

int main ()
{
  int N;
  int i,j;
  
  m_int sum1 = 0;
  m_int sum2 = 0;

  m_int *rowSum;
  m_int *colSum;

  m_int *freq; //frequencies of numbers from 0 to N^2 - 1;
  m_int **arr; //store input data;

  //Get sizeof table;
  scanf ("%d", &N);

  freq = (m_int *)malloc ((N * N) * sizeof (m_int));
  if (freq == NULL) {
    fprintf (stderr, "Error: Unable to allocate memory!\n");
    return - 1;
  }

  //Initialize freq's elements to 0's
  memset (freq, 0, sizeof (freq));
  
  //Allocate a '2D' array.
  arr = (m_int **)malloc (N * sizeof (m_int *));
  if (arr == NULL) {
    fprintf (stderr, "Error: Unable to allocate memory!\n");
    return - 1;
  }
  for (i = 0; i < N; i++) {
    arr[i] = (m_int *)malloc (N * sizeof (int));
    if (arr[i] == NULL) {
      fprintf (stderr, "Error: Unable to allocate memory!\n");
      return -1;
    }
  }
  
  rowSum = (m_int *)malloc (N * sizeof (m_int));
  //check if memory allocated smoothly;
  check_malloc (rowSum);

  colSum = (m_int *)malloc (N * sizeof (m_int));
  //same check;
  check_malloc (colSum);

  // Parsing table data;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      scanf (FORMAT, &arr[i][j]);
      freq[arr[i][j]] += 1;
      
      //main diagonal;
      if (i == j)
        sum1 += arr[i][j];

      //secondary diagonal;
      if (i + j == N - 1)
        sum2 += arr[i][j];
    }
  }
  
  for (i = 0; i < (N * N); i++) {
    //if it does not contain all numbers from 0..(N^2-1) return;
    if (freq[i] != 1) {
      printf ("no\n");
      goto error;
    }
  }

  // sum1: main diagonal
  // sum2: secondary diagonal
  if (sum1 == sum2) {
    //Diagonals are equal;
    //Let's check for the sum of rows and columns;
    
    //Computing summations;
    for (i = 0; i < N; i++) {
      rowSum[i] = 0;
      colSum[i] = 0;
      for (j = 0; j < N; j++) {
        //sum of each row
        rowSum[i] += arr[i][j];
        //sum of each column
        colSum[i] += arr[j][i];  
      }
    }

    for (i = 0; i < N; i++) {
      if ((rowSum[i] != sum1) || (colSum[i] != sum1)) {
        //if current row sum != current column sum exit;
        printf ("no\n");
        goto error;
      }
    }
    //table parsed is a magic square;
    printf ("yes\n");
  }
  else  
    printf ("no\n");

error:  
  //memory de-allocation;
  free (freq);
  freq = NULL;

  for (i = 0; i < N; i++)
    free (arr[i]);
  free (arr);
  arr = NULL;
  
  free (rowSum);
  rowSum = NULL;

  free (colSum);
  colSum = NULL;
  
  return 0;
}

#include <stdio.h>

#define TT "%lf"

typedef double DT;

int main ()
{
  unsigned int N, M; //DIASTASEIS N:ROWS, M:COLUMNS
  unsigned int i, j; //METRITES

  DT avg[100][100]; //PINAKAS STOIXEIWN
  DT mor[100]; //PINAKAS STILI MESON ORWN KATHE GRAMMHS
  DT moc[100]; //PINAKAS GRAMMI MESWN ORWN KATHE STILIS

  DT sumr = 0; //ATHROISMA STOIXEIWN KATHE GRAMMHS
  DT sumc = 0; //ATHROISMA STOIXEIWN KATHE STHLHS
  
  scanf ("%u %u", &N, &M);

  //DIAVASMA PINAKA APO STDIN
  for (i = 0; i < N; i++)
    for (j = 0; j < M; j++)
      scanf (TT, &avg[i][j]);

  //EVRESH MESWN ORWN KATHE GRAMMHS
  for (i = 0; i < N; i++) {
    sumc = 0;
    for (j = 0; j < M; j++)
      sumc += avg[i][j];

    mor[i] = (sumc / M);
  }

  //EVRESH MESWN ORWN KATHE STHLHS
  for (j = 0; j < M; j++) {
    sumr = 0;
    for (i = 0; i < N; i++)
      sumr += avg[i][j];

    moc[j] = (sumr / N);
  }

  //EVRESH MESOY OROU APO MESOUS OROUS GRAMMWN
  sumr = 0;
  for (i = 0; i < N; i++) {
    sumr += mor[i];
  }
  sumr = sumr / N;

  //EVRESH MESOU OROU APO MESOUS OROUS STHLWN
  sumc = 0;
  for (i = 0; i < M; i++) {
    sumc += moc[i];
  }
  sumc = sumc / M;
  
  printf ("%.3lf\n", sumr);
  printf ("%.3lf\n", sumc);
  
  return 0;
}

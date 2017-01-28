#include <stdio.h>

int main ()
{
  long long int N, M;
  scanf ("%lld %lld", &N, &M);

  printf ("%lld\n", (N > M) ? N : M);

  return 0;
}

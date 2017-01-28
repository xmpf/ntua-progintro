#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
  long long *primes;
  long long p;
  long long f;
  long long N;

  scanf ("%lld", &N);

  primes = (long long *)malloc ((N + 1)  * sizeof (long long));
  if (primes == NULL) {
    printf ("Error: Unable to allocate memory!\n");
    return -1;
  }

  primes[0] = primes[1] = 0;
  for (f = 2; f <= N; f++)
    primes[f] = 1;

  p = 2;
  while (p * p <= N) {
    for (f = p; f <= N/p; f += 1) {
      primes[f * p] = 0;
    }
    do {
      p += 1;
    } while (primes[p] != 1);
  }

  f = 0;
  for (p = 2; p <= N; p++) {
    if (primes[p])
      f += 1;
  }

  printf ("%lld\n", f);

  free (primes);
  primes = NULL;

  return 0;
}

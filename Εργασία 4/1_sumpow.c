#include <stdio.h>
#include <math.h>
#include <stdint.h>

// User-defined data-types
typedef uint_fast64_t uint_big;

// Global Variables
uint_big digits[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void powDigits (int Power)
{
  int it;
  for (it = 2; it < 10; it++) {
    digits[it] = pow (digits[it], Power);
  }

}

// Main Function
int main ()
{

  int N;

  uint_big sum  = 0;
  uint_big num  = 0;
  
  int q, w, e, r, t, y, u, i;

  // Read power from stdin
  scanf ("%d", &N);
  powDigits (N);

  for (q = 0; q <= 9; q++)
    for (w = 0; w <= 9; w++)
      for (e = 0; e <= 9; e++)
        for (r = 0; r <= 9; r++)
          for (t = 0; t <= 9; t++)
            for (y = 0; y <= 9; y++)
              for (u = 0; u <= 9; u++)
                for (i = 0; i <= 9; i++) {
                  num = (q * 10000000) + (w * 1000000) + (e * 100000) +\
                        (r * 10000) + (t * 1000) + (y * 100) + (u * 10) + i;
                  
                  sum = digits[q] + digits[w] + digits[e] + digits[r] + digits [t] +\
                        digits[y] + digits[u] + digits[i];

                  if (num == sum)
                    printf ("%llu\n", num);
                  else
                    continue;
                }

  return 0;
}

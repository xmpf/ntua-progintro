#include <stdio.h>

/** user defined data structures **/
typedef struct rational_number {
  
  int numerator;
  int denominator;

} rational_t;

int main ()
{
  
  rational_t fraction_a   = {0, 0};
  rational_t fraction_b   = {0, 0};
  rational_t fraction_sum = {0, 0};

  scanf  ("%d %d", &fraction_a.numerator, &fraction_a.denominator);
  scanf  ("%d %d", &fraction_b.numerator, &fraction_b.denominator);

  fraction_sum.numerator   = (fraction_a.numerator * fraction_b.denominator) + (fraction_b.numerator * fraction_a.denominator);
  fraction_sum.denominator = (fraction_a.denominator * fraction_b.denominator);

  printf ("%d %d\n", fraction_sum.numerator, fraction_sum.denominator);

  return 0;
}

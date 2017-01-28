#include <stdio.h>
#include <stdlib.h>

enum boolean_t {
  false,
  true
};

int main ()
{
  enum boolean_t yes = false;

  long long *array;
  long long N;
  long long min;
  long long d;
  long long f;

  int i;
  int j;

  scanf ("%lld", &N);
  array = (long long *)calloc (N, sizeof (long long));
  if (array == NULL) {
    fprintf (stderr, "Error: Unable to allocate memory!\n");
    return -1;
  }

  for (i = 0; i < N; i++) {
    scanf ("%lld", &array[i]);
  }
  
  min = array[0];
  i = N;
  while (--i > 0) {
    yes = false;

    for (j = 0; j < i; j++) {

      d = array[i];
      f = array[j];
      /*
      while (f > 0)
        f -= d;
      */
      if (f % d == 0) {
        yes = true;
      }
      else {
        yes = false;
        break;
      }
    }

    if (yes && min > d) {
      min = d;
      break;
    }
  }
    
  printf ("%lld\n", min);
  
  free (array);
  array = NULL;

  return 0;
}

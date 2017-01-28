#include <stdio.h>

enum boolean {
  false,
  true
};

int main ()
{
  char string[21];
  char c;
  int  len   = 0;
  int  times = 0;
  int  start = 0;
  int  end   = 0;
  int  i = 0;
  enum boolean palindrome = true;
  float pososto = 0.0;

  scanf ("%d\n", &times);
  for (i = 0; i < times; i++) {

    len = 0;
    while ((c = getchar ()) != '\n') {
      if (len < 20) string[len] = c;
      len++;
    }    

    if (len > 20) {
        printf ("error\n");
        continue;
     }
     else if (len == 0) {
        printf ("empty\n");
        continue;
    }
    else {
      string[len] = '\0';
      end = len;
      start = -1;
      palindrome = true;
      while (start++ < end--) {
        if (string[start] != string[end]) {
          palindrome = false;
          break;
        }
      }
    }
      if (palindrome) {
        printf ("yes\n");
        pososto += 1.0;
      }
      else
        printf ("no\n");
  }
  pososto = pososto / times * 100;
  printf ("%.3f\n", pososto);
  return 0;
}

#include <stdio.h>
#include <string.h>

//const int MAX_INPUT = 2048;

int main ()
{
//  char str[MAX_INPUT]; //string to be encrypted;
  int cipher[26]; //ciphertext;
  int c; //parse input using getchar ();
  int i; //general index;
  int exactly_once[26];

  //initialize ciphertext;
  memset (cipher, 0, sizeof (cipher));
  
  //initialize exactly_once;
  memset (exactly_once, 0, sizeof(exactly_once));

  i = 0;
  while ((c = getchar ()) != '\n' && i < 26) {
    
    if (c < 'a' || c > 'z') {
      break;
    }
    
    cipher[i++] = c;
    exactly_once[c - 'a'] += 1;
  }
  
  for (i = 0; i < 26; i++) {
    if (exactly_once[i] != 1) {
      printf ("error\n");
      return 0;
    }
  }
  
//  i = 0;
  while ((c = getchar ()) != EOF /*&& i < MAX_INPUT - 1*/) {
    if (c >= 'a' && c <= 'z') {
      /*str[i] = */ putchar (cipher[c - 'a']);
    }
    else if (c >= 'A' && c <= 'Z') {
      /*str[i] = */putchar (cipher[c - 'A'] - 32);
    }
    else
      /*str[i] = */putchar (c);

//    i += 1;
  }
//  str[i] = '\0';
//  printf ("%s", str);

  return 0;
}

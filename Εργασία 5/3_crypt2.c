#include <stdio.h>
#include <string.h>

int main ()
{
  int cipher[26]; //ciphertext;
  int c; //parse input using getchar ();
  int i; //general index;
  int exactly_once[26];
  char command; // (en|de)-crypt
  int decipher[26];

  //initialize ciphertext;
  memset (cipher, 0, sizeof (cipher));

  //initialize exactly_once;
  memset (exactly_once, 0, sizeof(exactly_once));

  i = 0;
  while ((c = getchar ()) != '\n' && i < 26) {

    if (c < 'a' || c > 'z') {
      break;
    }

    cipher[i] = c;
    exactly_once[c - 'a'] += 1;
    decipher[c - 'a'] = 'a' + i;
    i += 1;
  }

  for (i = 0; i < 26; i++) {
    if (exactly_once[i] != 1) {
      printf ("error\n");
      return 0;
    }
  }

  command = getchar ();
  while ((c = getchar ()) != EOF && c != '\n')
    ;

  if (command == 'd') { //Decrypt routine;

    while ((c = getchar ()) != EOF) {

      if (c >= 'a' && c <= 'z') {
        putchar (decipher[c - 'a']);
      }
      else if (c >= 'A' && c <= 'Z') {
        putchar (decipher[c - 'A'] - 32);
      }
      else
        putchar (c);

    }

  }
  else { //Encrypt routine;
    while ((c = getchar ()) != EOF) {
      if (c >= 'a' && c <= 'z') {
        putchar (cipher[c - 'a']);
      }
      else if (c >= 'A' && c <= 'Z') {
        putchar (cipher[c - 'A'] - 32);
      }
      else
        putchar (c);
    }
  }

  return 0;
}


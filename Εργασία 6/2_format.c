#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_LINE = 60;
const int MAX_WORD = 20;

int main ()
{
  char line[MAX_LINE + 1];
  char word[MAX_WORD + 1];

  int counter = 0; // Total number of words in each line.
  int spaces  = 0; // Number of spaces to fill.
  int length  = 0; // Length of current word.
  int total = 0; // Total spaces between each word: (spaces / counter);
  int i = 0; // General index variable;
  int j = 0;
  int blanks = 0;
  int modBlanks = 0;
  int runner = 0;

  scanf ("%s", word); // Read first word, discard whitespace.
  while (word[i] != '\0') { line[i] = word[i]; i+= 1; }
  counter = 1;

  // Using scanf, to read whole words from input stream.
  while (scanf ("%s", word) != EOF) {
    // strlen: Returns number of bytes excluding null '\0'.
    length = strlen (word);
    if (i + length < MAX_LINE) {
      line[i++] = ' '; // Process next word.
      counter += 1;
      j = 0;
      // Process next word.
      while (word[j] != '\0') {
        // Append the next word, in a way that won't
        // overwrite previous characters in the array.
        line[i++] = word[j++];
      } // End of while.
    } // End of if.
    else { // i + length > MAX_LINE.
      blanks = counter - 1; // Number of total words -1;
      //spaces = MAX_LINE - i + blanks;
      spaces = MAX_LINE - i;

      // Iterate through line to add extra spaces. Justify.

      modBlanks = spaces % blanks;
      total = spaces / blanks;
      spaces -= modBlanks;
      for (j = 0; j < i; j++) {
        runner = total;
        if (line[j] == ' ') {
          do {
            putchar (' ');
          } while (runner-- > 0);

          if (modBlanks >= counter - 1)
           putchar (' ');

          counter -= 1;    // Total words decreased by 1.
        }
        else { putchar (line[j]); }
      }
      putchar ('\n'); // Print the new line.

      // Initialization of variables.
      counter = 1;
      total   = 1;
      i = 0;
      j = 0;
      // As we are in a new line.

      while (word[j] != '\0') { line[i++] = word[j++]; }

    } // End of else

  } // End of while;

  for (j = 0; j < i; j++) { putchar (line[j]); }
    putchar ('\n');

  return (0);
}


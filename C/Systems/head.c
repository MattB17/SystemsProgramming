// simple version of a Linux command line program called head
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFSIZE 256

/* This program takes two command line arguments: a number NUM and a
 * filename FILE. It prints NUM lines from the file FILE.
 * This version has no error checking.
*/

int main(int argc, char **argv) {
  FILE *fp;
  char buf[BUFSIZE];
  int i;

  if (argc != 3) {
    fprintf(stderr, "usage: %s NUM FILE\n", argv[0]);
    exit(1);
  }

  char * endptr;
  long numlines = strtol(argv[1], &endptr, 0);

  if (endptr[0] != '\0') {
    fprintf(stderr, "ERROR: number of lines contained non-numeric characters.\n");
    exit(1);
  }

  // error for cant fit in long (number too large)
  if (errno == ERANGE && numlines == LONG_MAX) {
    perror(argv[1]);
    exit(1);
  }

  if (numlines <= 0) {
    fprintf(stderr, "ERROR: number of lines should be positive.\n");
    exit(1);
  }

  if ((fp = fopen(argv[2], "r")) == NULL) {
    perror(argv[2]);
    exit(1);
  }

  for (i = 0; i < numlines; i++) {
    // check for if numlines is more than the number of lines
    // in the file
    if ((fgets(buf, BUFSIZE, fp)) == NULL) {
      fprintf(stderr, "ERROR: not enough lines in the file.\n");
      exit(1);
    }
    printf("%s", buf);
  }

  return 0;
}

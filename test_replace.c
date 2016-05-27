#include <stdio.h>
#include <stdlib.h>
#include "rtf_replace.h"

#define PROGNAME "rtf_replace"

int main(int argc, char *argv[]) {
  FILE *fp_in;
  int retval = EXIT_SUCCESS;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <inputfile>\n", PROGNAME);
    fprintf(stderr, "%s will process <inputfile>, replacing items as configured.\n", \
	    PROGNAME);
    fprintf(stderr, "All output will be sent to stdout.\n\n");
    exit(EXIT_FAILURE);
  }

  fp_in = fopen(argv[1], "rb");

  if (fp_in == NULL) {
    fprintf(stderr, "ERROR: Could not open file \'%s\'\n\n", argv[1]);
    fprintf(stderr, "Usage: %s <inputfile>\n", PROGNAME);
    fprintf(stderr, "%s will process <inputfile>, replacing items as configured.\n", \
	    PROGNAME);
    fprintf(stderr, "All output will be sent to stdout.\n\n");
    exit(EXIT_FAILURE);
  }


  retval = rtf_replace(fp_in, stdout, "CALLME", "MAYBE");

  fclose(fp_in);
  
  return retval;
}

#include <time.h>
#include "readlines.h"
#define MAXLINES 5000
#include <stdio.h>

int main () {
  char *lineptr[MAXLINES];
  float startTime = (float)clock()/CLOCKS_PER_SEC;
  readlines(lineptr, MAXLINES);
  float endTime = (float)clock()/CLOCKS_PER_SEC;
  float timeElapsed = endTime - startTime;
  printf("It took: %lf\n", timeElapsed);
  return 0;
}
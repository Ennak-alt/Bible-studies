#include <time.h>
#include "readlines.h"
#define MAXLINES 5000
#define MAXLINE 100000
#include <stdio.h>

int main () {
  char *lineptr[MAXLINES];
  char line[MAXLINE];
  float startTime = (float)clock()/CLOCKS_PER_SEC;
  readlines2(lineptr, line, MAXLINES);
  float endTime = (float)clock()/CLOCKS_PER_SEC;
  float timeElapsed = endTime - startTime;
  printf("It took: %lf\n", timeElapsed);
  return 0;
}
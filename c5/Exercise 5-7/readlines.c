#define MAXLEN 1000
#include "alloc.h"
#include "getline.h"
#include <stdio.h>
#include <string.h>

int readlines(char *lineptr[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while((len = getlinev2(line, MAXLEN)) > 0)
    if (nlines >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else {
      line[len-1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  return nlines;
}

int readlines2(char *lineptr[], char *linstr, int maxlines) {
  int len, nlines;
  char line[MAXLEN];

  nlines = 0;
  while((len = getlinev2(line, MAXLEN)) > 0)
    if (nlines >= maxlines)
      return -1;
    else {
      line[len-1] = '\0';
      strcpy(linstr, line);
      lineptr[nlines++] = linstr;
      linstr += len;
    }
    return nlines;
}
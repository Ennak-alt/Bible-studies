#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "io.h"
#define MAXLINES 5000
char *lineptr[MAXLINES];

void qsort_(void *lineptr[], int left, int right, int reverse, 
          int (*comp)(void *, void *));
int numcmp(char *, char *);
int strcmp_(char *, char *);
int strcmp_ignorecase(char *, char *);

/* sort input lines */
int main(int argc, char *argv[]) {
  int nlines;
  int numeric = 0;
  int fold = 0;
  int reverse = 1;

  while (--argc > 0) {
    int sl = strlen(*++argv);
    if (sl == 2 && *(*argv) == '-')
      switch(*(*argv+1)) {
        case 'n':
          numeric = 1;
          break;
        case 'r':
          reverse = -1;
          break;
        case 'f':
          fold = 1;
          break;
      }
  }
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    qsort_((void **) lineptr, 0, nlines-1, reverse,
      (int (*)(void*,void*))(numeric ? numcmp : (fold ? strcmp_ignorecase : strcmp_)));
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("input too big to sort\n");
    return 1;
  }

  return 0;
}

void qsort_(void *v[], int left, int right, int reverse,
           int (*comp)(void *, void *))
{
  int i, last;
  void swap(void *v[], int, int);
  if (left >= right)
    return;
  swap(v, left, (left + right)/2);
  last = left;
  for (i = left+1; i <= right; i++)
    if (reverse*(*comp)(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort_(v, left, last-1, reverse, comp);
  qsort_(v, last+1, right, reverse, comp);
}

int strcmp_(char *s, char *t) {
  for ( ; *s == *t; s++, t++)
    if (*s == '\0')
      return 0;
  return *s - *t;
}

int strcmp_ignorecase(char *s, char *t) {
  for ( ; tolower(*s) == tolower(*t); s++, t++)
    if (*s == '\0')
      return 0;
  return tolower(*s) - tolower(*t);
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2) {
  double v1, v2;

  v1 = atof(s1);
  v2 = atof(s2);
  if (v1 < v2)
    return -1;
  else if (v1 > v2)
    return 1;
  else 
    return 0;
}

void swap(void *v[], int i, int j) {
  void *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
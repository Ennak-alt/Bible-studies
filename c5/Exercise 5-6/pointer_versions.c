#include <stdio.h>
#include <string.h>

void getlinePV(char *s) {
  while ((*s = getchar()) != EOF && *s++ != '\n');
  if (*s != EOF)
    s--; 
  *s = '\0';
}

void reversePV(char *s) {
  char *t = s + strlen(s) - 1;
  while (s < t) {
    char c = *s;
    *s++ = *t;
    *t-- = c;
  }
}
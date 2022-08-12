#include <ctype.h>
#include <stdio.h>

void strncpy_(char *s, char *t, int n) {
  while((*s++ = *t++) && n--)
    ;
  *--s = '\0';
}

void strncat_(char *s, char *t, int n) {
  while(*s++ != '\0')
    ;
  s--;
  while((*s++ = *t++) && n--)
    ;
  *--s = '\0';
}

int strncmp_(char *s, char *t, int n) {
  while(*s && *t && *s == *t && --n)
    s++, t++;
  return *s - *t;
}
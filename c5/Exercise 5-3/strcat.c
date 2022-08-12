#include <stdio.h>
void strcat_(char *s, char *t) {
  while (*++s != '\0')
    ;
  while ((*s++ = *t++))
    ;
  return;
}
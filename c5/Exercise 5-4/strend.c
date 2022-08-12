#include <string.h>

int strend(char *s, char *t) {
  int tlen = strlen(t);
  int slen = strlen(s);
  if (tlen > slen)
    return 0;
  s += strlen(s) - strlen(t);
  while (*s != '\0')
    if (*s++ != *t++)
      return 0;
  return 1;
}
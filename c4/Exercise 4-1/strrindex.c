#include <string.h>

int strrindex(char s[], char t[]) {
  int ls = strlen(s);
  int lt = strlen(t);
  for (int i = ls-lt; i >= 0; i--) {
    int j;
    for (j = 0; j < lt; j++)
      if (s[i+j] != t[j]) 
        break;
    if (j == lt) 
      return i;
  }
  return -1;
}
#include <stdio.h>
#include <string.h>  

void reverse(char s[]) {
    int i = 0;
    char cp[1000];
    while (s[i] != '\0') {
        cp[i] = s[i];
        ++i;
    }
    --i;
    for (int j = 0; i >= 0; ++j, --i) {
        s[j] = cp[i];
    }
}

void itoa(int n, char s[]) {
  int i, sign;

  if ((sign = n) < 0) 
    n = -n;
  i = 0;
  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

void newitoa(int n, char s[]) {
  int i, sign;
  char l;
  
  i = 0;

  if ((sign = n) < 0) {
    s[0] = (char)(-(n - (n/10)*10) + '0');
    i++;
    n = -(n / 10);
  }

  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);
  if (sign < 0) {
    s[i++] = '-';
  }
  s[++i] = '\0';
  reverse(s);
}

int main () {
  char s[1000];
  itoa(2123, s);
  printf("%s \n", s);

  itoa(-998213, s);
  printf("%s \n", s);

  itoa(1 << 31, s);
  printf("%s \n", s);

  newitoa(1 << 31, s);
  printf("%s \n", s);
}
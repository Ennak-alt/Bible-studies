#include <string.h>
#include <stdio.h>

void test(char testName[], char expected[], char ouput[]) {
  if (strcmp(expected, ouput) == 0) {
    printf("\033[0m%s: \033[0;32mSUCEEDED \n", testName);
  } else {
    printf("\033[0m%s: \033[0;31mFAILED \n", testName);
    printf("\033[0;31m   Expected: \"%s\" but got \"%s\" \n", expected, ouput);
  }
}

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

void itoa(int n, char s[], int w) {
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

  if (i < w) 
    for (; i < w; ++i)
      s[i] = '0';

  if (sign < 0)
    s[i++] = '-';

  s[i] = '\0';
  reverse(s);
}

// void itoa(int n, char s[], int w) {
//   int ns[1000];
//   itoa(n, ns);

//   int i = 0;
//   int l = strlen(ns);

//   if (l < w)
//     for (; i < l-w; i++)
//       s[i] = '0';

//   for (int j = 0; j < l; j++, i++) 
//     s[i] = ns[j];
  
//   s[i] = '\0';
// }

int main () {
  char s[1000];
  itoa(2123, s, 10);
  printf("%s \n", s);

  itoa(-998213, s, 10);
  printf("%s \n", s);

  itoa(1 << 31, s, 10);
  printf("%s \n", s);

  itoa(1 << 31, s, 10);
  printf("%s \n", s);
}
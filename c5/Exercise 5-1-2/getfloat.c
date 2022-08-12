#include <stdio.h>
#include <ctype.h>
#include "getnum.h"
#include "getch.h"

int getfloat(double *pn) {
  int c, sign;

  while (isspace(c = getch()))  /* skip white space */
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-') {
    c = getch();
    if (!isdigit(c)) {
      ungetch(c);
      return 0;
    }
  }
  for (*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');
  if (c == '.') {
    printf("YEA");
    c = getch();
    double temp = 0.0;
    for (int i = 10.0; isdigit(c); c = getch(), i *= 10.0) 
      temp += (double)(c - '0') / i;
    *pn += temp;
  }
  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}
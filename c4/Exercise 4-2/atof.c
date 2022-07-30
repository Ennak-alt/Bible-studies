#include <ctype.h>
#include <math.h>

double atof(char s[]) {
  double val, power;
  int i, sign;

  for (i = 0; isspace(s[i]); i++) 
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-') 
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }

  if (tolower(s[i++]) == 'e') {
    double exsign = s[i] == '-' ? i++, 0.1: 10;
    int exval = 0.0;
    for (;s[i] != '\0'; i++)
      exval = 10 * exval + (s[i] - '0');
    power /= powf(exsign, exval);
  }

  return sign * val / power;
}
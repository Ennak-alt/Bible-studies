#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP   100
#define NUMBER  '0'

#define TOP 't'
#define DUPLICATE 'd'
#define SWAP 's'
#define CLEAR 'c'

#define SIN 'S'
#define COS 'C'


int getop(char []);
void push(double);
double pop(void);
void clear(void);

int main() {
  int type;
  double op2, num, sndNum;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch(type) {
      case NUMBER:
        push(atof(s));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0)
          push(pop() / op2);
        else
          printf("error: zero divisor\n");
        break;
      case '%':
        op2 = pop();
        push(fmod(pop(), op2));
        break;
      case TOP: 
        num = pop();
        printf("Top: %f\n", num);
        push(num);
        break;
      case DUPLICATE:
        num = pop();
        push(num);
        push(num);
        break;
      case SWAP:
        num = pop();
        sndNum = pop();
        push(num);
        push(sndNum);
        break;
      case CLEAR:
        clear();
        break;
      case '\n':
        printf("\t%.8g\n", pop());
        break;
      default:
        printf("error: unknown command %s\n", s);
        break;
    }
  }
  return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
  if (sp < MAXVAL)
    val[sp++] = f;
  else 
    printf("error: stack full, can't push %g\n", f);
}

void clear(void) {
  for (;sp > 0; sp--)
    pop();
}

double pop(void) {
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[]) {
  int i, c;
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.') 
    return c;
  i = 0;
  if (isdigit(c))
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
  if (bufp >= BUFSIZE) 
    printf("ungetch: too many characters\n");
  else 
    buf[bufp++] = c;
}